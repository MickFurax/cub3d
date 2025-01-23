/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabeman <arabeman@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 18:10:02 by arabeman          #+#    #+#             */
/*   Updated: 2025/01/23 11:13:38 by arabeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void move_player(t_minimap *minimap)
{
    float speed = SPEED;
    float diagonal_speed = (0.07f * speed) / 0.1f;
    double cos_angle = cos(minimap->player_img.angle);
    double sin_angle = sin(minimap->player_img.angle);

    if (minimap->key_up && minimap->key_right)
    {
        minimap->y -= diagonal_speed;
        minimap->x += diagonal_speed;
    }
    else if (minimap->key_up && minimap->key_left)
    {
        minimap->x += diagonal_speed;
        minimap->y += diagonal_speed;
    }
    else if (minimap->key_down && minimap->key_right)
    {
        minimap->y -= diagonal_speed;
        minimap->x -= diagonal_speed;
    }
    else if (minimap->key_down && minimap->key_left)
    {
        minimap->x -= diagonal_speed;
        minimap->y += diagonal_speed;
    }
    else if (minimap->key_up)
        minimap->x += speed;
    else if (minimap->key_down)
        minimap->x -= speed;
    else if (minimap->key_left)
        minimap->y += speed;
    else if (minimap->key_right)
        minimap->y -= speed;
    if (minimap->turn_left)
        minimap->player_img.angle -= speed / 10;
    if (minimap->turn_right)
        minimap->player_img.angle += speed / 10;
    if (minimap->forward)
    {
        minimap->x += cos_angle * speed;
        minimap->y -= sin_angle * speed;
    }
    if (minimap->backward)
    {
        minimap->x -= cos_angle * speed;
        minimap->y += sin_angle * speed;
    }
}

int key_press(int keycode, t_minimap *minimap)
{
    if (keycode == W)
        minimap->key_up = true;
    if (keycode == S)
        minimap->key_down = true;
    if (keycode == A)
        minimap->key_left = true;
    if (keycode == D)
        minimap->key_right = true;
    if (keycode == LEFT)
        minimap->turn_left = true;
    if (keycode == RIGHT)
        minimap->turn_right = true;
    if (keycode == UP)
        minimap->forward = true;
    if (keycode == DOWN)
        minimap->backward = true;
    if (keycode == Q || keycode == ESC)
        mlx_loop_end(minimap->mlx);
    return (0);
}

int key_release(int keycode, t_minimap *minimap)
{
    if (keycode == W)
        minimap->key_up = false;
    if (keycode == S)
        minimap->key_down = false;
    if (keycode == A)
        minimap->key_left = false;
    if (keycode == D)
        minimap->key_right = false;
    if (keycode == LEFT)
        minimap->turn_left = false;
    if (keycode == RIGHT)
        minimap->turn_right = false;
    if (keycode == UP)
        minimap->forward = false;
    if (keycode == DOWN)
        minimap->backward = false;
    return (0);
}
