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

static int rgb(t_axios *axios, int z, int z1)
{
    if(z || z1)
        return (0xffffff);
    else
        return (axios->rgb);
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
    scale(axios, &x, &y);
    scale(axios, &x1, &y1);
    axios->rgb = rgb(axiosm z, z1);
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