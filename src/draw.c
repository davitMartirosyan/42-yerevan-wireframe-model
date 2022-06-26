/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmartiro <dmartiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 02:17:54 by dmartiro          #+#    #+#             */
/*   Updated: 2022/06/26 07:21:11 by dmartiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"
static float  max(float a, float b) 
{
    return (a > b) ? a : b;
}
static float  pos(float n)
{
    return (n < 0 ) ? -n : n;
}
static void scale(t_axios *axios, float *x, float *y, float *x1, float *y1)
{
    *x *= axios->scale;
    *y *= axios->scale;
    *x1 *= axios->scale;
    *y1 *= axios->scale;
}

static void move(t_axios *axios, float *x, float *y, float *x1, float *y1)
{
    *x += axios->_x;
    *x1 += axios->_x;
    *y += axios->_y;
    *y1 += axios->_y;
}

void draw(float x, float y, float x1, float y1, t_axios *axios) //[1:1][3:12]
{
    float x_step;
    float y_step;
    int step;
    int z;
    int z1;
    
    z = axios->matrix[(int) y][(int) x];
    z1 = axios->matrix[(int) y1][(int) x1];
    scale(axios, &x, &y, &x1, &y1);
    axios->rgb = (z || z1) ? 0xffffff : axios->rgb;
    isometric(&x, &y, z);
    isometric(&x1, &y1, z1);
    move(axios, &x, &y, &x1, &y1);
    x_step = x1 - x; // 2 
    y_step = y1 - y; // 11
    step = max(pos(x_step), pos(y_step));
    x_step /= step;
    y_step /= step;
    while((int)(x - x1) || (int)(y - y1))
    {
        mlx_pixel_put(axios->mlx, axios->mlx_win, x, y, axios->rgb);
        x += x_step;
        y += y_step;
    }
}