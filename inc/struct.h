/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabeman <arabeman@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 11:03:15 by arabeman          #+#    #+#             */
/*   Updated: 2025/01/24 10:06:32 by arabeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
#define STRUCT_H

#include <stdbool.h>

typedef struct s_img
{
	void *img_ptr;
	char *addr;
	int bits_per_pixel;
	int size_line;
	int endian;
	double angle;
} t_img;

typedef struct s_minimap
{
	char **map;
	void *mlx;
	void *win;

	t_img minimap_img;
	t_img player_img;

	float x;
	float y;

	bool key_up;
	bool key_down;
	bool key_right;
	bool key_left;

	bool turn_left;
	bool turn_right;
} t_minimap;

typedef struct s_data
{
	char **map;
	t_minimap *minimap;
	int player_index[2];
} t_data;

#endif
