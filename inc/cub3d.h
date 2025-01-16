/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabeman <arabeman@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 13:23:49 by arabeman          #+#    #+#             */
/*   Updated: 2025/01/16 10:42:59 by arabeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

#define PXL_PER_PXL 32

#define MINIMAP_WIDTH PXL_PER_PXL * 8
// # define MINIMAP_WIDTH PXL_PER_PXL * 16
#define MINIMAP_HEIGHT PXL_PER_PXL * 8
// # define MINIMAP_HEIGHT PXL_PER_PXL * 16

#define CENTER PXL_PER_PXL * 3.5f
#define MAIN_COLOR 0xD0D4E4

#define W 119
#define A 97
#define S 115
#define D 100
#define Q 113
#define UP 65362
#define DOWN 65364
#define LEFT 65361
#define RIGHT 65363

#define π 3.141592653589793
#define PI 3.141592653589793

#include "struct.h"
#include <math.h>
#include <stdio.h>

void print_hello_world(void);

#endif