/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_minimap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabeman <arabeman@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 17:16:21 by arabeman          #+#    #+#             */
/*   Updated: 2025/01/23 11:24:17 by arabeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cub3d.h"
#include <time.h>
#include <sys/time.h>

int render_minimap(t_data *data)
{
    t_minimap *minimap = data->minimap;
    move_player(minimap);
    clear_minimap(data, data->minimap->player_img);
    draw_minimap(data, minimap->x, minimap->y);
    mlx_put_image_to_window(minimap->mlx, minimap->win, minimap->player_img.img_ptr, CENTER, CENTER);
    mlx_put_image_to_window(minimap->mlx, minimap->win, minimap->minimap_img.img_ptr, 0, 0);
    return 0;
}

int render_and_show_fps(t_data *data)
{
    static bool initialized = false;
    static struct timeval last_time;
    static double time_taken;
    struct timeval current_time;

    t_minimap *minimap = data->minimap;
    move_player(minimap);
    clear_minimap(data, data->minimap->player_img);
    if (!initialized)
    {
        gettimeofday(&last_time, NULL);
        initialized = true;
        time_taken = 0;
    }
    else
    {
        gettimeofday(&current_time, NULL);
        time_taken = (current_time.tv_sec - last_time.tv_sec) +
                     (current_time.tv_usec - last_time.tv_usec) / 1000000.0;
        last_time = current_time;
    }
    ft_putstr_fd("FPS: ", 1);
    ft_putnbr_fd(1.0 / time_taken, 1);
    ft_putchar_fd('\n', 1);
    draw_minimap(data, minimap->x, minimap->y);
    usleep(1000);
    mlx_put_image_to_window(minimap->mlx, minimap->win, minimap->player_img.img_ptr, CENTER, CENTER);
    mlx_put_image_to_window(minimap->mlx, minimap->win, minimap->minimap_img.img_ptr, 0, 0);
    return 0;
}
