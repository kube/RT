/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_define_xyz.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 16:45:09 by acollin           #+#    #+#             */
/*   Updated: 2014/03/27 19:22:23 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_print.h>
#include <parser.h>
#include <rt.h>
#include <object.h>
#include <libft.h>
#include <stdlib.h>

void				cmd_define_x(t_parser *parser, char **line)
{
	if (parser->last_type == LAST_CAMERA)
		env->scene->camera.origin.x = atof(line[0]);
	else if (parser->last_type == LAST_OBJECT)
		env->scene->objects->origin.x = atof(line[0]);
	else if (parser->last_type == LAST_LIGHT)
		env->scene->lights->origin.x = atof(line[0]);
	else
		ft_putendl_fd("ERROR! Orphan Property.", 2);
}

void				cmd_define_z(t_parser *parser, char **line)
{
	if (parser->last_type == LAST_CAMERA)
		env->scene->camera.origin.z = atof(line[0]);
	else if (parser->last_type == LAST_OBJECT)
		env->scene->objects->origin.z = atof(line[0]);
	else if (parser->last_type == LAST_LIGHT)
		env->scene->lights->origin.z = atof(line[0]);
	else
		ft_putendl_fd("ERROR! Orphan Property.", 2);
}

void				cmd_define_y(t_parser *parser, char **line)
{
	if (parser->last_type == LAST_CAMERA)
		env->scene->camera.origin.y = atof(line[0]);
	else if (parser->last_type == LAST_OBJECT)
		env->scene->objects->origin.y = atof(line[0]);
	else if (parser->last_type == LAST_LIGHT)
		env->scene->lights->origin.y = atof(line[0]);
	else
		ft_putendl_fd("ERROR! Orphan Property.", 2);
}
