/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabenja <mrabenja@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 10:39:26 by mrabenja          #+#    #+#             */
/*   Updated: 2025/01/29 13:57:37 by mrabenja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static int is_pos_closed(char **map_copy, int y, int x)
{
	if (!map_copy[y - 1] || !map_copy[y - 1][x] || map_copy[y - 1][x] == ' ')
		return (0);
	if (!map_copy[y + 1] || !map_copy[y + 1][x] || map_copy[y + 1][x] == ' ')
		return (0);
	if (!map_copy[y][x - 1] || map_copy[y][x - 1] == ' ')
		return (0);
	if (!map_copy[y][x + 1] || map_copy[y][x + 1] == ' ')
		return (0);
	return (1);
}

static int get_content(int fd, t_map_config *cf, char **av)
{
	char *line;
	int i;
	int count;
	int temp_fd;

	count = 0;
	i = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		count++;
		free(line);
	}
	cf->map = (char **)malloc((count + 1) * sizeof(char *));
	if (!cf->map)
		return (0);
	close(fd);
	temp_fd = open(av[1], O_RDONLY);
	if (temp_fd < 0)
	{
		tab_free(cf->map);
		return (0);
	}
	while ((line = get_next_line(temp_fd)) != NULL)
	{
		if (ft_strchr("NSWEFC", line[0]))
			parse_id_line(line, cf);
		else if (ft_strlen(line) > 0 && is_valid_char(line[0]))
		{
			line[ft_strlen(line) - 1] = '\0';
			cf->map[i++] = ft_strdup(line);
		}
		free(line);
	}
	return (cf->map[i] = NULL, close(temp_fd), 1);
}

static int valid_map(t_map_config *map_cfg)
{
	int data[3];
	char **map;

	// x , y , player
	map = map_cfg->map;
	data[1] = 0;
	data[2] = 0;
	while (map[data[1]])
	{
		data[0] = 0;
		while (map[data[1]][data[0]])
		{
			if (map[data[1]][data[0]] == '0' || ft_strchr("NSEW",
														  map[data[1]][data[0]]))
			{
				if (!is_pos_closed(map, data[1], data[0]))
				{
					puts("closed");
					return (0);
				}
				if (ft_strchr("NSEW", map[data[1]][data[0]]))
				{
					if (data[2])
						return (0);
					data[2] = 1;
					map_cfg->map_y = data[1];
					map_cfg->map_x = data[0];
					map_cfg->player_y = data[1] * TILE_SIZE;
					map_cfg->player_x = data[0] * TILE_SIZE;
					map_cfg->player_dir = map[data[1]][data[0]];
				}
			}
			else if (map[data[1]][data[0]] != '1' && map[data[1]][data[0]] != ' ')
			{
				puts("here");
				return (0);
			}
			data[0]++;
		}
		data[1]++;
	}
	return (data[2]);
}

int handle_error_input(int ac, char **av, t_map_config *cf)
{
	int fd;

	if (ac != 2)
		return (ft_putendl_fd("Usage: ./cub3D path_to_map", 2), 1);
	if (!valid_file_ext(av[1]))
		ft_putstr_fd("Invalid file extension", 2);
	init_map_config(cf);
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		return (ft_putstr_fd("Error: Invalid file", 2), 1);
	if (!get_content(fd, cf, av))
		return (ft_putstr_fd("Error: Invalid file", 2), 1);
	if (!valid_map(cf))
		return (ft_putstr_fd("Invalid map config", 2), 1);
	if (!cf->has_no || !cf->has_so || !cf->has_we || !cf->has_ea || !cf->has_floor || !cf->has_ceiling)
		return (ft_putstr_fd("Missing config", 2), 1);
	set_player_angle(cf);
	return (0);
}
