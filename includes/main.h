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

# include "mlx.h"
# include "x_events.h"
# include "keycodes.h"
# include <time.h>

# define W_WIDTH	800
# define W_HEIGHT	800
# define W_TITLE	"window title"

# define FRAME_CAP	1

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

typedef struct	s_game
{
	void		*mlx;
	void		*win;
	t_data  	img[2];
	t_data  	*img_ptr;
}				t_game;

#endif