/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaccary <smaccary@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 00:52:46 by smaccary          #+#    #+#             */
/*   Updated: 2020/08/21 01:53:59 by smaccary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"
#include "structs.h"

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

t_cell	*new_cell(int x, int y, int color)
{
	t_cell	*cell;

	cell = malloc(sizeof(t_cell));
	*cell = (t_cell){.x = x, .y = y, .color = color};
	return (cell);
}

void    init_snake(t_snake *snake)
{
	snake->size = 1;
	snake->x = (W_WIDTH / CELL_SIZE) / 2;
	snake->y = (W_HEIGHT / CELL_SIZE) / 2;
	snake->dir_x = 1;
	snake->dir_y = 0;
	snake->cells_list =  ft_lstnew(new_cell(snake->x, snake->y, CELL_COLOR));
}