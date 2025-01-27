/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabeman <arabeman@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 13:20:55 by mrabenja          #+#    #+#             */
/*   Updated: 2025/01/27 15:38:23 by arabeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static void	create_framebuff(t_data *m)
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
void	start_win(t_data *m)
{
	m->mlx = mlx_init();
	m->win = mlx_new_window(m->mlx, WIN_WIDTH, WIN_HEIGHT, "Cub3D");
	create_framebuff(m);
	mlx_hook(m->win, 2, 1L << 0, key_press, m);
	mlx_hook(m->win, 3, 1L << 1, key_release, m);
	mlx_hook(m->win, 17, 0, mlx_loop_end, m->mlx);
	mlx_loop(m->mlx);
}

void	cleanup(t_data *m)
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
