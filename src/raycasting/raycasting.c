/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabenja <mrabenja@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 11:48:55 by mrabenja          #+#    #+#             */
/*   Updated: 2025/01/28 16:05:10 by mrabenja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

bool	has_wall_at(t_data *data, int x, int y)
{
	char	**map;
	char	c;

	map = data->map_config->map;
	c = map[(int)floor(y / TILE_SIZE)][(int)floor(x / TILE_SIZE)];
	if (c == '1')
		return (true);
	return (false);
}

void	cast_ray(t_map_config *cf, int col, double *ray_dst)
{
	double ray_angle = cf->player_angle + ((col - WIN_WIDTH / 2.0) / WIN_WIDTH)
		* FOV_ANGLE; // this what makes it an offset
        //represents how much the ray's angle deviate from the player's central angle
    reset_angle(&ray_angle);
    double ray_x = cf->player_x;
    double ray_y = cf->player_y;
}