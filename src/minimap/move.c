/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabeman <arabeman@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 10:34:03 by mrabenja          #+#    #+#             */
/*   Updated: 2025/02/17 10:04:41 by arabeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static void update_position(t_data *data, double x, double y)
{
	data->minimap->x = x;
	data->minimap->y = y;
}

static void handle_frwrd_bckwrd(t_data *data, float speed)
{
	double cos_angle;
	double sin_angle;

	cos_angle = cos(data->map_config->player_angle);
	sin_angle = sin(data->map_config->player_angle);
	if (data->key.backward)
		update_position(data, data->minimap->x + sin_angle * speed,
						data->minimap->y + cos_angle * speed);
	if (data->key.forward)
		update_position(data, data->minimap->x - sin_angle * speed,
						data->minimap->y - cos_angle * speed);
}

static void handle_left_right(t_data *data, float speed)
{
	double cos_angle;
	double sin_angle;

	cos_angle = cos(data->map_config->player_angle);
	sin_angle = sin(data->map_config->player_angle);
	if (data->key.left)
		update_position(data, data->minimap->x + cos_angle * speed,
						data->minimap->y - sin_angle * speed);
	if (data->key.right)
		update_position(data, data->minimap->x - cos_angle * speed,
						data->minimap->y + sin_angle * speed);
}

void move_player_minimap(t_data *data, float speed)
{
	if ((data->key.forward && (data->key.right || data->key.left)) || (data->key.backward && (data->key.right || data->key.left)))
		speed /= 2;
	handle_frwrd_bckwrd(data, speed);
	handle_left_right(data, speed);
}
