/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabeman <arabeman@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 13:11:21 by arabeman          #+#    #+#             */
/*   Updated: 2025/01/15 16:54:21 by arabeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
#define STRUCT_H

typedef struct s_img
{
	void *img_ptr;
	char *addr;
	int bits_per_pixel;
	int size_line;
	int endian;
} t_img;

typedef struct s_minimap
{
	char **map;
	void *mlx;
	void *win;
	char *addr;
	void *img_ptr;
	int bits_per_pixel;
	int size_line;
	int endian;
} t_minimap;

typedef struct s_data
{
	char **map;
	t_minimap *minimap;
	int player_pos[2];
} t_data;

#endif
