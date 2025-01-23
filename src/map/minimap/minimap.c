/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabeman <arabeman@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 16:20:54 by arabeman          #+#    #+#             */
/*   Updated: 2025/01/22 11:10:58 by arabeman         ###   ########.fr       */
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
	minimap->x = 0;
	minimap->y = 0;
	set_minimap_img(minimap);
	data->minimap = minimap;
}

void set_minimap_img(t_minimap *minimap)
{
	minimap->minimap_img.img_ptr = mlx_new_image(minimap->mlx, MINIMAP_WIDTH, MINIMAP_HEIGHT);
	minimap->minimap_img.addr = mlx_get_data_addr(minimap->minimap_img.img_ptr, &minimap->minimap_img.bits_per_pixel, &minimap->minimap_img.size_line, &minimap->minimap_img.endian);
	//* player
	int _;
	minimap->player_img.angle = 0;
	minimap->player_img.img_ptr	= mlx_xpm_file_to_image(minimap->mlx, "asset/minimap/player_32.xpm", &_, &_);
	minimap->player_img.addr = mlx_get_data_addr(minimap->player_img.img_ptr, &minimap->player_img.bits_per_pixel, &minimap->player_img.size_line, &minimap->player_img.endian);
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

void set_player_index(t_data *data)
{
	char **map = data->map;

	if (!map)
		return;
	data->player_index[0] = 0;
	data->player_index[1] = 0;
	int i = 0;
	int j = 0;
	while (i < 8)
	{
		j = 0;
		while (j < 8)
		{
			if (map[i][j] == 'N')
			{
				data->player_index[0] = i;
				data->player_index[1] = j;
				map[i][j] = '0';
				return;
			}
			j++;
		}
		i++;
	}
}
