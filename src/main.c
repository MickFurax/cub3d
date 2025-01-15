/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabeman <arabeman@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 13:23:07 by arabeman          #+#    #+#             */
/*   Updated: 2025/01/15 17:39:09 by arabeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"
#include "../libft/libft.h"
#include "../minilibx-linux/mlx.h"

//* map
void set_map(t_data *data);
void unset_map(t_data *data);
void set_minimap(t_data *data);
void unset_minimap(t_data *data);
void draw_map(t_data *data);

//* draw
void put_pixel(t_data *data, int x, int y, int color);
void draw_square(t_data *data, int x, int y);

//* image
t_img new_image(void *mlx, char *path);
unsigned int get_pixel_img(t_img img, int x, int y);
void put_img(t_data *data, t_img img, int x, int y);

//* player
void set_player_pos(t_data *data);

int main(int argc, char **argv)
{
	t_data data;
	t_img player;

	(void)argc;
	(void)argv;
	set_map(&data);
	set_minimap(&data);
	set_player_pos(&data);
	data.minimap->img_ptr = mlx_new_image(data.minimap->mlx, MINIMAP_WIDTH, MINIMAP_HEIGHT);
	data.minimap->addr = mlx_get_data_addr(data.minimap->img_ptr, &data.minimap->bits_per_pixel, &data.minimap->size_line, &data.minimap->endian);
	// ************************* //
	player = new_image(data.minimap->mlx, "asset/minimap/player.xpm");
	draw_map(&data);
	put_img(&data, player, CENTER, CENTER);
	mlx_put_image_to_window(data.minimap->mlx, data.minimap->win, player.img_ptr, CENTER, CENTER);
	mlx_put_image_to_window(data.minimap->mlx, data.minimap->win, data.minimap->img_ptr, 0, 0);
	// ************************* //
	mlx_hook(data.minimap->win, 17, 0, mlx_loop_end, data.minimap->mlx);
	mlx_loop(data.minimap->mlx);
	unset_minimap(&data);
	unset_map(&data);
	return (0);
}

int get_wall_x(int player_x, int wall_x)
{
	return ((PXL_PER_PXL * wall_x) / player_x);
}

int get_wall_y(int player_y, int wall_y)
{
	return ((PXL_PER_PXL * wall_y) / player_y);
}

void draw_map(t_data *data)
{
	char **map = data->map;
	int player_x_i = data->player_pos[0];
	int player_y_i = data->player_pos[1];

	(void)map;
	(void)player_x_i;
	(void)player_y_i;
	printf("Player position: [%d, %d]\n", player_x_i, player_y_i);
	int x_i = 0;
	int y_i = 0;
	while (x_i < 8)
	{
		y_i = 0;
		while (y_i < 8)
		{
			if (map[x_i][y_i] == '1')
			{
				draw_square(data, get_wall_y(player_y_i, y_i) , get_wall_x(player_x_i, x_i));
			}
			y_i++;
		}
		x_i++;
	}
}

void set_player_pos(t_data *data)
{
	char **map = data->map;

	if (!map)
		return ;
	data->player_pos[0] = 0;
	data->player_pos[1] = 0;
	int i = 0;
	int j = 0;
	while (i < 8)
	{
		j = 0;
		while (j < 8)
		{
			if (map[i][j] == 'N')
			{
				data->player_pos[0] = i;
				data->player_pos[1] = j;
				map[i][j] = '0';
				return ;
			}
			j++;
		}
		i++;
	}
}

void draw_square(t_data *data, int x, int y)
{
	int i;

	i = 0;
	while (i < PXL_PER_PXL)
	{
		int j = 0;
		while (j < PXL_PER_PXL)
		{
			put_pixel(data, i + x, j + y, MAIN_COLOR);
			j++;
		}
		i++;
	}
}

t_img new_image(void *mlx, char *path)
{
	t_img image;
	int _;

	image.img_ptr = mlx_xpm_file_to_image(mlx, path, &_, &_);
	image.addr = mlx_get_data_addr(image.img_ptr, &image.bits_per_pixel, &image.size_line, &image.endian);
	return (image);
}

unsigned int get_pixel_img(t_img img, int x, int y)
{
	return (*(unsigned int *)((img.addr + (y * img.size_line) + (x * img.bits_per_pixel / 8))));
}

void put_img(t_data *data, t_img img, int x, int y)
{
	int i;
	int j;

	i = 0;
	while (i < PXL_PER_PXL)
	{
		j = 0;
		while (j < PXL_PER_PXL)
		{
			if (get_pixel_img(img, i, j) != 0xFF000000)
				put_pixel(data, x + i, y + j, get_pixel_img(img, i, j));
			j++;
		}
		i++;
	}
}

void put_pixel(t_data *data, int x, int y, int color)
{
	char *dst;

	if (x < 0 || y < 0 || x >= MINIMAP_WIDTH || y >= MINIMAP_HEIGHT)
		return;
	dst = data->minimap->addr + (y * data->minimap->size_line + x * (data->minimap->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void set_map(t_data *data)
{
	char **map;

	map = malloc(sizeof(char *) * 8);
	if (!map)
		return;
	map[0] = ft_strdup("11111111");
	map[1] = ft_strdup("1000N001");
	map[2] = ft_strdup("10000111");
	map[3] = ft_strdup("10000011");
	map[4] = ft_strdup("10110001");
	map[5] = ft_strdup("10000001");
	map[6] = ft_strdup("10100001");
	map[7] = ft_strdup("11111111");
	data->map = map;
}

void unset_map(t_data *data)
{
	char **map;

	map = data->map;
	if (map)
	{
		for (int i = 0; i < 8; i++)
			free(map[i]);
		free(map);
	}
}

void set_minimap(t_data *data)
{
	t_minimap *minimap;

	minimap = malloc(sizeof(t_minimap));
	if (!minimap)
		return;
	minimap->map = data->map;
	minimap->mlx = mlx_init();
	if (!minimap->mlx)
	{
		free(minimap);
		return;
	}
	minimap->win = mlx_new_window(minimap->mlx, MINIMAP_WIDTH, MINIMAP_HEIGHT, "Minimap");
	if (!minimap->win)
	{
		mlx_destroy_display(minimap->mlx);
		free(minimap->mlx);
		free(minimap);
		return;
	}
	data->minimap = minimap;
}

void unset_minimap(t_data *data)
{
	if (data->minimap)
	{
		if (data->minimap->win)
			mlx_destroy_window(data->minimap->mlx, data->minimap->win);
		if (data->minimap->mlx)
		{
			mlx_destroy_display(data->minimap->mlx);
			free(data->minimap->mlx);
		}
		free(data->minimap);
	}
}
