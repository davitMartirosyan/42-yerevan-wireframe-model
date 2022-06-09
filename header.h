/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmartiro <dmartiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 03:19:17 by dmartiro          #+#    #+#             */
/*   Updated: 2022/06/08 03:29:50 by dmartiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

typedef struct s_data
{
    void *img;
    void *addr;
    int bits_per_pixel;
    int line_length;
    int endian;
}   t_data;

int is_prime(int x);
void draw(t_data *data, int x, int y, int color);
void triangle(t_data data, int x, int y, int h);
#endif