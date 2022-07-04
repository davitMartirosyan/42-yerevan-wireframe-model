/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_generator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmartiro <dmartiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 10:20:42 by dmartiro          #+#    #+#             */
/*   Updated: 2022/07/04 11:12:44 by dmartiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

static int	map_width(char *filename)
{
	int		fd;
	int		i;
	char	**split;

	i = 0;
	fd = open(filename, O_RDONLY);
	split = ft_split(get_next_line(fd, 1), ' ');
	while (split[i])
		i++;
	close(fd);
	return (i);
}

static int	map_height(char *filename)
{
	int	fd;
	int	i;

	i = 0;
	fd = open(filename, O_RDONLY);
	while (get_next_line(fd, 1))
		i++;
	get_next_line(fd, 0);
	close(fd);
	return (i);
}

static void	create_matrix(int *matrix, char *line)
{
	char	**split;
	int		i;

	i = 0;
	split = ft_split(line, ' ');
	while (split[i])
	{
		matrix[i] = ft_atoi(split[i]);
		i++;
	}
}

void	map_init(t_axios *axios, char *filename)
{
	int		i;
	int		fd;
	char	*line;

	axios->width = map_width(filename);
	axios->height = map_height(filename);
	axios->matrix = (int **)malloc(sizeof(int *) * axios->height);
	i = 0;
	while (i < axios->height)
		axios->matrix[i++] = (int *)malloc(sizeof(int) * axios->width);
	fd = open(filename, O_RDONLY);
	i = 0;
	line = get_next_line(fd, 1);
	while (line != NULL)
	{
		create_matrix(axios->matrix[i++], line);
		free(line);
		line = get_next_line(fd, 1);
	}
	close(fd);
}
