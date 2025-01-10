/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_display.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabeman <arabeman@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 15:14:16 by arabeman          #+#    #+#             */
/*   Updated: 2025/01/10 15:21:52 by arabeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	tab_display(char **tab)
{
	int	i;

	i = 0;
	while (tab && tab[i])
	{
		ft_putstr_fd("[", 1);
		ft_putnbr_fd(i, 1);
		ft_putstr_fd("] ", 1);
		ft_putendl_fd(tab[i], 1);
		i++;
	}
}
