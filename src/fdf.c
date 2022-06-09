/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmartiro <dmartiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 03:19:21 by dmartiro          #+#    #+#             */
/*   Updated: 2022/06/08 04:24:54 by dmartiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "../header.h"

int main(void)
{
    int w;
    int h;
    void *mlx;
    void *mlx_win;

    w = 500;
    h = 500;
    t_data img;
    mlx = mlx_init();
    mlx_win = mlx_new_window(mlx, w, h, "Polygon");
    img.img = mlx_new_image(mlx, w, h);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
    
    // circle(img, 100, 100)
    triangle(img, 200, 80, 150);
    mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
    mlx_loop(mlx);
    return (0);

}