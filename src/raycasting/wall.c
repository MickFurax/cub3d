/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabenja <mrabenja@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:20:43 by mrabenja          #+#    #+#             */
/*   Updated: 2025/02/03 15:14:54 by mrabenja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	render_wall(int col, double ray_dist, void *img, char *addr)
{
	int line_height;
	int draw_start;
	int draw_end;
	int y;
	(void)img;

	line_height = (int)(WIN_HEIGHT / ray_dist);
	// center the wall --> /2 in the uppper win height, the other in the lower
	draw_start = WIN_HEIGHT / 2 - line_height / 2;
	if (draw_start < 0) // wall really big
		draw_start = 0;
	draw_end = WIN_HEIGHT / 2 + line_height / 2;
	if (draw_end >= WIN_HEIGHT)
		draw_end = WIN_HEIGHT - 1;
	int color = 0xFFFFFF;
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
