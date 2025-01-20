/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabeman <arabeman@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 13:23:49 by arabeman          #+#    #+#             */
/*   Updated: 2025/01/17 18:52:52 by arabeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

#include "struct.h"
#include "const.h"
#include "../libft/libft.h"
#include "../minilibx-linux/mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//* data
void init_data(t_data *data, int argc, char **argv);
void free_data(t_data *data);
t_data	*get_data(void);
void	set_data(t_data *data);

//* map
void set_map(t_data *data);
void init_minimap(t_data *data);
void free_minimap(t_data *data);

#endif