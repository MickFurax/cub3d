/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabenja <mrabenja@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 13:23:07 by arabeman          #+#    #+#             */
/*   Updated: 2025/02/03 12:54:09 by mrabenja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"
#include "../libft/libft.h"
#include "../minilibx-linux/mlx.h"

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
    printf("Configuration file parsed successfully!\n");
    start_win(&data);
    mlx_loop_hook(data.mlx, gameloop, &data);
    mlx_loop(data.mlx);
    cleanup(&data);
    return (0);
}
