/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabeman <arabeman@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 07:58:00 by arabeman          #+#    #+#             */
/*   Updated: 2025/01/07 13:05:16 by arabeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


static char	*indexing(int c, int index, int c_temp, char *pointer)
{
	if (c < 0)
		c_temp = c * -1;
	while (index >= 0)
	{
		pointer[index] = (c_temp % 10) + 48;
		c_temp = c_temp / 10;
		index--;
		if (c < 0 && index == 0)
		{
			pointer[index] = '-';
			break ;
		}
	}
	return (pointer);
}

char	*ft_itoa(int c)
{
	int		index;
	int		n;
	int		c_temp;
	char	*pointer;

	if (c == -2147483648)
		return (ft_strdup("-2147483648"));
	index = 0;
	n = c;
	c_temp = c;
	if (n < 0)
	{
		n = c * -1;
		index++;
	}
	while (n > 9)
	{
		n = n / 10;
		index++;
	}
	pointer = malloc((index + 2));
	if (!pointer)
		return (0);
	pointer[index + 1] = '\0';
	return (indexing(c, index, c_temp, pointer));
}
