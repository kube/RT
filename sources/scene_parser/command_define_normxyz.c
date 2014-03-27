/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_define_normxyz.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 16:40:41 by acollin           #+#    #+#             */
/*   Updated: 2014/03/27 19:22:58 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_print.h>
#include <parser.h>
#include <rt.h>
#include <object.h>
#include <libft.h>
#include <stdlib.h>

void				cmd_define_normx(t_parser *parser, char **line)
{
	if (parser->last_type == LAST_OBJECT)
		env->scene->objects->normal.x = atof(line[0]);
	else
		ft_putendl_fd("ERROR! Orphan Property: normx.", 2);
}

void				cmd_define_normz(t_parser *parser, char **line)
{
	if (parser->last_type == LAST_OBJECT)
		env->scene->objects->normal.z = atof(line[0]);
	else
		ft_putendl_fd("ERROR! Orphan Property: normz.", 2);
}

void				cmd_define_normy(t_parser *parser, char **line)
{
	if (parser->last_type == LAST_OBJECT)
		env->scene->objects->normal.y = atof(line[0]);
	else
		ft_putendl_fd("ERROR! Orphan Property: normy.", 2);
}
