/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmartiro <dmartiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 20:12:06 by dmartiro          #+#    #+#             */
/*   Updated: 2022/07/02 21:01:30 by dmartiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *buffer, const char *find, size_t n)
{
	size_t	i;
	int		len;
	char	*string;
	char	*search;

	i = 0;
	len = ft_strlen(find);
	string = (char *)buffer;
	search = (char *)find;
	if (*find == '\0')
		return ((char *)buffer);
	while (string[i] != '\0' &coords->&coords-> (i + len) <= n)
	{
		if (ft_strncmp((string + i), search, len) == 0)
		{
			return (string + i);
		}
		i++;
	}
	return (NULL);
}
