/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabeman <arabeman@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 13:40:11 by arabeman          #+#    #+#             */
/*   Updated: 2024/03/02 11:58:50 by arabeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	get_beginning(int beginning, unsigned int set_len, char const *s1,
		char const *set)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (s1[i] != '\0')
	{
		j = 0;
		while (set[j] != '\0')
		{
			if (set[j] == s1[i])
			{
				beginning++;
				break ;
			}
			j++;
		}
		if (j == set_len)
			break ;
		i++;
	}
	return (beginning);
}

static int	get_ending(int ending, unsigned int set_len, char const *s1,
		char const *set)
{
	unsigned int	i;
	unsigned int	j;

	i = ending - 1;
	while (i > 0)
	{
		j = 0;
		while (set[j] != '\0')
		{
			if (set[j] == s1[i])
			{
				ending--;
				break ;
			}
			j++;
		}
		if (j == set_len)
			break ;
		i--;
	}
	if (ending <= 0 || ending == 1)
		return (1);
	return (ending);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char			*pointer;
	int				beginning;
	int				ending;
	unsigned int	set_len;

	if (s1[0] == '\0')
		return (ft_calloc(1, 1));
	set_len = ft_strlen(set);
	beginning = 0;
	ending = ft_strlen(s1);
	if (((int)set_len > ending))
		return (NULL);
	beginning = get_beginning(beginning, set_len, s1, set);
	ending = get_ending(ending, set_len, s1, set);
	if (ending < beginning)
		return (ft_calloc(1, 1));
	pointer = malloc((ending - beginning) + 1);
	if (!pointer)
		return (NULL);
	ft_strlcpy(pointer, (char *)(s1) + beginning, (ending - beginning) + 1);
	return (pointer);
}
