/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_define_rotxyz.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollin <acollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 16:44:16 by acollin           #+#    #+#             */
/*   Updated: 2014/03/27 17:03:13 by acollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_print.h>
#include <parser.h>
#include <rt.h>
#include <object.h>
#include <libft.h>

void				cmd_define_rotx(t_parser *parser, char **line)
{
	if (parser->last_type == LAST_OBJECT)
		env->scene->objects->rotX = ft_atoi(line[1]);
	else if (parser->last_type == LAST_LIGHT)
		env->scene->lights->direction.x = ft_atoi(line[1]);
	else
		ft_putendl_fd("ERROR! Orphan Property: rotx.", 2);
}

void				cmd_define_rotz(t_parser *parser, char **line)
{
	if (parser->last_type == LAST_OBJECT)
		env->scene->objects->rotZ = ft_atoi(line[1]);
	else if (parser->last_type == LAST_LIGHT)
		env->scene->lights->direction.z = ft_atoi(line[1]);
	else
		ft_putendl_fd("ERROR! Orphan Property: rotz.", 2);
}

void				cmd_define_roty(t_parser *parser, char **line)
{
	if (parser->last_type == LAST_OBJECT)
		env->scene->objects->rotY = ft_atoi(line[1]);
	else if (parser->last_type == LAST_LIGHT)
		env->scene->lights->direction.y= ft_atoi(line[1]);
	else
		ft_putendl_fd("ERROR! Orphan Property: roty.", 2);
}
