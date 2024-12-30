/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabeman <arabeman@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 08:45:49 by arabeman          #+#    #+#             */
/*   Updated: 2024/03/02 11:57:41 by arabeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_iswhitespace(int c)
{
	if (((c >= 9) && (c <= 13)) || c == 32)
	{
		return (1);
	}
	return (0);
}

static int	looping(const char *nptr, int i, int atoi, int sign)
{
	while (nptr[i] != '\0')
	{
		if ((nptr[i] == '-' || nptr[i] == '+') && !ft_isdigit(nptr[i + 1]))
			break ;
		if ((nptr[i] == '+' && ft_isdigit(nptr[i + 1])))
			i++;
		else if ((nptr[i] == '-' && ft_isdigit(nptr[i + 1])))
		{
			sign = -1;
			i++;
		}
		if (!ft_isdigit(nptr[i]) && !ft_iswhitespace(nptr[i]))
			break ;
		if (ft_isdigit(nptr[i]))
		{
			atoi = atoi * 10 + (nptr[i] - '0');
			if (!ft_isdigit(nptr[i + 1]))
				break ;
		}
		i++;
	}
	return ((int)(atoi * sign));
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	atoi;
	int	sign;

	i = 0;
	atoi = 0;
	sign = 1;
	if (nptr[i] != '\0')
	{
		atoi = looping(nptr, i, atoi, sign);
	}
	return (atoi);
}
