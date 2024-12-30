/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabeman <arabeman@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 08:45:31 by arabeman          #+#    #+#             */
/*   Updated: 2024/03/02 11:58:22 by arabeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*pointer;
	unsigned int	s_len;
	unsigned int	i;

	s_len = ft_strlen(s);
	if (!s)
		return (NULL);
	if (start > s_len)
		len = 0;
	if (len > s_len)
		len = ft_strlen(s + (start));
	if ((s_len - start) < len)
		len = s_len - start;
	pointer = malloc(len + 1);
	i = 0;
	if (!pointer)
		return (NULL);
	while ((s[i] != '\0') && (i < len))
	{
		pointer[i] = s[start];
		start++;
		i++;
	}
	pointer[i] = '\0';
	return (pointer);
}
