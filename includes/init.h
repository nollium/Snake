/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaccary <smaccary@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 01:01:31 by smaccary          #+#    #+#             */
/*   Updated: 2020/08/21 01:01:31 by smaccary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

# include "structs.h"
# include "main.h"

void    init_data(t_data *data, void *mlx, int w, int h);
void	init_display(t_game *game);

#endif