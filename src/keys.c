/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaccary <smaccary@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/11 13:45:37 by smaccary          #+#    #+#             */
/*   Updated: 2020/08/13 00:30:35 by smaccary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "keys.h"

int		init_keys(t_key keys[K_BUFF_SIZE])
{
	int	i;
	
	i = -1;
	while (++i < K_BUFF_SIZE)
	{
		keys[i].keycode = -1;
		keys[i].time = -1;
	}
	return (K_BUFF_SIZE);
}

int		key_press_hook(int keycode, t_key keys[K_BUFF_SIZE])
{
	int i;

	i = 0;
	while (i < K_BUFF_SIZE && (keys[i]).keycode != -1)
		i++;
	if (i >= K_BUFF_SIZE || keys[i].keycode != -1)
		return (0);
	keys[i].keycode = keycode;
	while (++i < K_BUFF_SIZE)
	{
		if (keys[i].keycode == keycode)
			keys[i].keycode = -1;
	}
	return (0);
}

int		key_release_hook(int keycode, t_key keys[K_BUFF_SIZE])
{
	int				i;

	i = -1;
	while (++i < K_BUFF_SIZE)
	{
		if (keys[i].keycode == keycode)
		{
			if (i >= K_BUFF_SIZE)
				return (0);
			keys[i].keycode = -1;
			keys[i].time = 0;
		}
	}
	return (0);
}

t_key	*key_chr(t_key *arr, int keycode, size_t size)
{
	size_t	i;

	i = -1;
	while (++i < size)
		if (arr[i].keycode == keycode)
			return (arr + i);
	return (NULL);
}
