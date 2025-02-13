/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabeman <arabeman@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 14:09:56 by arabeman          #+#    #+#             */
/*   Updated: 2025/02/13 14:28:53 by arabeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void init_minimap(t_data *data)
{
    t_minimap *minimap;

    minimap = malloc(sizeof(t_minimap));
    if (!minimap)
        return;
    minimap->map = data->map_config->map;
    minimap->minimap_img.img_ptr = mlx_new_image(data->mlx, MINIMAP_W, MINIMAP_H);
    minimap->minimap_img.addr = mlx_get_data_addr(minimap->minimap_img.img_ptr, &minimap->minimap_img.bits_per_pixel, &minimap->minimap_img.size_line, &minimap->minimap_img.endian);

    int _;
    minimap->player_img.angle = 0;
    minimap->player_img.img_ptr = mlx_xpm_file_to_image(data->mlx, "texture/minimap/player_32.xpm", &_, &_);
    minimap->player_img.addr = mlx_get_data_addr(minimap->player_img.img_ptr, &minimap->player_img.bits_per_pixel, &minimap->player_img.size_line, &minimap->player_img.endian);
    data->minimap = minimap;
}
