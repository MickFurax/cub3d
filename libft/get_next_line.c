/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabeman <arabeman@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 15:11:23 by arabeman          #+#    #+#             */
/*   Updated: 2025/01/06 16:30:39 by arabeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_realloc_and_join(char *s1, char *s2);
char		*ft_clean(char *s);
char		*ft_read_and_add(int fd, char *all);
char		*ft_strrchr(const char *s, int c);

char	*get_next_line(int fd)
{
	char		*next_line;
	static char	*all[1024] = {NULL};
	int			i;

	i = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!all[fd])
		all[fd] = ft_strdup("");
	all[fd] = ft_read_and_add(fd, all[fd]);
	if (!all[fd])
		return (NULL);
	while (all[fd][i] && all[fd][i] != 10)
		i++;
	if (all[fd][i] == 10)
		i++;
	next_line = ft_substr(all[fd], 0, i);
	if (!next_line)
		return (free(next_line), NULL);
	all[fd] = ft_clean(all[fd]);
	return (next_line);
}

char	*ft_realloc_and_join(char *s1, char *s2)
{
	char	*all;

	all = ft_strjoin(s1, s2);
	free(s1);
	return (all);
}

char	*ft_clean(char *s)
{
	char	*cleaned;
	int		i;

	i = 0;
	while (s[i] && s[i] != 10)
		i++;
	if (s[i] == 10)
		i++;
	if (s[i] == '\0')
		return (free(s), NULL);
	cleaned = ft_strdup(s + i);
	free(s);
	return (cleaned);
}

char	*ft_read_and_add(int fd, char *all)
{
	int		nb_read;
	char	*temp;

	nb_read = BUFFER_SIZE;
	while (nb_read != 0)
	{
		temp = malloc(BUFFER_SIZE + 1);
		if (!temp)
			return (free(all), NULL);
		nb_read = read(fd, temp, BUFFER_SIZE);
		if (nb_read < 0 || (nb_read == 0 && !ft_strlen(all)))
			return (free(temp), free(all), NULL);
		if (nb_read == 0 || (nb_read == 1 && temp[0] == '\0'))
			return (free(temp), all);
		temp[nb_read] = '\0';
		all = ft_realloc_and_join(all, temp);
		if (ft_strrchr(all, 10))
			return (free(temp), all);
		free(temp);
	}
	if (!all)
		return (free(all), NULL);
	return (all);
}
