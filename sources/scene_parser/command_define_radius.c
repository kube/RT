/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_define_radius.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollin <acollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 17:15:45 by acollin           #+#    #+#             */
/*   Updated: 2014/03/27 17:42:14 by acollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_print.h>
#include <parser.h>
#include <rt.h>
#include <object.h>
#include <libft.h>

void				cmd_define_radius(t_parser *parser, char **line)
{
	if (parser->last_type == LAST_OBJECT)
	{
		if (env->scene->objects->type == OBJ_CONE
				|| env->scene->objects->type == OBJ_SPHERE)
		env->scene->objects->radius = ft_atoi(line[1]);
	}
	else
		ft_putendl_fd("ERROR! Orphan Property: radius.", 2);
}
