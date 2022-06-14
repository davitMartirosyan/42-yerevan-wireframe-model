/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmartiro <dmartiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 01:23:44 by dmartiro          #+#    #+#             */
/*   Updated: 2022/06/14 05:37:21 by dmartiro         ###   ########.fr       */
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
    int scale;
    int rgb;
    int width;
    int height;
    int **matrix;
}   t_axios;

//generating
void generate_map_array(t_axios *wm, char *fname);

//drawing
void drawing(float x, float y, float x1, float y1, t_axios *matrix);
void map(t_axios *matrix);
float mod(float i);
float max(float a, float b);
void isometric(float *x, float *y, int z);
#endif