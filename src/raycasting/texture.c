/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabenja <mrabenja@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 13:00:22 by mrabenja          #+#    #+#             */
/*   Updated: 2025/02/05 15:12:45 by mrabenja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	load_textures(t_data *data)
{
	t_texture		*txt;
	t_map_config	*cfg;

	txt = data->textures;
	cfg = data->map_config;
	set_width_height(data->textures);
	txt[north].img = mlx_xpm_file_to_image(data->mlx, cfg->no_texture,
			txt[north].width, txt[north].height);
	txt[south].img = mlx_xpm_file_to_image(data->mlx, cfg->so_texture,
			txt[south].width, txt[south].height);
	txt[east].img = mlx_xpm_file_to_image(data->mlx, cfg->ea_texture,
			txt[east].width, txt[east].height);
	txt[west].img = mlx_xpm_file_to_image(data->mlx, cfg->we_texture,
			txt[west].width, txt[west].height);
	if (!data->textures[north].img || !data->textures[south].img
		|| !data->textures[east].img || !data->textures[west].img)
	{
		ft_putstr_fd("Failed to load texture\n", 2);
		cleanup(data);
		exit(EXIT_FAILURE);
	}
}

void	set_texture_data(t_data *data)
{
	t_texture	*txt;
	int 		i;

	i = -1;
	txt = data->textures;

	while (++i < 4)
		txt[i].addr = mlx_get_data_addr(txt[i].img, txt[i].bpp,
				txt[i].line_length, txt[i].endian);
}

void	free_textures(t_data *data)
{
	t_texture	*txt;
	int 		i;

	i = -1;
	txt = data->textures;
	while (++i < 4)
		if (txt[i].img)
			mlx_destroy_image(data->mlx, txt[i].img);
}
//FIXIT
t_texture 	*get_wall_txt(t_data *data, t_ray_data *rd)
{
	if (rd->side == 0) //vertical
	{
		if (rd->step_x > 0)
			return (&data->textures[west]);
		else
			return (&data->textures[east]);
	}
	else if (rd->side == 1) //horizontal
	{
		if (rd->step_y > 0)
			return (&data->textures[north]);
		else
			return (&data->textures[south]);
	}
}

int	get_texture_pxl(t_texture *txt, int x, int y)
{
	char *res;
	
	if (x < 0 || y < 0 || x >= WIN_WIDTH || y >= WIN_HEIGHT)
		return;
	res = txt->addr + (y * txt->line_length + x * (txt->bpp / 8));
	return(*(unsigned int *)res);
}