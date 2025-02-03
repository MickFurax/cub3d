/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabenja <mrabenja@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 10:34:03 by mrabenja          #+#    #+#             */
/*   Updated: 2025/02/03 15:23:03 by mrabenja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	move_player(t_data *data)
{
	double cosine;
	double sine;

	cosine = cos(data->map_config->player_angle);
	sine = sin(data->map_config->player_angle);
	if (data->key.forward)
	{
		if (!has_wall_at(data, data->map_config->player_x + cosine * MOVE_SPEED,
				data->map_config->player_y + sine * MOVE_SPEED))
		{
			data->map_config->player_x  += cosine * MOVE_SPEED;
			data->map_config->player_y += sine *MOVE_SPEED;
		}
		data->key.forward = false;
	}
	if (data->key.backward)
	{
		if (!has_wall_at(data, data->map_config->player_x - cosine * MOVE_SPEED,
				data->map_config->player_y - sine * MOVE_SPEED))
		{
			data->map_config->player_x  -= cosine * MOVE_SPEED;
			data->map_config->player_y -= sine *MOVE_SPEED;
		}
		data->key.backward = false;
	}
	//perpendicular counterclockwise --> if vector (cos T , sin T); then (-sin T ,cos T)
	if (data->key.left)
	{
		if (!has_wall_at(data, data->map_config->player_x + sine * MOVE_SPEED,
				data->map_config->player_y - cosine * MOVE_SPEED))
		{
			data->map_config->player_x  += sine * MOVE_SPEED;
			data->map_config->player_y -= cosine *MOVE_SPEED;
		}
		data->key.left = false;
	}
	//perpendicular clockwise --> opposite of the previous
	if (data->key.right) 
	{
		if (!has_wall_at(data, data->map_config->player_x - sine * MOVE_SPEED,
				data->map_config->player_y + cosine * MOVE_SPEED))
		{
			data->map_config->player_x  -= sine * MOVE_SPEED;
			data->map_config->player_y += cosine *MOVE_SPEED;
		}
		data->key.right = false;
	}
	if (data->key.turn_left)
	{
		data->map_config->player_angle -= ROTA_SPEED;
		data->key.turn_left = false;
	}
	if (data->key.turn_right)
	{
		data->map_config->player_angle += ROTA_SPEED;
		data->key.turn_right = false;
	}
	reset_angle(&data->map_config->player_angle);
}
