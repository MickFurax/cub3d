/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabenja <mrabenja@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 15:40:14 by arabeman          #+#    #+#             */
/*   Updated: 2025/02/12 15:37:59 by mrabenja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include <stdbool.h>

typedef struct s_color
{
	int				r;
	int				g;
	int				b;
}					t_color;

typedef struct s_key
{
	bool			forward;
	bool			backward;
	bool			right;
	bool			left;
	bool			turn_left;
	bool			turn_right;
}					t_key;

typedef struct s_map_config
{
	char			*no_texture;
	char			*so_texture;
	char			*we_texture;
	char			*ea_texture;
	t_color			floor_c;
	t_color			ceiling_c;
	char			**map;
	int				height;
	int				width;
	double			player_x;
	double			player_y;
	int				map_x;
	int				map_y;
	double			player_angle;
	char			player_dir;
	int				has_no;
	int				has_so;
	int				has_we;
	int				has_ea;
	int				has_floor;
	int				has_ceiling;
}					t_map_config;

typedef struct s_ray_data
{
	double ray_x; // ray at the player position
	double ray_y; // ray at the player position
	double			delta_x;
	double			delta_y;
	int				step_x;
	int				step_y;
	double			side_dist_x;
	double			side_dist_y;
	int				hit;
	int				side;
	double			ray_angle;
	double			corrected_fisheye;
}					t_ray_data;

typedef struct s_framebuffer // for the whole screeen
{
	void *img;  // image buffer created by mlx_new_image
	char *addr; // data of each pixel inside img
	int bpp;    // 32
	int line_length;
	int endian; // rgba or bgra
}					t_framebuffer;

typedef struct s_texture // for one texture in the screen
{
	void *img;
	char *addr;
	int bpp;
	int line_length;
	int endian;
	int width;
	int height;
}					t_texture;

typedef struct s_render_param
{
	double			line_height;
	int				draw_start;
	int				draw_end;
	int				tex_x;
	int				tex_y;
	double			step; // Calculate how much to increase the texture coordinate per screen pixel
	t_texture		*texture;
	double			tex_pos; // Starting texture coordinate
}					t_render_param;

typedef struct s_data
{
	void			*mlx;
	void			*win;
	t_framebuffer	*framebuff;
	t_map_config	*map_config;
	t_key			key;
	t_texture textures[4]; // should change for the bonus pt
}					t_data;

#endif