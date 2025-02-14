/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabeman <arabeman@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 14:39:47 by arabeman          #+#    #+#             */
/*   Updated: 2025/02/14 14:23:31 by arabeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

unsigned int get_pixel_img(t_img img, int x, int y)
{
	return (*(unsigned int *)((img.addr + (y * img.size_line) + (x * img.bits_per_pixel / 8))));
}

void render_img_minimap(t_data *data, t_img img, int x, int y)
{
    int i;
    int j;
    int new_x;
    int new_y;
    double cos_angle = cos(-data->map_config->player_angle - (90 * (M_PI / 180)));
    double sin_angle = sin(-data->map_config->player_angle - (90 * (M_PI / 180)));

    i = 0;
    while (i < MINIMAP_TILE)
    {
        j = 0;
        while (j < MINIMAP_TILE)
        {
            new_x = cos_angle * (i - (MINIMAP_TILE / 2)) - sin_angle * (j - (MINIMAP_TILE / 2)) + (MINIMAP_TILE / 2);
            new_y = sin_angle * (i - (MINIMAP_TILE / 2)) + cos_angle * (j - (MINIMAP_TILE / 2)) + (MINIMAP_TILE / 2);
            if (new_x >= 0 && new_x < MINIMAP_TILE && new_y >= 0 && new_y < MINIMAP_TILE && get_pixel_img(img, new_x, new_y) != 0xFF000000)
            {
                put_pixel_minimap(data->minimap, x + i, y + j, get_pixel_img(img, new_x, new_y));
            }
            j++;
        }
        i++;
    }
}
