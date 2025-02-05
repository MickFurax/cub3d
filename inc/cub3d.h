/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabenja <mrabenja@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 00:53:28 by mrabenja          #+#    #+#             */
/*   Updated: 2025/02/05 15:16:53 by mrabenja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include "const.h"
# include "struct.h"
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>

// parsing
int			parse_rgb_color(char *str, t_color *color);
int			valid_file_ext(char *file_name);
void		print_hello_world(void);
char		**ft_split_wsp(char const *s);
int			parse_id_line(char *line, t_map_config *config);
int			is_valid_char(char c);
int			handle_error_input(int ac, char **av, t_map_config *cf);
void		init_map_config(t_map_config *map_cf);
void		free_map_config(t_map_config *config);

// window
void		start_win(t_data *m);
void		cleanup(t_data *m);

// key
int			key_press(int keycode, t_data *data);
int			key_release(int keycode, t_data *data);

// angle
void		set_player_angle(t_map_config *cf);
void		reset_angle(double *ray_angle);

// ray
bool		has_wall_at(t_data *data, int x, int y);
int			cast_ray(t_map_config *cf, int col, double *ray_dst);
void		render_wall(int col, double ray_dist, char *addr, int side);
void		render_frame(t_data *data);
void		move_player(t_data *data);
void		ft_mlx_pixel_put(t_framebuffer *img, int x, int y,
				unsigned int color);
void		render_background(t_data *data);

// textures
void		load_textures(t_data *data);
void		set_texture_data(t_data *data);
void		free_textures(t_data *data);
t_texture	*get_wall_txt(t_data *data, t_ray_data *rd);
int			get_texture_pxl(t_texture *txt, int x, int y);

#endif