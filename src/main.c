/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabenja <mrabenja@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 13:23:07 by arabeman          #+#    #+#             */
/*   Updated: 2025/02/07 12:28:46 by mrabenja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"
#include "../libft/libft.h"
#include "../minilibx-linux/mlx.h"

void init_key(t_data *data);

static int gameloop(t_data *data)
{
    move_player(data);
    render_frame(data);
    return (0);
}

int main(int ac, char **av)
{
    t_data data;
    t_map_config cf;
    if (handle_error_input(ac, av, &cf))
        return (1);
    data.map_config = &cf;
    init_key(&data);
    printf("Configuration file parsed successfully!\n");
    start_win(&data);
    mlx_loop_hook(data.mlx, gameloop, &data);
    mlx_loop(data.mlx);
    cleanup(&data);
    return (0);
}

void init_key(t_data *data)
{
    data->key.forward = false;
    data->key.backward = false;
    data->key.left = false;
    data->key.right = false;
    data->key.turn_left = false;
    data->key.turn_right = false;
}
