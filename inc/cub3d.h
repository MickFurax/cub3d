/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabeman <arabeman@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 00:53:28 by mrabenja          #+#    #+#             */
/*   Updated: 2025/02/14 15:44:52 by arabeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

#include "../libft/libft.h"
#include "../minilibx-linux/mlx.h"
#include "const.h"
#include "struct.h"
#include <fcntl.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>

// parsing
int parse_rgb_color(char *str, t_color *color);
int valid_file_ext(char *file_name);
char **ft_split_wsp(char const *s);
int parse_id_line(char *line, t_map_config *config);
int is_valid_char(char c);
int handle_error_input(int ac, char **av, t_map_config *cf);
void init_map_config(t_map_config *map_cf);
void free_map_config(t_map_config *config);

// window
void start_win(t_data *m);
void cleanup(t_data *m);

// key
int key_press(int keycode, t_data *data);
int key_release(int keycode, t_data *data);

// angle
void set_player_angle(t_map_config *cf);
void reset_angle(double *ray_angle);

// ray
bool has_wall_at(t_data *data, int x, int y);
int cast_ray(t_map_config *cf, int col, double *ray_dst);
void render_frame(t_data *data);
void move_player(t_data *data);
void ft_mlx_pixel_put(t_framebuffer *img, int x, int y,
					  unsigned int color);
void init_ray_data(t_ray_data *rd);
void render_background(t_data *data);
int cast_ray2(t_map_config *cf, int col, double *ray_dst,
			  t_ray_data *rd);

// wall
void calculate_wall_bound(double ray_dist, int *draw_start,
						  int *draw_end);
void put_pixel(char *addr, int pix_idx, int color);
void render_wall(int col, double ray_dist, char *addr, int side);

// textures
void load_textures(t_data *data);
void set_texture_data(t_data *data);
void free_textures(t_data *data);
t_texture *get_wall_txt(t_data *data, t_ray_data *rd);
int get_texture_pxl(t_texture *txt, int x, int y);
void render_textured_wall(int col, double ray_dist, t_data *data,
						  t_ray_data *rd);

// minimap
void init_minimap(t_data *data);
int render_minimap(t_data *data);
void render_img_minimap(t_data *data, t_img img, int x, int y);
void put_pixel_minimap(t_minimap *minimap, int x, int y, int color);
void render_wall_minimap(t_data *data, int x, int y);
void	move_player_minimap(t_data *data, float speed);

#endif