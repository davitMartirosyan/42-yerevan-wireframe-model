/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmartiro <dmartiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 02:17:54 by dmartiro          #+#    #+#             */
/*   Updated: 2022/07/04 11:24:33 by dmartiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	rgb(int z, int z1, int def)
{
	if (z || z1)
		return (0xffffff);
	else
		return (def);
}

void	draw(t_coords coords, t_axios *ax)
{
	float	x_step;
	float	y_step;
	int		step;
	int		z;
	int		z1;

	z = ax->matrix[(int) coords.y][(int) coords.x];
	z1 = ax->matrix[(int) coords.y1][(int) coords.x1];
	scale(ax, &coords);
	ax->rgb = rgb(z, z1, ax->rgb);
	isometric(&coords.x, &coords.y, z);
	isometric(&coords.x1, &coords.y1, z1);
	move(ax, &coords);
	x_step = coords.x1 - coords.x;
	y_step = coords.y1 - coords.y;
	step = max(pos(x_step), pos(y_step));
	x_step /= step;
	y_step /= step;
	while ((int)(coords.x - coords.x1) || (int)(coords.y - coords.y1))
	{
		mlx_pixel_put(ax->mlx, ax->mlx_win, coords.x, coords.y, ax->rgb);
		coords.x += x_step;
		coords.y += y_step;
	}
}
