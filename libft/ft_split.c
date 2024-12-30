/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabeman <arabeman@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:03:49 by arabeman          #+#    #+#             */
/*   Updated: 2024/03/02 11:58:59 by arabeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdio.h>

static int	ft_arr_l(char *s, char c)
{
	int	count;
	int	is_arr_item;
	int	i;

	count = 0;
	is_arr_item = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			is_arr_item = 0;
		}
		else if (!is_arr_item)
		{
			is_arr_item = 1;
			count++;
		}
		i++;
	}
	return (count);
}

static char	*duplicate(char *start, char *end)
{
	int		i;
	int		len;
	char	*result;

	len = end - start;
	result = (char *)malloc((len + 1) * sizeof(char));
	if (!result)
		return (NULL);
	i = 0;
	while (i < len)
	{
		result[i] = start[i];
		i++;
	}
	result[len] = '\0';
	return (result);
}

char	**ft_split(char const *s, char c)
{
	int		arr_l;
	char	**arr;
	char	*start;
	int		j;

	arr_l = ft_arr_l((char *)s, c);
	start = (char *)s;
	j = 0;
	arr = (char **)malloc(sizeof(char *) * (arr_l + 1));
	if (!arr)
		return (NULL);
	while (*s)
	{
		if (*s == c)
		{
			if (start != s)
				arr[j++] = duplicate(start, (char *)s);
			start = (char *)s + 1;
		}
		s++;
	}
	if (start != s)
		arr[j++] = duplicate(start, (char *)s);
	arr[j] = NULL;
	return (arr);
}
