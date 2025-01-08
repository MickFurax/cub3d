/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabeman <arabeman@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 13:23:07 by arabeman          #+#    #+#             */
/*   Updated: 2025/01/08 13:27:39 by arabeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"
#include "../libft/libft.h"
#include "../minilibx-linux/mlx.h"

int main(int argc, char **argv)
{
    (void)argc;
    (void)argv;
    print_hello_world();
    ft_putstr_fd("Using libft function: Hello World!\n", 1);

    void *mlx;
    void *mlx_win;

    mlx = mlx_init();
    mlx_win = mlx_new_window(mlx, 1920 / 2, 1080 / 2, "Hello world!");
    sleep(2);
    mlx_destroy_window(mlx, mlx_win);
    mlx_destroy_display(mlx);
    free(mlx);
    (void)mlx_win;
    char *gnl_test = get_next_line(0);
    ft_putstr_fd(gnl_test, 1);
    free(gnl_test);
    return (0);
}
