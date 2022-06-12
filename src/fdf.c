/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmartiro <dmartiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 03:19:21 by dmartiro          #+#    #+#             */
/*   Updated: 2022/06/12 05:01:45 by dmartiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int main(int ac, char **av)
{
    t_axios *axios;
    axios = (t_axios *)malloc(sizeof(t_axios));
    if(ac == 2)
        generate_map_array(axios, av[1]);
        
    printf("X -> : %d\n", axios->width);
    printf("Y -> : %d\n", axios->height);
    printf("Cord -> : %d\n", axios->matrix[2][2]);
    
    return (0);
}