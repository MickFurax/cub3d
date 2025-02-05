/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabenja <mrabenja@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 13:20:55 by mrabenja          #+#    #+#             */
/*   Updated: 2025/02/05 15:19:26 by mrabenja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static void create_framebuff(t_data *m)
{
	m->framebuff = malloc(sizeof(t_framebuffer));
	if (!m->framebuff)
	{
		ft_putstr_fd("Error allocating framebuffer", 2);
		cleanup(m);
		exit(EXIT_FAILURE);
	}
	m->framebuff->img = mlx_new_image(m->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!m->framebuff->img)
	{
		ft_putstr_fd("Error creating image", 2);
		cleanup(m);
		exit(EXIT_FAILURE);
	}
	m->framebuff->addr = mlx_get_data_addr(m->framebuff->img,
										   &m->framebuff->bpp, &m->framebuff->line_length,
										   &m->framebuff->endian);
}
void start_win(t_data *m)
{
	m->mlx = mlx_init();
	m->win = mlx_new_window(m->mlx, WIN_WIDTH, WIN_HEIGHT, "Cub3D");
	create_framebuff(m);
	mlx_hook(m->win, 2, 1L << 0, key_press, m);
	mlx_hook(m->win, 3, 1L << 1, key_release, m);
	mlx_hook(m->win, 17, 0, mlx_loop_end, m->mlx);
}

void cleanup(t_data *data)
{
	if (data->framebuff)
	{
		if (data->framebuff->img)
			mlx_destroy_image(data->mlx, data->framebuff->img);
		free(data->framebuff);
	}
	if (data->win)
	{
		mlx_destroy_window(data->mlx, data->win);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	free_map_config(data->map_config);
	free_textures(data);
}
