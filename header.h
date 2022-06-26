/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmartiro <dmartiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 01:23:44 by dmartiro          #+#    #+#             */
/*   Updated: 2022/06/26 07:17:01 by dmartiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
#define HEADER_H

#include <mlx.h>
#include "libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h> 
#include <fcntl.h>
typedef struct s_axios
{
    void *mlx;
    void *mlx_win;
    int scale;
    int rgb;
    int width;
    int height;
    int **matrix;
    int _x;
    int _y;
}   t_axios;

//generating
void map_init(t_axios *axios, char *filename);
void draw(float x, float y, float x1, float y1, t_axios *axios);
void wireframe_init(t_axios *axios);
void isometric(float *x, float *y, int z);
#endif