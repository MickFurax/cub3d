/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_addback.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabeman <arabeman@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 14:55:04 by arabeman          #+#    #+#             */
/*   Updated: 2025/01/10 15:23:36 by arabeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Adds a new element at the end of a table.
 * @param tab The table to be modified.
 * @param str The new element to be added.
 * @return The modified table with the new string added at the end.
 */
char	**tab_addback(char **tab, char *str)
{
	int		i;
	char	**new;

	new = malloc(sizeof(char *) * (tab_length(tab) + 2));
	if (!new)
		return (NULL);
	i = 0;
	while (tab && tab[i])
	{
		new[i] = tab[i];
		i++;
	}
	new[i] = str;
	new[i + 1] = NULL;
	free(tab);
	return (new);
}
