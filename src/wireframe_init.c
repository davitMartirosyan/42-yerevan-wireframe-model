/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wireframe_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmartiro <dmartiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 04:23:37 by dmartiro          #+#    #+#             */
/*   Updated: 2022/06/26 04:42:13 by dmartiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void wireframe_init(t_axios *axios)
{
    int x;
    int y;
    axios->rgb = 0x00ca1c;
    y = 0;
    while(y < axios->height)
    {
        x = 0;
        while(x < axios->width)
        {
            if(x < axios->width - 1)
                draw(x, y, x+1, y, axios);
            if(y < axios->height - 1)
                draw(x, y, x, y+1, axios);
            axios->rgb += 0xc1ac;   
            x++;
        }
        y++;
    }
}