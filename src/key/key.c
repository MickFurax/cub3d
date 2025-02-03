/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabenja <mrabenja@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 11:34:30 by arabeman          #+#    #+#             */
/*   Updated: 2025/02/03 14:27:45 by mrabenja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int key_press(int keycode, t_data *data)
{
	if (keycode == W || keycode == UP)
		data->key.forward = true;
	else if (keycode == S || keycode == DOWN)
		data->key.backward = true;
	else if (keycode == A)
		data->key.left = true;
	else if (keycode == D)
		data->key.right = true;
	else if (keycode == LEFT)
		data->key.turn_left = true;
	else if (keycode == RIGHT)
		data->key.turn_right = true;
	else if (keycode == Q || keycode == ESC)
		mlx_loop_end(data->mlx);
	return (0);
}

int key_release(int keycode, t_data *data)
{
	if (keycode == W || keycode == UP)
		data->key.forward = false;
	else if (keycode == S || keycode == DOWN)
		data->key.backward = false;
	else if (keycode == A)
		data->key.left = false;
	else if (keycode == D)
		data->key.right = false;
	else if (keycode == LEFT)
		data->key.turn_left = false;
	else if (keycode == RIGHT)
		data->key.turn_right = false;
	return (0);
}
