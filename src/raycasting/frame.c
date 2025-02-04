/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabeman <arabeman@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 16:27:23 by mrabenja          #+#    #+#             */
/*   Updated: 2025/02/04 14:38:31 by arabeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static void ft_mlx_pixel_put(t_framebuffer *img, int x, int y, unsigned int color)
{
	char *dest;

	if (x < 0 || y < 0 || x >= WIN_WIDTH || y >= WIN_HEIGHT)
		return;
	dest = img->addr + (y * img->line_length + x * (img->bpp / 8));
	*(unsigned int *)dest = color;
}

static void refresh_framebuff(t_data *data)
{
	int i;
	int j;

	j = 0;
	while (j < WIN_HEIGHT)
	{
		i = 0;
		while (i < WIN_WIDTH)
		{
			ft_mlx_pixel_put(data->framebuff, i, j, 0x0);
			i++;
		}
		j++;
	}
}

void render_frame(t_data *data)
{
	int col;
	double ray_dist;

	ray_dist = 0;
	col = 0;
	refresh_framebuff(data);
	while (col < WIN_WIDTH)
	{
		render_wall(col, ray_dist, data->framebuff->img, data->framebuff->addr, cast_ray(data->map_config, col, &ray_dist));
		col++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->framebuff->img, 0, 0);
}
