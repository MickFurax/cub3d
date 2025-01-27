/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabeman <arabeman@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 15:40:14 by arabeman          #+#    #+#             */
/*   Updated: 2025/01/27 17:03:03 by arabeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
#define STRUCT_H

#include <stdbool.h>

typedef struct s_color
{
    int r;
    int g;
    int b;
} t_color;

typedef struct s_key
{
    bool forward;
    bool backward;
    bool right;
    bool left;
    bool turn_left;
    bool turn_right;
} t_key;

typedef struct s_map_config
{
    char *no_texture;
    char *so_texture;
    char *we_texture;
    char *ea_texture;
    t_color floor_c;
    t_color ceiling_c;
    char **map;
    int height;
    int width;
    double player_x;
    double player_y;
    double player_angle;
    char player_dir;
    int has_no;
    int has_so;
    int has_we;
    int has_ea;
    int has_floor;
    int has_ceiling;
} t_map_config;

typedef struct s_framebuffer
{
    void *img;
    char *addr;
    int bpp;
    int line_length;
    int endian;
} t_framebuffer;

typedef struct s_data
{
    void *mlx;
    void *win;
    t_framebuffer *framebuff;
    t_map_config *map_config;
    t_key key;
} t_data;

#endif