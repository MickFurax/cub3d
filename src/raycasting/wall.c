/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabenja <mrabenja@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:20:43 by mrabenja          #+#    #+#             */
/*   Updated: 2025/02/05 15:54:25 by mrabenja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	render_wall(int col, double ray_dist, char *addr, int side)
{
	int line_height;
	int draw_start;
	int draw_end;
	int y;
	int	color;

	line_height = (int)(WIN_HEIGHT / ray_dist);
	// center the wall --> /2 in the uppper win height, the other in the lower
	draw_start = WIN_HEIGHT / 2 - line_height / 2;
	if (draw_start < 0) // wall really big
		draw_start = 0;
	draw_end = WIN_HEIGHT / 2 + line_height / 2;
	if (draw_end >= WIN_HEIGHT)
		draw_end = WIN_HEIGHT - 1;
	color = 0xEEEEEE;
	if (side)
		color = 0xFFFFFF;
	y = draw_start;
	while (y < draw_end)
	{
		int pix_idx  = (y * WIN_WIDTH + col) * 4;
		addr[pix_idx] = color & 0xFF;
		addr[pix_idx + 1] = (color >> 8) & 0xFF;
		addr[pix_idx + 2] = (color >> 16) & 0xFF;
		y++;
	}
}

void	render_textured_wall(int col, double ray_dist, t_ray_data *rd, t_data *data)
{
	int line_height;
	int draw_start;
	int draw_end;
	int y;
	int	texture[2]; //x and y

	t_texture *wall_txt = get_wall_txt(data, rd);
	line_height = (int)(WIN_HEIGHT / ray_dist);
	// center the wall --> /2 in the uppper win height, the other in the lower
	draw_start = WIN_HEIGHT / 2 - line_height / 2;
	if (draw_start < 0) // wall really big
		draw_start = 0;
	draw_end = WIN_HEIGHT / 2 + line_height / 2;
	if (draw_end >= WIN_HEIGHT)
		draw_end = WIN_HEIGHT - 1;
		
	texture[0]=rd->
	// if (side)
	// 	color = 0xFFFFFF;
	// y = draw_start;
	// while (y < draw_end)
	// {
	// 	int pix_idx  = (y * WIN_WIDTH + col) * 4;
	// 	addr[pix_idx] = color & 0xFF;
	// 	addr[pix_idx + 1] = (color >> 8) & 0xFF;
	// 	addr[pix_idx + 2] = (color >> 16) & 0xFF;
	// 	y++;
	// }
}