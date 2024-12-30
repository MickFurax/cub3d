/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabeman <arabeman@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 09:16:51 by arabeman          #+#    #+#             */
/*   Updated: 2024/03/02 11:58:35 by arabeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	s1_len;
	unsigned int	s2_len;
	unsigned int	i;
	unsigned int	j;
	char			*pointer;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	i = 0;
	j = 0;
	pointer = (char *)malloc((s1_len + s2_len) + 1);
	if (!pointer)
		return (NULL);
	while (i < s1_len)
	{
		pointer[i] = s1[i];
		i++;
	}
	while (i < (s1_len + s2_len) + 1)
	{
		pointer[i++] = s2[j++];
	}
	pointer[i] = '\0';
	return (pointer);
}
