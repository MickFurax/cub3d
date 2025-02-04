/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   const.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabeman <arabeman@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 15:41:24 by arabeman          #+#    #+#             */
/*   Updated: 2025/02/04 14:35:59 by arabeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONST_H
#define CONST_H

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

#define WIN_WIDTH 800
#define WIN_HEIGHT 600
#define FOV_ANGLE (M_PI / 3) // 60 degrees
#define TILE_SIZE 64

// player config
#define MOVE_SPEED 0.1
#define ROTA_SPEED 0.001
#define DIAGONAL_SPEED (0.07 * MOVE_SPEED) / 0.1

// keycode
#define W 119
#define A 97
#define S 115
#define D 100
#define Q 113
#define ESC 65307
#define UP 65362
#define DOWN 65364
#define LEFT 65361
#define RIGHT 65363

#endif