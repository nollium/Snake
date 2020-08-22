/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaccary <smaccary@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 23:28:07 by smaccary          #+#    #+#             */
/*   Updated: 2020/08/13 00:18:10 by smaccary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYS_H
# define KEYS_H

# include <stdlib.h>

# define K_BUFF_SIZE	20

typedef struct	s_key
{
	int		keycode;
	size_t	time;
}				t_key;

int		key_press_hook(int keycode, t_key keys[K_BUFF_SIZE]);
int		key_release_hook(int keycode, t_key keys[K_BUFF_SIZE]);
t_key	*key_chr(t_key *arr, int keycode, size_t size);
int		init_keys(t_key keys[K_BUFF_SIZE]);

#endif