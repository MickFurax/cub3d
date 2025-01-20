/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_global.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabeman <arabeman@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 18:20:16 by arabeman          #+#    #+#             */
/*   Updated: 2025/01/17 18:53:00 by arabeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static t_data	**_global_data(void)
{
	static t_data	*data = NULL;

	return (&data);
}

t_data	*get_data(void)
{
	return (*_global_data());
}

void	set_data(t_data *data)
{
	*_global_data() = data;
}
