/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frontend.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaccary <smaccary@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 00:48:01 by smaccary          #+#    #+#             */
/*   Updated: 2020/08/21 00:48:01 by smaccary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include "frontend.h"

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