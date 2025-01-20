/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabeman <arabeman@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 16:20:54 by arabeman          #+#    #+#             */
/*   Updated: 2025/01/17 17:49:14 by arabeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cub3d.h"

void init_minimap(t_data *data)
{
	t_minimap *minimap;

	minimap = malloc(sizeof(t_minimap));
	if (!minimap)
		return;
	minimap->map = data->map;
	minimap->mlx = mlx_init();
	if (!minimap->mlx)
		return (free(minimap));
	minimap->win = mlx_new_window(minimap->mlx, MINIMAP_WIDTH, MINIMAP_HEIGHT, "Minimap");
	if (!minimap->win)
	{
		mlx_destroy_display(minimap->mlx);
		free(minimap->mlx);
		free(minimap);
		return;
	}
	minimap->key_up = false;
	minimap->key_down = false;
	minimap->key_left = false;
	minimap->key_right = false;
	data->minimap = minimap;
}

void free_minimap(t_data *data)
{
	if (data->minimap)
	{
		if (data->minimap->win)
			mlx_destroy_window(data->minimap->mlx, data->minimap->win);
		if (data->minimap->mlx)
		{
			mlx_destroy_display(data->minimap->mlx);
			free(data->minimap->mlx);
		}
		free(data->minimap);
	}
}
