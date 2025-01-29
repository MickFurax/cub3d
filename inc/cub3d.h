/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabenja <mrabenja@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 00:53:28 by mrabenja          #+#    #+#             */
/*   Updated: 2025/01/29 13:44:38 by mrabenja         ###   ########.fr       */
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
int		parse_rgb_color(char *str, t_color *color);
int		valid_file_ext(char *file_name);
void	print_hello_world(void);
char	**ft_split_wsp(char const *s);
int		parse_id_line(char *line, t_map_config *config);
int		is_valid_char(char c);
int		handle_error_input(int ac, char **av, t_map_config *cf);
void	init_map_config(t_map_config *map_cf);
void	free_map_config(t_map_config *config);

// window
void	start_win(t_data *m);
void	cleanup(t_data *m);

// key
int		key_press(int keycode, t_data *data);
int		key_release(int keycode, t_data *data);

// angle
void	set_player_angle(t_map_config *cf);
void	reset_angle(double *ray_angle);

#endif