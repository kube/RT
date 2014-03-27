/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_define_antialias.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollin <acollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 19:42:48 by acollin           #+#    #+#             */
/*   Updated: 2014/03/27 19:49:11 by acollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_print.h>
#include <parser.h>
#include <rt.h>
#include <object.h>
#include <libft.h>
#include <stdlib.h>

void				cmd_define_antialias(t_parser *parser, char **line)
{
	unsigned int	antialias;

	if (parser->last_type == LAST_NONE)
	{
		antialias = (unsigned int)ft_atoi(line[0]);
		if (antialias >= 1 && antialias <= 40)
			env->scene->antialias = antialias;
	}
	else
		ft_putendl_fd("ERROR! Orphan Property: antialias.", 2);
}
