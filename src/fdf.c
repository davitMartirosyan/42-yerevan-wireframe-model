/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmartiro <dmartiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 03:19:21 by dmartiro          #+#    #+#             */
/*   Updated: 2022/06/14 05:14:31 by dmartiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int main(int ac, char **av)
{
    t_axios *axios;
    axios = (t_axios *)malloc(sizeof(t_axios));
    if(ac == 2)
        generate_map_array(axios, av[1]);
    // axios->mlx = mlx_init();
    // axios->mlx_win = mlx_new_window(axios->mlx, 1000, 1000, "Fdf");
    // axios->scale = 20;
    // map(axios);
    // mlx_loop(axios->mlx);

    // int i = 0;
    // int a;
    // while(i < axios->height)
    // {
    //     a = 0;
    //     while(a < axios->width)
    //     {
    //         printf("%d ", axios->matrix[i][a]);
    //         a++;
    //     }
    //     printf("\n");
    //     i++;
    // }
    printf("%d\n", axios->width);
    // return (0);
}