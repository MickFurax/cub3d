/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabeman <arabeman@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 13:23:49 by arabeman          #+#    #+#             */
/*   Updated: 2025/01/15 17:29:59 by arabeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define PXL_PER_PXL 32

# define MINIMAP_WIDTH PXL_PER_PXL * 8
// # define MINIMAP_WIDTH PXL_PER_PXL * 16
# define MINIMAP_HEIGHT PXL_PER_PXL * 8
// # define MINIMAP_HEIGHT PXL_PER_PXL * 16

# define CENTER PXL_PER_PXL * 3.5f 
# define MAIN_COLOR 0xD0D4E4

# include "struct.h"
# include <math.h>
# include <stdio.h>

void	print_hello_world(void);

#endif