/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 22:36:49 by marvin            #+#    #+#             */
/*   Updated: 2022/06/30 22:36:49 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

float  max(float a, float b) 
{
    return (a > b) ? a : b;
}

float  pos(float n)
{
    return (n < 0 ) ? -n : n;
}

void scale(t_axios *axios, float *x, float *y)
{
    *x *= axios->scale;
    *y *= axios->scale;
}

void isometric(float *x, float *y, int z)
{
    *x = (*x - *y) * cos(0.8);
    *y = (*x + *y) * sin(0.8) - z;
}

void move(t_axios *axios, float *x, float *y, float *x1, float *y1)
{
    *x += axios->_x;
    *x1 += axios->_x;
    *y += axios->_y;
    *y1 += axios->_y;
}