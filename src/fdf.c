/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmartiro <dmartiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 03:19:21 by dmartiro          #+#    #+#             */
/*   Updated: 2022/06/26 04:05:09 by dmartiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int keycode(int key, void *axios)
{
    printf("%d", key);
    return (0);
}

int main(int ac, char **av)
{
    t_axios *axios;
    axios = (t_axios *)malloc(sizeof(t_axios));
    if(ac == 2)
        map_init(axios, av[1]);
    axios->mlx = mlx_init();
    axios->mlx_win = mlx_new_window(axios->mlx, 1000, 1000, "-Fdf-");
    axios->scale = 20;
    mlx_key_hook(axios->mlx_win, keycode, NULL);
    wireframe_init(axios);
    mlx_loop(axios->mlx);
    return (0);
}