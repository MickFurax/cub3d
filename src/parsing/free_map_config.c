/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map_config.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabenja <mrabenja@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 15:52:12 by arabeman          #+#    #+#             */
/*   Updated: 2025/02/03 10:29:09 by mrabenja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void free_map_config(t_map_config *config)
{
    free(config->no_texture);
    free(config->so_texture);
    free(config->ea_texture);
    free(config->we_texture);
    tab_free(config->map);
}
