/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabeman <arabeman@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 11:12:21 by arabeman          #+#    #+#             */
/*   Updated: 2025/02/05 11:38:27 by arabeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static int _rgb_to_int(t_color rgb)
{
    int color;

    color = rgb.r;
    color = (color << 8) | rgb.g;
    color = (color << 8) | rgb.b;
    return (color);
}

void render_background(t_data *data)
{
    int floor_color;
    int ceiling_color;

    floor_color = _rgb_to_int(data->map_config->floor_c);
    ceiling_color = _rgb_to_int(data->map_config->ceiling_c);

    int i = 0;
    int j;
    while (i < WIN_HEIGHT)
    {
        j = 0;
        while (j < WIN_WIDTH)
        {
            if (i < WIN_HEIGHT / 2)
                ft_mlx_pixel_put(data->framebuff, j, i, ceiling_color);
            else
                ft_mlx_pixel_put(data->framebuff, j, i, floor_color);
            j++;
        }
        i++;
    }
}
