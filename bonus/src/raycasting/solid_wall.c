/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solid_wall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabenja <mrabenja@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:20:43 by mrabenja          #+#    #+#             */
/*   Updated: 2025/02/12 15:40:49 by mrabenja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	calculate_wall_bound(double ray_dist, int *draw_start,
		int *draw_end)
{
	int	line_height;

	line_height = (int)(WIN_HEIGHT / ray_dist);
	*draw_start = WIN_HEIGHT / 2 - line_height / 2;
	*draw_end = WIN_HEIGHT / 2 + line_height / 2;
	if (*draw_start < 0)
		*draw_start = 0;
	if (*draw_end >= WIN_HEIGHT)
		*draw_end = WIN_HEIGHT - 1;
}

void	put_pixel(char *addr, int pix_idx, int color)
{
	addr[pix_idx] = color & 0xFF;             // B
	addr[pix_idx + 1] = (color >> 8) & 0xFF;  // G
	addr[pix_idx + 2] = (color >> 16) & 0xFF; // R
}

void	render_wall(int col, double ray_dist, char *addr, int side)
{
	int	draw_start;
	int	draw_end;
	int	y;
	int	color;

	calculate_wall_bound(ray_dist, &draw_start, &draw_end);
	color = 0x00FF00; // Greeen for vertical walls
	if (side)
		color = 0x0000FF; // BLUE i guess
	y = draw_start;
	while (y < draw_end)
	{
		put_pixel(addr, (y * WIN_WIDTH + col) * 4, color);
		y++;
	}
}

