/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabeman <arabeman@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 13:23:07 by arabeman          #+#    #+#             */
/*   Updated: 2025/01/23 11:02:48 by arabeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int main(int argc, char **argv)
{
	t_data data;

	init_data(&data, argc, argv);
	mlx_hook(data.minimap->win, 2, 1L << 0, key_press, data.minimap);
	mlx_hook(data.minimap->win, 3, 1L << 1, key_release, data.minimap);
	mlx_loop_hook(data.minimap->mlx, render_and_show_fps, &data);
	mlx_hook(data.minimap->win, 17, 0, mlx_loop_end, data.minimap->mlx);
	mlx_loop(data.minimap->mlx);
	free_data(&data);
	return (0);
}
