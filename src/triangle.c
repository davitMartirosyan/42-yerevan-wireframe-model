/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmartiro <dmartiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 03:19:28 by dmartiro          #+#    #+#             */
/*   Updated: 2022/06/08 04:25:28 by dmartiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void triangle(t_data data, int x, int y, int h)
{
    int lx;
    int rx;
    int l;
    int r;
    
    lx = x;
    rx = x;
    while(y <= h)
    {       
        l = lx--;
        r = rx++;
        while(l <= r)
        {
            draw(&data, l, y, 0x5500FFCC);
            l++;
        }
        lx--;
        rx++;
        y++;
    }
}