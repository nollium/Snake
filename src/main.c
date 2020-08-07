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
** YOU SHOULD ALWAYS SWITCH BETWEEN TWO IMAGE BUFFERS TO PREVENT TEARING
** (DOUBLE BUFFERING) 
*/

int		loop_handler(t_game *game)
{
	static clock_t	t0 = 0;

	if ((double)(clock() - t0) > (double)CLOCKS_PER_SEC / (double)FRAME_CAP)
	{
		mlx_put_image_to_window(game->mlx, game->win,
								game->img_ptr->mlx_img, 0, 0);
		if (game->img_ptr == game->img)
			game->img_ptr++;
		else
			game->img_ptr--;
		t0 = clock();
	}
	return (0);
}

/*
** FUNCTION TO TEST IF EVERYTHING IS WORKING WELL 
*/

void	draw_grid(t_data *data, int color)
{
	int	x;
	int	y;
	int	step = 50;
	
	y = 0;
	while (y < data->height)
	{
		x = -1;
		while (++x < data->width)
		{
			my_pixel_put(data, x, y, color);
			my_pixel_put(data, y, x, color);
		}
		y += step;
	}
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
}

int		main(void)
{
	t_game	game;

	init_display(&game);
	draw_grid(game.img, 0xFF0000);
	draw_grid(game.img + 1, 0xFF);
	mlx_loop_hook(game.mlx, loop_handler, (void *)&game);
	mlx_loop(game.mlx);
	return (0);
}