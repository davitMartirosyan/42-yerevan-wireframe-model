/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wireframe_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmartiro <dmartiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 04:23:37 by dmartiro          #+#    #+#             */
/*   Updated: 2022/07/02 20:52:51 by dmartiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void cordinate_init(t_coords coords, t_axios *axios)
{
    if(coords.x < axios->width - 1)
    {
        coords.x1 = coords.x+1;
        coords.y1 = coords.y;
        draw(coords, axios);
    }
    if(coords.y < axios->height - 1)
    {
        coords.x1 = coords.x;
        coords.y1 = coords.y+1;
        draw(coords, axios);
    }
}

void wireframe_init(t_axios *axios)
{
    t_coords coords;

    coords.y = 0;
    while(coords.y < axios->height)
    {
        coords.x = 0;
        while(coords.x < axios->width)
        {
            cordinate_init(coords, axios);
            axios->rgb += 0xffc1ac;   
            coords.x++;
        }
        coords.y++;
    }
}