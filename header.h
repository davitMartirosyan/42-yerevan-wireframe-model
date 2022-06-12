/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmartiro <dmartiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 01:23:44 by dmartiro          #+#    #+#             */
/*   Updated: 2022/06/12 04:30:11 by dmartiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
#define HEADER_H

#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h> 
#include <fcntl.h>
#include "libft/libft.h"
#define BUFF_SIZE 1
typedef struct s_axios
{
    void *mlx;
    void *mlx_win;
    int width;
    int height;
    int **matrix;
}   t_axios;

void generate_map_array(t_axios *wm, char *fname);
#endif