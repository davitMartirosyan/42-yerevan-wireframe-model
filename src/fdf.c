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
        map_init(axios, av[1]);
    return (0);
}