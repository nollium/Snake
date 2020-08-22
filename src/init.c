/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaccary <smaccary@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 00:52:46 by smaccary          #+#    #+#             */
/*   Updated: 2020/08/22 18:45:57 by smaccary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"
#include "structs.h"
#include "snake.h"

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

void    init_snake(t_snake *snake)
{
	snake->x = (W_WIDTH / CELL_SIZE) / 2;
	snake->y = (W_HEIGHT / CELL_SIZE) / 2;
	snake->dir_x = 1;
	snake->dir_y = 0;
	snake->cells_list = ft_lstnew(new_cell(snake->x, snake->y, CELL_COLOR));
	snake->cells_list->next = ft_lstnew(new_cell(snake->x - snake->dir_x, snake->y - snake->dir_y, 0xFF));
	snake->size = ft_lstsize(snake->cells_list);
}
