/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   angle.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabenja <mrabenja@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 10:50:03 by mrabenja          #+#    #+#             */
/*   Updated: 2025/01/29 15:01:52 by mrabenja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	reset_angle(double *ray_angle)
{
	if (*ray_angle < 0)
		*ray_angle += 2 * M_PI;
	if (*ray_angle > 2 * M_PI)
		*ray_angle -= 2 * M_PI;
}

void	set_player_angle(t_map_config *cf)
{
	if (cf->player_dir == 'N')
		cf->player_angle = M_PI / 2;
	else if (cf->player_dir == 'S')
		cf->player_angle = -M_PI / 2;
	else if (cf->player_dir == 'E')
		cf->player_angle = 0;
	else if (cf->player_dir == 'W')
		cf->player_angle = M_PI;
}
