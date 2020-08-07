/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_events.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaccary <smaccary@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 17:43:39 by smaccary          #+#    #+#             */
/*   Updated: 2020/08/06 16:33:02 by smaccary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef X_EVENTS_H
# define X_EVENTS_H

/*
** EVENT_DEFINITIONS
*/

# define NO_EVENT_MASK				0L
# define KEY_PRESS_MASK				1L
# define KEY_RELEASE_MASK			2L
# define BUTTON_PRESS_MASK			4L
# define BUTTON_RELEASE_MASK		8L
# define ENTER_WINDOW_MASK			16L
# define LEAVE_WINDOW_MASK			32L
# define POINTER_MOTION_MASK		64L
# define POINTER_MOTION_HINT_MASK	128L
# define BUTTON_1_MOTION_MASK		256L
# define BUTTON_2_MOTION_MASK		512L
# define BUTTON_3_MOTION_MASK		1024L
# define BUTTON_4_MOTION_MASK		2048L
# define BUTTON_5_MOTION_MASK		4096L
# define BUTTON_MOTION_MASK			8192L
# define KEYMAP_STATE_MASK			16384L
# define EXPOSURE_MASK				32768L
# define VISIBILITY_CHANGE_MASK		65536L
# define STRUCTURE_NOTIFY_MASK		131072L
# define RESIZE_REDIRECT_MASK		262144L
# define SUBSTRUCTURE_NOTIFY_MASK	524288L
# define SUBSTRUCTURE_REDIRECT_MASK	1048576L
# define FOCUS_CHANGE_MASK			2097152L
# define PROPERTY_CHANGE_MASK		4194304L
# define COLOR_MAP_CHANGE_MASK		8388608L
# define OWNER_GRAB_BUTTON_MASK		16777216L

/*
** Event names.  Used in "type" field in XEvent structures.  Not to be
**	confused with event masks above.  They start from 2 because 0 and 1
**	are reserved in the protocol for errors and replies.
*/

# define KEY_PRESS			2
# define KEY_RELEASE		3
# define BUTTON_PRESS		4
# define BUTTON_RELEASE		5
# define MOTION_NOTIFY		6
# define ENTER_NOTIFY		7
# define LEAVE_NOTIFY		8
# define FOCUS_IN			9
# define FOCUS_OUT			10
# define KEYMAP_NOTIFY		11
# define EXPOSE				12
# define GRAPHICS_EXPOSE	13
# define NO_EXPOSE			14
# define VISIBILITY_NOTIFY	15
# define CREATE_NOTIFY		16
# define DESTROY_NOTIFY		17
# define UNMAP_NOTIFY		18
# define MAP_NOTIFY			19
# define MAP_REQUEST		20
# define REPARENT_NOTIFY	21
# define CONFIGURE_NOTIFY	22
# define CONFIGURE_REQUEST	23
# define GRAVITY_NOTIFY		24
# define RESIZE_REQUEST		25
# define CIRCULATE_NOTIFY	26
# define CIRCULATE_REQUEST	27
# define PROPERTY_NOTIFY	28
# define SELECTION_CLEAR	29
# define SELECTION_REQUEST	30
# define SELECTION_NOTIFY	31
# define COLORMAP_NOTIFY	32
# define CLIENT_MESSAGE		33
# define MAPPING_NOTIFY		34
# define GENERIC_EVENT		35
# define LAST_EVENT			36

/*
**	Key masks. Used as modifiers to GrabButton and GrabKey,
**	results of QueryPointer,
**	state in various key-, mouse-, and button-related events.
*/

# define SHIFT_MASK		1
# define LOCK_MASK		2
# define CONTROL_MASK	4
# define MOD_1_MASK		8
# define MOD_2_MASK		16
# define MOD_3_MASK		32
# define MOD_4_MASK		64
# define MOD_5_MASK		128

/*
**	modifier names.  Used to build a SetModifierMapping request or
**	to read a GetModifierMapping request.  These correspond to the
**	masks  defined above.
*/

# define SHIFT_MAP_INDEX		0
# define LOCK_MAP_INDEX			1
# define CONTROL_MAP_INDEX		2
# define MOD_1_MAP_INDEX		3
# define MOD_2_MAP_INDEX		4
# define MOD_3_MAP_INDEX		5
# define MOD_4_MAP_INDEX		6
# define MOD_5_MAP_INDEX		7

/*
**	button masks.  Used in same manner as Key masks above. Not to be confused
**	with button names below.
*/

# define BUTTON_1_MASK		256
# define BUTTON_2_MASK		512
# define BUTTON_3_MASK		1024
# define BUTTON_4_MASK		2048
# define BUTTON_5_MASK		4096

#endif
