/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabenja <mrabenja@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 13:20:55 by mrabenja          #+#    #+#             */
/*   Updated: 2025/01/24 13:51:48 by mrabenja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static void	create_framebuff(t_mlx *m)
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
		// free(m->framebuff);
		cleanup(m);
		exit(EXIT_FAILURE);
	}
	m->framebuff->addr = mlx_get_data_addr(m->framebuff->img,
			&m->framebuff->bpp, &m->framebuff->line_length,
			&m->framebuff->endian);
}
void	start_win(t_mlx *m)
{
	m->mlx = mlx_init();
	m->win = mlx_new_window(m->mlx, WIN_WIDTH, WIN_HEIGHT, "Cub3D");
	create_framebuff(m);
	mlx_loop(m->mlx);
}

void	cleanup(t_mlx *m)
{
	if (m->framebuff)
	{
		if (m->framebuff->img)
			mlx_destroy_image(m->mlx, m->framebuff->img);
		free(m->framebuff);
	}
	if (m->win)
		mlx_destroy_window(m->mlx, m->win);
}
