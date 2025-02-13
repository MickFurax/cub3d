/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabenja <mrabenja@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 10:46:15 by mrabenja          #+#    #+#             */
/*   Updated: 2025/01/29 11:28:15 by mrabenja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	valid_file_ext(char *file_name)
{
	char	*tmp;

	tmp = ft_strrchr(file_name, '.');
	if (!tmp || ft_strncmp(tmp, ".cub", 4))
		return (0);
	return (1);
}

int	valid_texture_path(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (0);
	close(fd);
	return (1);
}

int	parse_rgb_color(char *str, t_color *color)
{
	char	**splitted;
	int		i;

	i = 0;
	splitted = ft_split(str, ',');
	if (!splitted[0] || !splitted[1] || !splitted[2])
	{
		tab_free(splitted);
		return (0);
	}
	color->r = ft_atoi(splitted[i++]);
	color->g = ft_atoi(splitted[i++]);
	color->b = ft_atoi(splitted[i++]);
	if (color->r < 0 || color->r > 255 || color->g < 0 || color->g > 255
		|| color->b < 0 || color->b > 255)
	{
		tab_free(splitted);
		return (0);
	}
	tab_free(splitted);
	return (1);
}

int	parse_id_line(char *line, t_map_config *config)
{
	char	**splitted;

	splitted = ft_split_wsp(line);
	if (!splitted || !splitted[0])
	{
		tab_free(splitted);
		return (0);
	}
	if (!ft_strcmp(splitted[0], "NO") && splitted[1])
	{
		config->no_texture = ft_strdup(splitted[1]);
		config->has_no = valid_texture_path(splitted[1]);
	}
	else if (!ft_strcmp(splitted[0], "SO") && splitted[1])
	{
		config->so_texture = ft_strdup(splitted[1]);
		config->has_so = valid_texture_path(splitted[1]);
	}
	else if (!ft_strcmp(splitted[0], "EA") && splitted[1])
	{
		config->ea_texture = ft_strdup(splitted[1]);
		config->has_ea = valid_texture_path(splitted[1]);
	}
	else if (!ft_strcmp(splitted[0], "WE") && splitted[1])
	{
		config->we_texture = ft_strdup(splitted[1]);
		config->has_we = valid_texture_path(splitted[1]);
	}
	else if (!ft_strcmp(splitted[0], "F") && splitted[1])
		config->has_floor = parse_rgb_color(splitted[1], &config->floor_c);
	else if (!ft_strcmp(splitted[0], "C") && splitted[1])
		config->has_ceiling = parse_rgb_color(splitted[1], &config->ceiling_c);
	tab_free(splitted);
	return (1);
}
void	init_map_config(t_map_config *map_cf)
{
	map_cf->no_texture = NULL;
	map_cf->so_texture = NULL;
	map_cf->we_texture = NULL;
	map_cf->ea_texture = NULL;
	map_cf->floor_c.r = -1;
	map_cf->floor_c.g = -1;
	map_cf->floor_c.b = -1;
	map_cf->ceiling_c.r = -1;
	map_cf->ceiling_c.g = -1;
	map_cf->ceiling_c.b = -1;
	map_cf->map = NULL;
	map_cf->height = 0;
	map_cf->width = 0;
	map_cf->player_x = -1;
	map_cf->player_y = -1;
	map_cf->player_dir = 0;
	map_cf->has_no = 0;
	map_cf->has_so = 0;
	map_cf->has_we = 0;
	map_cf->has_ea = 0;
	map_cf->has_floor = 0;
	map_cf->has_ceiling = 0;
	map_cf->map_x = 0;
	map_cf->map_y = 0;
}

int	is_valid_char(char c)
{
	return (c == '0' || c == '1' || c == 'N' || c == 'S' || c == 'E' || c == 'W'
		|| c == ' ');
}
