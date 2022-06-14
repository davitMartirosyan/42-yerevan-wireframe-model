/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_generator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmartiro <dmartiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 02:43:49 by dmartiro          #+#    #+#             */
/*   Updated: 2022/06/14 06:13:50 by dmartiro         ###   ########.fr       */
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

static void	map_width(t_axios *wm, char *file, char *str, char **buf)
{
	int		read_len;
	char	*str2;
    int fd;

    fd = open(file, O_RDONLY, 0);
	read_len = read(fd, str, BUFF_SIZE);
	while (read_len > 0)
	{
		str[read_len] = 0;
		if (!*buf)
			*buf = ft_substr(str, 0, read_len);
		else
		{
			str2 = *buf;
			*buf = ft_strjoin(*buf, str);
			free(str2);
		}
		if (ft_strchr(str, '\n'))
			break ;
		read_len = read(fd, str, BUFF_SIZE);
	}
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
    char	*str;
	static char	*buff;
    char **split;
    int width;

    width = 0;
    str = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1));
	if (!str)
		return ;
    map_width(wm, fname, str, &buff);
    map_height(wm, fname);
    split = ft_split(buff, ' ');
    while(split[width])
        width++;
    wm->width = width;
    free(buff);
}
