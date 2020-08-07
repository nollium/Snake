/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaccary <smaccary@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 15:55:40 by smaccary          #+#    #+#             */
/*   Updated: 2020/08/06 20:37:13 by smaccary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

/*
** MLX HEADER
*/

# include "mlx.h"

/*
** X EVENTS ARE REWRITTEN ACCORDINGLY TO 42'S NORM IN THIS FILE
*/

# include "x_events.h"

/*
** IMPORTANT KEYBOARD KEYCODES FOR LINUX, OSX AND WINDOWS (MINGW)
** ARE REWRITTEN IN THIS FILE
*/

# include "keycodes.h"

# include <time.h>
# include <stdio.h>
# include <unistd.h>

# define W_WIDTH	800
# define W_HEIGHT	800
# define W_TITLE	"window title"

/*
** MAX FRAMES PER SECOND 
*/

# define FRAME_CAP	1

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
}				t_game;

#endif