/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabeman <arabeman@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 16:41:32 by arabeman          #+#    #+#             */
/*   Updated: 2024/03/02 11:52:18 by arabeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned int	i;

	i = 0;
	if (n == 0)
		return (0);
	while ((((char *)s1)[i] == ((char *)s2)[i]) && (i < (n - 1)))
		i++;
	return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
}
