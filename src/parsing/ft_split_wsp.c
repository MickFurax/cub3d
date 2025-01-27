/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_wsp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabenja <mrabenja@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 10:46:05 by mrabenja          #+#    #+#             */
/*   Updated: 2025/01/24 10:46:08 by mrabenja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static int	count_words(const char *str)
{
	int	count;

	count = 0;
	while (*str)
	{
		while (*str && ft_isspace(*str))
			str++;
		if (*str && !ft_isspace(*str))
		{
			count++;
			while (*str && !ft_isspace(*str))
				str++;
		}
	}
	return (count);
}

char	**ft_split_wsp(char const *s)
{
	int			length;
	char		**array;
	int			i;
	const char	*start;

	i = 0;
	length = count_words(s);
	array = (char **)malloc(sizeof(char *) * (length + 1));
	if (!array)
		return (NULL);
	while (*s)
	{
		while (*s && ft_isspace(*s))
			s++;
		if (*s && !ft_isspace(*s))
		{
			start = s;
			while (*s && !ft_isspace(*s))
				s++;
			array[i++] = ft_substr(start, 0, s - start);
		}
	}
	array[i] = NULL;
	return (array);
}
