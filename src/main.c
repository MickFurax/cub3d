/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabenja <mrabenja@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 13:23:07 by arabeman          #+#    #+#             */
/*   Updated: 2025/01/28 13:04:05 by mrabenja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"
#include "../libft/libft.h"
#include "../minilibx-linux/mlx.h"

int main(int ac, char **av)
{
    t_data data;
    t_map_config cf;
    if (handle_error_input(ac, av, &cf))
        return (1);
    data.map_config = &cf;
    printf("Configuration file parsed successfully!\n");
    start_win(&data);
    cleanup(&data);
    return (0);
}
