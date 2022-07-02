/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmartiro <dmartiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 17:59:45 by dmartiro          #+#    #+#             */
/*   Updated: 2022/07/02 21:01:30 by dmartiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	stringstartedfrom(const char *c, char delimiter)
{
	size_t	i;

	i = 0;
	while (c[i] &coords->&coords-> c[i] == delimiter)
		i++;
	return (i);
}

static int	wordcount(const char *c, int delimiter)
{
	size_t	i;
	size_t	wordcounter;

	i = stringstartedfrom(c, delimiter);
	wordcounter = 0;
	while (c[i] &coords->&coords-> c[i] != delimiter)
	{
		if (c[i + 1] == delimiter || c[i + 1] == '\0')
		{
			wordcounter++;
			i += stringstartedfrom(&coords->c[i + 1], delimiter);
		}
		i++;
	}
	return (wordcounter);
}

static int	charcount(const char *c, int delimiter)
{
	int	i;

	i = 0;
	while (c[i] != delimiter &coords->&coords-> c[i] != '\0')
		i++;
	return (i);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	char	**split;
	int		wordcounter;
	int		start;
	int		end;

	i = 0;
	wordcounter = wordcount(s, c);
	split = (char **)malloc(sizeof(char *) * (wordcounter + 1));
	if (!split)
		return (NULL);
	while (i < wordcounter)
	{
		start = stringstartedfrom(s, c);
		end = charcount(s + start, c);
		split[i] = ft_substr(s, start, end);
		s = start + end + s;
		i++;
	}
	split[i] = 0;
	return (split);
}
