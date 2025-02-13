/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_minimap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabeman <arabeman@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 14:07:39 by arabeman          #+#    #+#             */
/*   Updated: 2025/02/13 14:47:21 by arabeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void put_pixel_minimap(t_minimap *minimap, int x, int y, int color)
{
    char *dst;

    if (x < 0 || y < 0 || x >= MINIMAP_W || y >= MINIMAP_H)
        return ;
    dst = minimap->minimap_img.addr + (y * minimap->minimap_img.size_line + x * (minimap->minimap_img.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int render_minimap(t_data *data)
{
    t_minimap *minimap = data->minimap;
    int i = 0;
    while (i < MINIMAP_H)
    {
        int j = 0;
        while (j < MINIMAP_W)
        {
            put_pixel_minimap(data->minimap, i, j, 0x000000);
            j++;
        }
        i++;
    }
    render_img_minimap(data, minimap->player_img, PLAYER_POS, PLAYER_POS);
    mlx_put_image_to_window(data->mlx, data->win, minimap->player_img.img_ptr, PLAYER_POS, PLAYER_POS);
    mlx_put_image_to_window(data->mlx, data->win, minimap->minimap_img.img_ptr, 0, 0);
    return (0);
}
