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
# include "structs.h"
# include "frontend.h"
# include "init.h"

# include <time.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>


# define W_WIDTH	800
# define W_HEIGHT	800
# define W_TITLE	"window title"

/*
** MAX FRAMES PER SECOND 
*/

# define FRAME_CAP	0

#endif