/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabeman <arabeman@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 11:34:30 by arabeman          #+#    #+#             */
/*   Updated: 2025/01/27 15:39:56 by arabeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int key_press(int keycode, t_data *data)
{
	if (keycode == W || keycode == UP)
		data->key.forward = true;
	if (keycode == S || keycode == DOWN)
		data->key.backward = true;
	if (keycode == A)
		data->key.left = true;
	if (keycode == D)
		data->key.right = true;
	if (keycode == LEFT)
		data->key.turn_left = true;
	if (keycode == RIGHT)
		data->key.turn_right = true;
	if (keycode == Q || keycode == ESC)
		mlx_loop_end(data->mlx);
	return (0);
}

int key_release(int keycode, t_data *data)
{
	if (keycode == W || keycode == UP)
		data->key.forward = false;
	if (keycode == S || keycode == DOWN)
		data->key.backward = false;
	if (keycode == A)
		data->key.left = false;
	if (keycode == D)
		data->key.right = false;
	if (keycode == LEFT)
		data->key.turn_left = false;
	if (keycode == RIGHT)
		data->key.turn_right = false;
	return (0);
}
