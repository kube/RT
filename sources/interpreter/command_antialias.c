/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_antialias.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/17 03:01:57 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/03/27 17:14:01 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>
#include <ft_print.h>
#include <ft_convert.h>

void				cmd_antialias(char **line)
{
	int				value;

	value = -1;
	if (*line)
		value = ft_atoi(*line);
	if (value < 1 || value > 40 || !line[1])
		env->scene->antialias = (unsigned int)value;
	else
		ft_putendl_fd("usage: antialias <value:1-40>", 2);
}
