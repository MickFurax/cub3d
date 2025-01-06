/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabeman <arabeman@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 09:16:51 by arabeman          #+#    #+#             */
/*   Updated: 2025/01/06 16:31:09 by arabeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	s1_len;
	unsigned int	s2_len;
	char			*pointer;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	pointer = (char *)malloc((s1_len + s2_len) + 1);
	if (!pointer)
		return (NULL);
	ft_strlcpy(pointer, (char *)s1, s1_len + 1);
	ft_strlcat(pointer + s1_len, (char *)s2, s1_len + s2_len + 1);
	return (pointer);
}
