/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaccary <smaccary@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 14:52:42 by smaccary          #+#    #+#             */
/*   Updated: 2020/08/06 17:13:34 by smaccary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENTS_H
# define EVENTS_H

# ifdef __linux__

#  define ESC_KEY			65307
#  define F_KEY				102

#  define ARROW_UP_KEY		65362
#  define ARROW_DOWN_KEY	65364
#  define ARROW_LEFT_KEY	65361
#  define ARROW_RIGHT_KEY	65363
#  define LEFT_SHIFT_KEY	65506

#  ifndef QWERTY
#   define FORWARD_KEY		122
#   define BACKWARD_KEY		115
#   define LEFT_KEY			113
#   define RIGHT_KEY		100
#   define CTRL_KEY			65507
#   define LEFT_ALT_KEY		99
#   define C_KEY			99
#  endif

#  ifdef QWERTY
#   define FORWARD_KEY		119
#   define BACKWARD_KEY		115
#   define LEFT_KEY			97
#   define RIGHT_KEY		100
#   define CTRL_KEY			65507
#   define LEFT_ALT_KEY		99
#   define C_KEY			99
#  endif

# endif

# ifdef __APPLE__

#  define ARROW_UP_KEY		126
#  define ARROW_DOWN_KEY	125
#  define ARROW_LEFT_KEY	123
#  define ARROW_RIGHT_KEY	124
#  define LEFT_SHIFT_KEY	258

#  define FORWARD_KEY		13
#  define BACKWARD_KEY		1
#  define LEFT_KEY			0
#  define RIGHT_KEY			2
#  define CTRL_KEY			256
#  define LEFT_ALT_KEY		8
#  define C_KEY				8
#  define ESC_KEY			53
#  define F_KEY				3

# endif

# ifdef _WIN32

#  define ARROW_UP_KEY		1073741906
#  define ARROW_DOWN_KEY	1073741905
#  define ARROW_LEFT_KEY	1073741904
#  define ARROW_RIGHT_KEY	1073741903
#  define LEFT_SHIFT_KEY	1073742053

#  define FORWARD_KEY		122
#  define BACKWARD_KEY		115
#  define LEFT_KEY			113
#  define RIGHT_KEY			100
#  define CTRL_KEY			1073742048
#  define LEFT_ALT_KEY		1073742050
#  define C_KEY				99
#  define ESC_KEY			27
#  define F_KEY				102

# endif

#endif
