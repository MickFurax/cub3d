/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_wall.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabenja <mrabenja@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 13:27:16 by mrabenja          #+#    #+#             */
/*   Updated: 2025/02/12 15:39:45 by mrabenja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static double	calculate_wall_x(t_ray_data *rd, double ray_dist)
{
	double wall_x; // exact position where the ray hit
	// Calculate texture X coordinate // this is the key
	if (rd->side == 0)
		wall_x = rd->ray_y / TILE_SIZE + ray_dist * sin(rd->ray_angle);
	else
		wall_x = rd->ray_x / TILE_SIZE + ray_dist * cos(rd->ray_angle);
	return (wall_x - floor(wall_x / TILE_SIZE) * TILE_SIZE);
	// get the decimal part
}

static void	set_texture_coord(t_texture *wall_txt, t_ray_data *rd,
		double wall_x, int *tex_x)
{
	// Convert to texture coordinate
	*tex_x = (int)(wall_x * (double)wall_txt->width) % wall_txt->width;
	// Flip texture coordinate if needed to prevent mirroring
	if ((rd->side == 0 && rd->step_x < 0) || (rd->side == 1 && rd->step_y > 0))
		*tex_x = wall_txt->width - *tex_x - 1;
}
static void	draw_texture_line(t_data *data, int col, t_render_param *param)
{
	int	y;
	int	color;

	y = param->draw_start;
	param->tex_pos = (param->draw_start - WIN_HEIGHT / 2 + param->line_height / 2)
		* param->step;
	while (y < param->draw_end)
	{
		param->tex_y = (int)param->tex_pos & (param->texture->height - 1);
		param->tex_pos += param->step;
		// Get pixel color from texture
		color = get_texture_pxl(param->texture, param->tex_x, param->tex_y);
		// Put pixel in framebuffer
		put_pixel(data->framebuff->addr, (y * WIN_WIDTH + col) * 4, color);
		y++;
	}
}

void	render_textured_wall(int col, double ray_dist, t_data *data,
		t_ray_data *rd)
{
	t_render_param param;
	double wall_x;

	param.line_height = (WIN_HEIGHT / rd->corrected_fisheye);
	calculate_wall_bound(rd->corrected_fisheye, &param.draw_start, &param.draw_end);
	param.texture = get_wall_txt(data, rd);
	wall_x = calculate_wall_x(rd, ray_dist);
	set_texture_coord(param.texture, rd, wall_x, &param.tex_x);
	param.step = (double)param.texture->height / param.line_height;
	draw_texture_line(data, col, &param);
}