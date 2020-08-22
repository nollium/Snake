/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   snake.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaccary <smaccary@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 18:30:31 by smaccary          #+#    #+#             */
/*   Updated: 2020/08/22 18:30:31 by smaccary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "snake.h"

t_cell	*new_cell(int x, int y, int color)
{
	t_cell	*cell;

	cell = malloc(sizeof(t_cell));
	*cell = (t_cell){.x = x, .y = y, .color = color};
	return (cell);
}
