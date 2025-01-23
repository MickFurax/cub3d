/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabeman <arabeman@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 11:03:00 by arabeman          #+#    #+#             */
/*   Updated: 2025/01/22 09:18:40 by arabeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void set_map(t_data *data)
{
	char **map;

	map = malloc(sizeof(char *) * 9);
	if (!map)
		return;
	map[0] = ft_strdup("11111111");
	map[1] = ft_strdup("10000001");
	map[2] = ft_strdup("10000111");
	map[3] = ft_strdup("10000011");
	map[4] = ft_strdup("10110001");
	map[5] = ft_strdup("10000001");
	map[6] = ft_strdup("10100N01");
	map[7] = ft_strdup("11111111");
	map[8] = NULL;
	data->map = map;
}
