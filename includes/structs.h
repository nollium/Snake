/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaccary <smaccary@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 00:49:13 by smaccary          #+#    #+#             */
/*   Updated: 2020/08/21 00:49:13 by smaccary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

/*
** STRUCT STORING ALL INFORMATION REQUIRED TO USE A MLX IMAGE 
*/

typedef struct	s_data
{
	void		*mlx_img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			height;
	int			width;
}				t_data;

/*
** MLX HOOKS ONLY TAKE ONE ARGUMENT SO YOU SHOULD STORE EVERYTHING YOU NEED
** IN A STRUCT 
*/

typedef struct	s_game
{
	void		*mlx;
	void		*win;
	t_data  	img[2];
	t_data  	*img_ptr;
	int			frame_ready;
}				t_game;


#endif