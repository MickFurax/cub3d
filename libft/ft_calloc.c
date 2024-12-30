/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabeman <arabeman@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 13:00:26 by arabeman          #+#    #+#             */
/*   Updated: 2024/03/02 11:57:48 by arabeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char			*pointer;
	unsigned int	i;

	pointer = malloc(nmemb * size);
	i = 0;
	if (!pointer)
	{
		return (NULL);
	}
	while (i < nmemb * size)
	{
		pointer[i] = 0;
		i++;
	}
	return ((void *)pointer);
}
