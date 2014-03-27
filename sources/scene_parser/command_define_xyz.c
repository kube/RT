/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_define_xyz.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollin <acollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 16:45:09 by acollin           #+#    #+#             */
/*   Updated: 2014/03/27 16:55:14 by acollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_print.h>
#include <parser.h>
#include <rt.h>
#include <object.h>
#include <libft.h>

void				cmd_define_x(t_parser *parser, char **line)
{
	if (parser->last_type == LAST_CAMERA)
		env->scene->camera.origin.x = ft_atoi(line[1]);
	else if (parser->last_type == LAST_OBJECT)
		env->scene->objects->origin.x = ft_atoi(line[1]);
	else if (parser->last_type == LAST_LIGHT)
		env->scene->lights->origin.x = ft_atoi(line[1]);
	else
		ft_putendl_fd("ERROR! Orphan Property.", 2);
}

void				cmd_define_z(t_parser *parser, char **line)
{
	if (parser->last_type == LAST_CAMERA)
		env->scene->camera.origin.z = ft_atoi(line[1]);
	else if (parser->last_type == LAST_OBJECT)
		env->scene->objects->origin.z = ft_atoi(line[1]);
	else if (parser->last_type == LAST_LIGHT)
		env->scene->lights->origin.z = ft_atoi(line[1]);
	else
		ft_putendl_fd("ERROR! Orphan Property.", 2);
}

void				cmd_define_y(t_parser *parser, char **line)
{
	if (parser->last_type == LAST_CAMERA)
		env->scene->camera.origin.y = ft_atoi(line[1]);
	else if (parser->last_type == LAST_OBJECT)
		env->scene->objects->origin.y = ft_atoi(line[1]);
	else if (parser->last_type == LAST_LIGHT)
		env->scene->lights->origin.y = ft_atoi(line[1]);
	else
		ft_putendl_fd("ERROR! Orphan Property.", 2);
}
