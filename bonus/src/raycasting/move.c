/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabenja <mrabenja@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 10:34:03 by mrabenja          #+#    #+#             */
/*   Updated: 2025/02/12 12:41:43 by mrabenja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static void	handle_rotation(t_data *data)
{
	if (data->key.turn_left)
		data->map_config->player_angle -= ROTA_SPEED;
	if (data->key.turn_right)
		data->map_config->player_angle += ROTA_SPEED;
	reset_angle(&data->map_config->player_angle);
}

static	void update_position(t_data *data, double x, double y)
{
	if (!has_wall_at(data, x, y))
	{
		data->map_config->player_x = x;
		data->map_config->player_y = y;
	}
}

static void	handle_frwrd_bckwrd(t_data *data, float speed)
{
	double	cos_angle;
	double	sin_angle;

	cos_angle = cos(data->map_config->player_angle);
	sin_angle = sin(data->map_config->player_angle);
	if (data->key.forward)
		update_position(data, data->map_config->player_x + cos_angle * speed,
			data->map_config->player_y + sin_angle * speed);
	if (data->key.backward)
		update_position(data, data->map_config->player_x - cos_angle * speed,
			data->map_config->player_y - sin_angle * speed);
}

static void	handle_left_right(t_data *data, float speed)
{
	double	cos_angle;
	double	sin_angle;

	cos_angle = cos(data->map_config->player_angle);
	sin_angle = sin(data->map_config->player_angle);
	if (data->key.left)
		update_position(data, data->map_config->player_x + sin_angle * speed,
			data->map_config->player_y - cos_angle * speed);
	if (data->key.right)
		update_position(data, data->map_config->player_x - sin_angle * speed,
			data->map_config->player_y + cos_angle * speed);
}

void	move_player(t_data *data)
{
	float speed;

	speed = MOVE_SPEED;
	if ((data->key.forward && (data->key.right || data->key.left))
		|| (data->key.backward && (data->key.right || data->key.left)))
		speed = DIAGONAL_SPEED;
	handle_frwrd_bckwrd(data, speed);
	handle_left_right(data, speed);
	handle_rotation(data);
}
