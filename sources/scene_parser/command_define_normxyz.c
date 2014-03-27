/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_define_normxyz.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollin <acollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 16:40:41 by acollin           #+#    #+#             */
/*   Updated: 2014/03/27 17:06:50 by acollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_print.h>
#include <parser.h>
#include <rt.h>
#include <object.h>
#include <libft.h>

void				cmd_define_normx(t_parser *parser, char **line)
{
	if (parser->last_type == LAST_OBJECT)
		env->scene->objects->normal.x = ft_atoi(line[1]);
	else
		ft_putendl_fd("ERROR! Orphan Property: normx.", 2);
}

void				cmd_define_normz(t_parser *parser, char **line)
{
	if (parser->last_type == LAST_OBJECT)
		env->scene->objects->normal.z = ft_atoi(line[1]);
	else
		ft_putendl_fd("ERROR! Orphan Property: normz.", 2);
}

void				cmd_define_normy(t_parser *parser, char **line)
{
	if (parser->last_type == LAST_OBJECT)
		env->scene->objects->normal.y = ft_atoi(line[1]);
	else
		ft_putendl_fd("ERROR! Orphan Property: normy.", 2);
}
