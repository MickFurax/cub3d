/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabeman <arabeman@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 10:34:03 by mrabenja          #+#    #+#             */
/*   Updated: 2025/02/04 14:38:24 by arabeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void move_player(t_data *data)
{
	double cosine;
	double sine;
	float speed = MOVE_SPEED;

	cosine = cos(data->map_config->player_angle);
	sine = sin(data->map_config->player_angle);
	if ((data->key.forward && (data->key.right || data->key.left)) || (data->key.backward && (data->key.right || data->key.left)))
		speed = DIAGONAL_SPEED;
	if (data->key.forward)
	{
		print_hello_world();
		if (!has_wall_at(data, data->map_config->player_x + cosine * speed,
						 data->map_config->player_y + sine * speed))
		{
			data->map_config->player_x += cosine * speed;
			data->map_config->player_y += sine * speed;
		}
	}
	if (data->key.backward)
	{
		if (!has_wall_at(data, data->map_config->player_x - cosine * speed,
						 data->map_config->player_y - sine * speed))
		{
			data->map_config->player_x -= cosine * speed;
			data->map_config->player_y -= sine * speed;
		}
	}
	// perpendicular counterclockwise --> if vector (cos T , sin T); then (-sin T ,cos T)
	if (data->key.left)
	{
		if (!has_wall_at(data, data->map_config->player_x + sine * speed,
						 data->map_config->player_y - cosine * speed))
		{
			data->map_config->player_x += sine * speed;
			data->map_config->player_y -= cosine * speed;
		}
	}
	// perpendicular clockwise --> opposite of the previous
	if (data->key.right)
	{
		if (!has_wall_at(data, data->map_config->player_x - sine * speed,
						 data->map_config->player_y + cosine * speed))
		{
			data->map_config->player_x -= sine * speed;
			data->map_config->player_y += cosine * speed;
		}
	}
	if (data->key.turn_left)
	{
		data->map_config->player_angle -= ROTA_SPEED;
	}
	if (data->key.turn_right)
	{
		data->map_config->player_angle += ROTA_SPEED;
	}
	reset_angle(&data->map_config->player_angle);
}
