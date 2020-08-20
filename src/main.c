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