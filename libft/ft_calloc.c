/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabeman <arabeman@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 13:00:26 by arabeman          #+#    #+#             */
/*   Updated: 2025/01/06 18:27:28 by arabeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char			*pointer;

	pointer = malloc(nmemb * size);
	if (!pointer)
		return (NULL);
	ft_bzero(pointer, nmemb * size);
	return ((void *)pointer);
}
