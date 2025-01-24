/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabeman <arabeman@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 18:10:02 by arabeman          #+#    #+#             */
/*   Updated: 2025/01/24 14:52:22 by arabeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void move_player(t_minimap *minimap)
{
    float speed = SPEED;
    float diagonal_speed = (0.07f * speed) / 0.1f;

    if ((minimap->key_up && (minimap->key_right || minimap->key_left)) || (minimap->key_down && (minimap->key_right || minimap->key_left)))
        speed = diagonal_speed;
    if (minimap->key_left && !minimap->key_right)
    {
        minimap->x += cos(minimap->player_img.angle - 90) * (speed / 2);
        minimap->y -= sin(minimap->player_img.angle - 90) * (speed / 2);
        minimap->x -= cos(minimap->player_img.angle + 90) * (speed / 2);
        minimap->y += sin(minimap->player_img.angle + 90) * (speed / 2);
    }
    else if (minimap->key_right && !minimap->key_left)
    {
        minimap->x += cos(minimap->player_img.angle + 90) * (speed / 2);
        minimap->y -= sin(minimap->player_img.angle + 90) * (speed / 2);
        minimap->x -= cos(minimap->player_img.angle - 90) * (speed / 2);
        minimap->y += sin(minimap->player_img.angle - 90) * (speed / 2);
    }
    if (minimap->turn_left)
    {
        if (minimap->player_img.angle )
        {
            /* code */
        }
        
        minimap->player_img.angle -= speed / 10;
    }
    if (minimap->turn_right)

    {
        minimap->player_img.angle += speed / 10;
    }
    if (minimap->key_up)
    {
        minimap->x += cos(minimap->player_img.angle) * speed;
        minimap->y -= sin(minimap->player_img.angle) * speed;
    }
    if (minimap->key_down)
    {
        minimap->x -= cos(minimap->player_img.angle) * speed;
        minimap->y += sin(minimap->player_img.angle) * speed;
    }
}

int key_press(int keycode, t_minimap *minimap)
{
    if (keycode == W || keycode == UP)
        minimap->key_up = true;
    if (keycode == S || keycode == DOWN)
        minimap->key_down = true;
    if (keycode == A)
        minimap->key_left = true;
    if (keycode == D)
        minimap->key_right = true;
    if (keycode == LEFT)
        minimap->turn_left = true;
    if (keycode == RIGHT)
        minimap->turn_right = true;
    if (keycode == Q || keycode == ESC)
        mlx_loop_end(minimap->mlx);
    return (0);
}

int key_release(int keycode, t_minimap *minimap)
{
    if (keycode == W || keycode == UP)
        minimap->key_up = false;
    if (keycode == S || keycode == DOWN)
        minimap->key_down = false;
    if (keycode == A)
        minimap->key_left = false;
    if (keycode == D)
        minimap->key_right = false;
    if (keycode == LEFT)
        minimap->turn_left = false;
    if (keycode == RIGHT)
        minimap->turn_right = false;
    return (0);
}
