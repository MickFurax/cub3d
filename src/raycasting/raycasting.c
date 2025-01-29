/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabenja <mrabenja@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 11:48:55 by mrabenja          #+#    #+#             */
/*   Updated: 2025/01/29 17:27:14 by mrabenja         ###   ########.fr       */
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

static void	init_ray_data(t_ray_data *rd)
{
	rd->ray_x = 0.0;
	rd->ray_y = 0.0;
	rd->delta_x = 0.0;
	rd->delta_y = 0.0;
	rd->step_x = 0;
	rd->step_y = 0;
	rd->side_dist_x = 0.0;
	rd->side_dist_y = 0.0;
	rd->hit = 0;
	rd->side = 0;
	rd->ray_angle = 0.0;
}

static void	set_step(int *step_x, int *step_y, double ray_angle)
{
	if (cos(ray_angle) >= 0)
		*step_x = 1;
	else
		*step_x = -1;
	if (sin(ray_angle) >= 0)
		*step_y = 1;
	else
		*step_y = -1;
}

static void set_dist(t_ray_data *rd, t_map_config *cf)
{
	if (rd->step_x > 0)
		rd->side_dist_x = (cf->map_x + 1 - rd->ray_x / TILE_SIZE) * rd->delta_x;
	else
		rd->side_dist_x = (rd->ray_x / TILE_SIZE - cf->map_x) * rd->delta_x;
	if (rd->step_y > 0)
		rd->side_dist_y = (cf->map_y + 1 - rd->ray_y / TILE_SIZE) * rd->delta_y;
	else
		rd->side_dist_y = (rd->ray_y / TILE_SIZE - cf->map_y) * rd->delta_y;
		
}

void	cast_ray(t_map_config *cf, int col, double *ray_dst)
{

	t_ray_data rd;

	init_map_config(&rd);
	rd.ray_angle = cf->player_angle + ((col - WIN_WIDTH / 2.0) / WIN_WIDTH)
		* FOV_ANGLE; // this what makes it an offset
	// represents how much the ray's angle deviate from the player's central angle
	reset_angle(&rd.ray_angle);
	rd.ray_x = cf->player_x;
	rd.ray_y = cf->player_y;
	rd.delta_x = fabs(1 / (cos(rd.ray_angle)));
	rd.delta_y = fabs(1 / (sin(rd.ray_angle)));
	cf->map_x = (int)(rd.ray_x / TILE_SIZE);
	cf->map_y = (int)(rd.ray_y / TILE_SIZE);
	set_step(&rd.step_x, &rd.step_y, rd.ray_angle);
	/*
	side_dist_x = (next_vertical_grid_x − ray_x) × delta_dist_x
	side_dist_y = (next_horizontal_grid_y − ray_y) × delta_dist_y
	*/
	set_dist(&rd, cf);
	//

}
