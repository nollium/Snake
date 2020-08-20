/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frontend.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaccary <smaccary@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 00:50:27 by smaccary          #+#    #+#             */
/*   Updated: 2020/08/21 00:50:27 by smaccary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRONTEND_H
# define FRONTEND_H

# include "structs.h"

# define CELL_SIZE 12


void    my_pixel_put(t_data *data, int x, int y, int color);
void	draw_grid(t_data *data, int color);
void	fill_cell(t_data *data, int x, int y, int color);
void	copy_image(t_data *src, t_data *dst);

#endif