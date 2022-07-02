/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cord.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmartiro <dmartiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 00:46:13 by dmartiro          #+#    #+#             */
/*   Updated: 2022/07/02 21:01:47 by dmartiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void isometric(float *x, float *y, int z)
{
    *x = (*x - *y) * cos(0.8);
    *y = (*x + *y) * sin(0.8) - z;
}

float  max(float a, float b) 
{
    if (a > b)
        return (a);
    else
        return (b);
}

float  pos(float n)
{
    if (n < 0)
        return (-n);
    else
        return (n);
}

void scale(t_axios *axios, float *x, float *y, float *x1, float *y1)
{
    *x *= axios->scale;
    *y *= axios->scale;
    *x1 *= axios->scale;
    *y1 *= axios->scale;
}

void move(t_axios *axios, float *x, float *y, float *x1, float *y1)
{
    *x += axios->_x;
    *x1 += axios->_x;
    *y += axios->_y;
    *y1 += axios->_y;
}