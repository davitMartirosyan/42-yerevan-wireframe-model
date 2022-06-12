/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordcounter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmartiro <dmartiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 02:37:07 by dmartiro          #+#    #+#             */
/*   Updated: 2022/06/11 02:40:42 by dmartiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	stringstartedfrom(const char *c, char delimiter)
{
	size_t	i;

	i = 0;
	while (c[i] && c[i] == delimiter)
		i++;
	return (i);
}

int	ft_wordcounter(const char *c, int delimiter)
{
	size_t	i;
	size_t	wordcounter;

	i = stringstartedfrom(c, delimiter);
	wordcounter = 0;
	while (c[i] && c[i] != delimiter)
	{
		if (c[i + 1] == delimiter || c[i + 1] == '\0')
		{
			wordcounter++;
			i += stringstartedfrom(&c[i + 1], delimiter);
		}
		i++;
	}
	return (wordcounter);
}