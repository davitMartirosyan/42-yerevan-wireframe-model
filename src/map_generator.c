/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_generator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmartiro <dmartiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 02:43:49 by dmartiro          #+#    #+#             */
/*   Updated: 2022/06/12 06:25:27 by dmartiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

static void map_height(t_axios *wm, char *file)
{
    int height;
    int fd;
    
    fd = open(file, O_RDONLY, 0);
    height = 0;
    while(get_next_line(fd))
        height++;
    wm->height = height;
    close(fd);
}


static void map_width(t_axios *wm, char *file)
{
    int fd;

    fd = open(file, O_RDONLY, 0);
    wm->width = ft_wordcounter(get_next_line(fd), ' ');
    close(fd);
}

static void matrix_space(int *matrix, char *line)
{
    int i;
    char **n;

    n = ft_split(line, ' ');
    i = 0;
    while(n[i++])
        matrix[i] = ft_atoi(n[i]);
}

void generate_map_array(t_axios *wm, char *fname)
{
    int i;
    int f;
    
    map_width(wm, fname);
    map_height(wm, fname);
    f = open(fname, O_RDONLY, 0);
    i = 0;
    wm->matrix = (int **)malloc(sizeof(int *) * (wm->height));
    while(i <= wm->height)
    {
        wm->matrix[i] = (int *)malloc(sizeof(int) * (wm->width));
        i++;
    }
    i = 0;
    while(i < wm->height)
        matrix_space(wm->matrix[i++], get_next_line(f));
}