/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmartiro <dmartiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 02:54:51 by dmartiro          #+#    #+#             */
/*   Updated: 2022/06/14 05:55:32 by dmartiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

float max(float a, float b)
{
    return (a > b ? a : b);
} 

float mod(float i)
{
    return (i < 0) ? -i : i;
}

void isometric(float *x, float *y, int z)
{
    *x = (*x - *y) * cos(0.8);
    *y = (*x + *y) * sin(0.8) - z;
}

void drawing(float x, float y, float x1, float y1, t_axios *matrix)
{
    // [1, 1][3, 12]
    float x_step;
    float y_step; 
    int m;
    int z;
    int z1;
    
    z = matrix->matrix[(int)y][(int)x];
    z1 = matrix->matrix[(int)y1][(int)x1];
    
    x *= matrix->scale;
    y *= matrix->scale;
    x1 *= matrix->scale;
    y1 *= matrix->scale;

    matrix->rgb = (z || z1) ? 0xff0000 : 0xffffff;
    isometric(&x, &y, z);
    isometric(&x1, &y1, z1);

    x += 250;
    y += 250;
    x1 += 250;
    y1 += 250;
    x_step = x1 - x; // 3  - 1 = 2
    y_step = y1 - y; // 12 - 1 = 11
    m = max(mod(x_step), mod(y_step));
    x_step /= m;
    y_step /= m;
    while((int)(x - x1) || (int)(y - y1))
    {
       mlx_pixel_put(matrix->mlx, matrix->mlx_win, x, y, matrix->rgb);
       x += x_step;
       y += y_step;
    }
}

void map(t_axios *matrix)
{
    int x;
    int y;

    y = 0;
    while(y < matrix->height)
    {
        x = 0;
        while(x < matrix->width)
        {
            if(x < matrix->width - 1)
                drawing(x, y, x + 1, y, matrix);
            if(y < matrix->height - 1)
                drawing(x, y, x, y + 1, matrix);
            x++;
        }
        y++;
    }
}