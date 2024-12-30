/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabeman <arabeman@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 11:10:56 by arabeman          #+#    #+#             */
/*   Updated: 2024/03/02 11:49:15 by arabeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*temp_dest;
	const char	*temp_src;

	temp_dest = dest;
	temp_src = src;
	if (!dest && !src)
		return (0);
	if (dest <= src)
	{
		while (n--)
		{
			*temp_dest++ = *temp_src++;
		}
	}
	else if (dest > src)
	{
		while (n)
		{
			temp_dest[n - 1] = temp_src[n - 1];
			n--;
		}
	}
	return (dest);
}
