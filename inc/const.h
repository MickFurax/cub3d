/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   const.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabeman <arabeman@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 15:41:24 by arabeman          #+#    #+#             */
/*   Updated: 2025/02/14 15:36:40 by arabeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONST_H
# define CONST_H

# ifndef M_PI
#  define M_PI 3.14159265358979323846
# endif

# define WIN_WIDTH 800
# define WIN_HEIGHT 600
# define FOV_ANGLE (M_PI / 3) // 60 degrees
# define TILE_SIZE 32

# define MINIMAP_TILE 32
# define MINIMAP_W MINIMAP_TILE * 8 / 2
# define MINIMAP_H MINIMAP_TILE * 8 / 2
# define MINIMAP_CENTER MINIMAP_TILE * 4 / 2
# define PLAYER_POS MINIMAP_TILE * 3.0f / 2.0f
# define MINIMAP_COLOR 0xD0D4E4
# define BORDER_COLOR 0x65DFC1

// player config
# define MOVE_SPEED 0.1
# define ROTA_SPEED 0.0025
# define DIAGONAL_SPEED (0.07 * MOVE_SPEED) / 0.1

// keycode
# define W 119
# define A 97
# define S 115
# define D 100
# define Q 113
# define ESC 65307
# define UP 65362
# define DOWN 65364
# define LEFT 65361
# define RIGHT 65363

// enum direction
enum	e_direct
{
	north,
	south,
	east,
	west
};

#endif