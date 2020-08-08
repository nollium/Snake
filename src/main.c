/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaccary <smaccary@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 15:53:41 by smaccary          #+#    #+#             */
/*   Updated: 2020/08/06 20:59:56 by smaccary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

/*
** THIS IS HOW YOU DRAW INSIDE AN MLX IMAGE 
*/

void    my_pixel_put(t_data *data, int x, int y, int color)
{
	char    *dst;

	if (x <= 0 || x >= data->width || y <= 0 || y >= data->height)
		return ;
	dst = data->addr + (y * data->line_length + x * data->bits_per_pixel / 8);
	*(unsigned int *)dst = color;
}

/*
** FUNCTION TO TEST IF EVERYTHING IS WORKING WELL 
*/

void	draw_grid(t_data *data, int color)
{
	int	x;
	int	y;
	
	y = 0;
	while (y < data->height)
	{
		x = -1;
		while (++x < data->width)
		{
			my_pixel_put(data, x, y, color);
			my_pixel_put(data, y, x, color);
		}
		y += CELL_SIZE;
	}
}

void	fill_cell(t_data *data, int x, int y, int color)
{
	int	start_x;
	int	start_y;
	
	x *= CELL_SIZE;
	y *= CELL_SIZE;
	start_x = x;
	start_y = y;
	while (y < start_y + CELL_SIZE)
	{
		while (x < start_x + CELL_SIZE)
		{
			my_pixel_put(data, x, y, color);
			x++;
		}
		y++;
		x = start_x;
	}
}

void	copy_image(t_data *src, t_data *dst)
{
	int	i;

	i = -1;
	while (++i < dst->width * dst->height * dst->bits_per_pixel / 8
			&& i < src->width * src->height * src->bits_per_pixel / 8)
		(dst->addr)[i] = (src->addr)[i];
}

int	get_random_int()
{
	srand(clock());
	return ((rand() ^ (rand() << 15) ^ ((long long int) rand() << 30)));
}

/*
** YOU SHOULD ALWAYS SWITCH BETWEEN TWO IMAGE BUFFERS TO PREVENT TEARING
** (DOUBLE BUFFERING) 
*/

void	*fill_next_cell_rcolor(t_game *game)
{
	static int		x = 0;
	static int		y = 0;
	static int		increment = 1;

	fill_cell(game->img_ptr, x, y, ((unsigned int)get_random_int()) % (unsigned int)0xFFFFFF);
	x += increment;
	if (x > W_WIDTH / CELL_SIZE || x < 0)
	{
		increment *= -1;
		x += increment;
		y++;
	}
	return (NULL);
}

void	*fill_next_cell_rcolor_r(t_game *game)
{
	static int		x = (W_WIDTH - 1) / CELL_SIZE;
	static int		y = (W_HEIGHT - 1) / CELL_SIZE;
	static int		increment = -1;

	fill_cell(game->img_ptr, x, y, ((unsigned int)get_random_int()) % (unsigned int)0xFFFFFF);
	x += increment;
	if (x > W_WIDTH / CELL_SIZE || x < 0)
	{
		increment *= -1;
		x += increment;
		y--;
	}
	return (NULL);
}

void	*refresh(t_game *game)
{
	static clock_t	t0 = 0;

	if (game->frame_ready && (!FRAME_CAP
	|| (double)(clock() - t0) > (double)CLOCKS_PER_SEC / (double)FRAME_CAP))
	{
		mlx_put_image_to_window(game->mlx, game->win,
								game->img_ptr->mlx_img, 0, 0);
		if (game->img_ptr == game->img)
		{
			copy_image(game->img, game->img + 1);
			game->img_ptr++;
		}
		else
		{
			copy_image(game->img + 1, game->img);
			game->img_ptr--;
		}
		t0 = clock();
		game->frame_ready = 0;
	}
	return (NULL);
}

int		loop_handler(t_game *game)
{
	pthread_t		threads[3];

	if (!game->frame_ready)
	{
		pthread_create(threads, NULL, (void *(*)(void *))fill_next_cell_rcolor, game);
		pthread_create(threads + 1, NULL, (void *(*)(void *))fill_next_cell_rcolor_r, game);
		pthread_join(threads[0], NULL);
		pthread_join(threads[1], NULL);
		game->frame_ready = 1;
	}
	refresh(game);
	return (0);
}

void    init_data(t_data *data, void *mlx, int w, int h)
{
	data->mlx_img = mlx_new_image(mlx, w, h);
	data->addr = mlx_get_data_addr(data->mlx_img, &(data->bits_per_pixel),
								 &(data->line_length), &(data->endian));
	data->width = w;
	data->height = h;
}

void	init_display(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, W_WIDTH, W_HEIGHT, W_TITLE);
	game->img_ptr = game->img;
	init_data(game->img, game->mlx, W_WIDTH, W_HEIGHT);
	init_data(game->img + 1, game->mlx, W_WIDTH, W_HEIGHT);
	game->frame_ready = 0;
}

void	clean_all(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_image(game->mlx, game->img->mlx_img);
	mlx_destroy_image(game->mlx, game->img[1].mlx_img);
}

int		leave(t_game *game)
{
	clean_all(game);
	exit(0);
}

int		key_handler(int keycode, t_game *game)
{
	if (keycode == ESC_KEY)
		leave(game);
	return (0);
}

int		main(void)
{
	t_game	game;
	
	init_display(&game);
	draw_grid(game.img, 0xFF0000);
	draw_grid(game.img + 1, 0xFF);
	mlx_loop_hook(game.mlx, loop_handler, (void *)&game);
	mlx_key_hook(game.win, key_handler, &game);
	mlx_hook(game.win, DESTROY_NOTIFY, STRUCTURE_NOTIFY_MASK, leave, &game);
	mlx_loop(game.mlx);
	return (0);
}