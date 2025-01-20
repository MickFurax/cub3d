/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabeman <arabeman@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 11:44:41 by arabeman          #+#    #+#             */
/*   Updated: 2025/01/17 17:14:09 by arabeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void init_data(t_data *data, int argc, char **argv)
{
    set_map(data);
    init_minimap(data);
    (void)argc;
    (void)argv;
}

void free_data(t_data *data)
{
    tab_free(data->map);
    free_minimap(data);
}
