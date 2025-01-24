/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabeman <arabeman@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 17:02:01 by arabeman          #+#    #+#             */
/*   Updated: 2025/01/24 15:07:14 by arabeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void put_pixel(t_minimap *minimap, int x, int y, int color)
{
	char *dst;

	if (x < 0 || y < 0 || x >= MINIMAP_WIDTH || y >= MINIMAP_HEIGHT)
		return;
	dst = minimap->minimap_img.addr + (y * minimap->minimap_img.size_line + x * (minimap->minimap_img.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

unsigned int get_pixel_img(t_img img, int x, int y)
{
	return (*(unsigned int *)((img.addr + (y * img.size_line) + (x * img.bits_per_pixel / 8))));
}

void put_img(t_data *data, t_img img, int x, int y)
{
	int i;
	int j;
	(void)x;
	(void)y;
	int new_x;
	int new_y;
	double cos_angle = cos(-img.angle);
	double sin_angle = sin(-img.angle);

	i = 0;
	while (i < PXL_PER_PXL)
	{
		j = 0;
		while (j < PXL_PER_PXL)
		{
			new_x = cos_angle * (i - (PXL_PER_PXL / 2)) - sin_angle * (j - (PXL_PER_PXL / 2)) + (PXL_PER_PXL / 2);
			new_y = sin_angle * (i - (PXL_PER_PXL / 2)) + cos_angle * (j - (PXL_PER_PXL / 2)) + (PXL_PER_PXL / 2);
			if (new_x >= 0 && new_x < PXL_PER_PXL && new_y >= 0 && new_y < PXL_PER_PXL && get_pixel_img(img, new_x, new_y) != 0xFF000000)
			{
				put_pixel(data->minimap, x + i, y + j, get_pixel_img(img, new_x, new_y));
			}
			j++;
		}
		i++;
	}
}

void draw_square(t_minimap *minimap, int x, int y)
{
	int i;

	i = 1;
	while (i < PXL_PER_PXL - 1)
	{
		int j = 1;
		while (j < PXL_PER_PXL - 1)
		{
			put_pixel(minimap, i + x, j + y, 0xADD8E6);
			j++;
		}
		i++;
	}
}

int _get_wall_x(int player_x, int wall_x)
{
	return ((CENTER + (wall_x - player_x) * 32));
}

int _get_wall_y(int player_y, int wall_y)
{
	return ((CENTER + (wall_y - player_y) * 32));
}

void draw_minimap(t_data *data, int x, int y)
{
	// printf("x: %d, y: %d\n", x, y);
	char **map = data->map;
	int player_x_i = data->player_index[0];
	int player_y_i = data->player_index[1];

	int x_i = 0;
	int y_i = 0;
	while (x_i < 8)
	{
		y_i = 0;
		while (y_i < 8)
		{
			if (map[x_i][y_i] != '0' && map[x_i][y_i] != 'N')
				draw_square(data->minimap, _get_wall_y(player_y_i, y_i) + y, _get_wall_x(player_x_i, x_i) + x);
			y_i++;
		}
		x_i++;
	}
}

void clear_minimap(t_data *data, t_img player)
{
	for (int i = 0; i < MINIMAP_HEIGHT; i++)
		for (int j = 0; j < MINIMAP_WIDTH; j++)
			put_pixel(data->minimap, i, j, 0x000000);
	
	float ray_x = PXL_PER_PXL * 4;
	float ray_y = PXL_PER_PXL * 4;
	float angle = data->minimap->player_img.angle;
	printf("angle: %f\n", angle);
	float cos_angle = cos(angle - (PI / 2));
	float sin_angle = sin(angle - (PI / 2));

	for (int i = 0; i < MINIMAP_WIDTH * 2 / 2; i++)
	{
		put_pixel(data->minimap, ray_x, ray_y, 0xFF0000);
		ray_x += cos_angle;
		ray_y += sin_angle;
	}
	put_img(data, player, CENTER, CENTER);
	(void)player;
}
