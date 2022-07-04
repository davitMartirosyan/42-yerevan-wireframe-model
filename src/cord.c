/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cord.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmartiro <dmartiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 00:46:13 by dmartiro          #+#    #+#             */
/*   Updated: 2022/07/04 11:24:03 by dmartiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	isometric(float *x, float *y, int z)
{
	*x = (*x - *y) * cos(0.8);
	*y = (*x + *y) * sin(0.8) - z;
}

float	max(float a, float b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

float	pos(float n)
{
	if (n < 0)
		return (-n);
	else
		return (n);
}

void	scale(t_axios *axios, t_coords *coords)
{
	coords->x *= axios->scale;
	coords->y *= axios->scale;
	coords->x1 *= axios->scale;
	coords->y1 *= axios->scale;
}

void	move(t_axios *axios, t_coords *coords)
{
	coords->x += axios->_x;
	coords->x1 += axios->_x;
	coords->y += axios->_y;
	coords->y1 += axios->_y;
}
