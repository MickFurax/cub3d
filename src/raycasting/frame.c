/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabenja <mrabenja@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 16:27:23 by mrabenja          #+#    #+#             */
/*   Updated: 2025/02/12 15:15:12 by mrabenja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	ft_mlx_pixel_put(t_framebuffer *img, int x, int y, unsigned int color)
{
	char	*dest;

	if (x < 0 || y < 0 || x >= WIN_WIDTH || y >= WIN_HEIGHT)
		return ;
	dest = img->addr + (y * img->line_length + x * (img->bpp / 8));
	*(unsigned int *)dest = color;
}

static void	refresh_framebuff(t_data *data)
{
	int	i;
	int	j;

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

void	render_frame(t_data *data)
{
	int			col;
	t_ray_data	rd;
	double		ray_dist;

	ray_dist = 0;
	col = 0;
	refresh_framebuff(data);
	render_background(data);
	while (col < WIN_WIDTH)
	{
		cast_ray2(data->map_config, col, &ray_dist, &rd);
		render_textured_wall(col, ray_dist, data, &rd);
		col++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->framebuff->img, 0, 0);
}
