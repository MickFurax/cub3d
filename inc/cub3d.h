/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabeman <arabeman@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 00:53:28 by mrabenja          #+#    #+#             */
/*   Updated: 2025/01/27 11:17:34 by arabeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>

# define WIN_WIDTH 800
# define WIN_HEIGHT 600
# define FOV_ANGLE (M_PI / 3) //60 degrees
# define TILE_SIZE 64

typedef struct s_color
{
	int				r;
	int				g;
	int				b;
}					t_color;

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
	double			player_angle;
	char			player_dir;
	int				has_no;
	int				has_so;
	int				has_we;
	int				has_ea;
	int				has_floor;
	int				has_ceiling;
}					t_map_config;

typedef struct s_framebuffer
{
	void			*img;
	char			*addr;
	int				bpp;
	int				line_length;
	int				endian;
}					t_framebuffer;

typedef struct s_mlx
{
	void			*mlx;
	void			*win;
	t_framebuffer	*framebuff;
}					t_mlx;

// parsing
int					parse_rgb_color(char *str, t_color *color);
int					valid_file_ext(char *file_name);
void				print_hello_world(void);
char				**ft_split_wsp(char const *s);
int					parse_id_line(char *line, t_map_config *config);
int					is_valid_char(char c);
int					handle_error_input(int ac, char **av);
void				init_map_config(t_map_config *map_cf);

// window
void				start_win(t_mlx *m);
void				cleanup(t_mlx *m);

#endif