/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabenja <mrabenja@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 16:27:23 by mrabenja          #+#    #+#             */
/*   Updated: 2025/01/30 16:38:49 by mrabenja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	render_frame(t_data *data)
{
	int		col;
	double	ray_dist;

	ray_dist = 0;
	col = 0;
	while(col < WIN_WIDTH)
	{
		cast_ray(data->map_config, col, &ray_dist);
		render_wall(col, ray_dist, data->framebuff->img, data->framebuff->addr);
		col++; 
	}
	mlx_put_image_to_window(data->mlx, data->win, data->framebuff->img, 0, 0);
}