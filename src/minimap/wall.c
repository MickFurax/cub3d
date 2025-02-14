/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabeman <arabeman@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 10:28:45 by arabeman          #+#    #+#             */
/*   Updated: 2025/02/14 14:16:28 by arabeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int _get_wall_x(int player_x, int wall_x)
{
    return ((PLAYER_POS + (wall_x - player_x) * 32));
}

int _get_wall_y(int player_y, int wall_y)
{
    return ((PLAYER_POS + (wall_y - player_y) * 32));
}

void draw_square(t_minimap *minimap, int x, int y)
{
    int i;

    i = 1;
    while (i < MINIMAP_TILE - 1)
    {
        int j = 1;
        while (j < MINIMAP_TILE - 1)
        {
            put_pixel_minimap(minimap, i + x, j + y, MINIMAP_COLOR);
            j++;
        }
        i++;
    }
}

void render_wall_minimap(t_data *data, int x, int y)
{
    char **map = data->map_config->map;
    int player_x_i = data->player_start_index[0];
    int player_y_i = data->player_start_index[1];

    int x_i = 0;
    int y_i = 0;
    while (x_i < tab_length(map))
    {
        y_i = 0;
        while (y_i < (int)ft_strlen(map[x_i]))
        {
            if (map[x_i][y_i] != '0' && map[x_i][y_i] != 'N' && map[x_i][y_i] != 'S' && map[x_i][y_i] != 'E' && map[x_i][y_i] != 'W')
                draw_square(data->minimap, _get_wall_y(player_y_i, y_i) + y, _get_wall_x(player_x_i, x_i) + x);
            y_i++;
        }
        x_i++;
    }
}