/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabeman <arabeman@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 11:44:41 by arabeman          #+#    #+#             */
/*   Updated: 2025/01/22 09:26:43 by arabeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void init_data(t_data *data, int argc, char **argv)
{
    set_map(data);
    init_minimap(data);
    set_player_index(data);
    (void)argc;
    (void)argv;
}

void free_data(t_data *data)
{
    mlx_destroy_image(data->minimap->mlx, data->minimap->minimap_img.img_ptr);
    mlx_destroy_image(data->minimap->mlx, data->minimap->player_img.img_ptr);
    tab_free(data->map);
    free_minimap(data);
}
