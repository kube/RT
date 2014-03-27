/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_define_rotxyz.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 16:44:16 by acollin           #+#    #+#             */
/*   Updated: 2014/03/27 19:21:46 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_print.h>
#include <parser.h>
#include <rt.h>
#include <object.h>
#include <libft.h>
#include <stdlib.h>

void				cmd_define_rotx(t_parser *parser, char **line)
{
	if (parser->last_type == LAST_OBJECT)
		env->scene->objects->rotX = atof(line[0]);
	else if (parser->last_type == LAST_LIGHT)
		env->scene->lights->direction.x = atof(line[0]);
	else
		ft_putendl_fd("ERROR! Orphan Property: rotx.", 2);
}

void				cmd_define_rotz(t_parser *parser, char **line)
{
	if (parser->last_type == LAST_OBJECT)
		env->scene->objects->rotZ = atof(line[0]);
	else if (parser->last_type == LAST_LIGHT)
		env->scene->lights->direction.z = atof(line[0]);
	else
		ft_putendl_fd("ERROR! Orphan Property: rotz.", 2);
}

void				cmd_define_roty(t_parser *parser, char **line)
{
	if (parser->last_type == LAST_OBJECT)
		env->scene->objects->rotY = atof(line[0]);
	else if (parser->last_type == LAST_LIGHT)
		env->scene->lights->direction.y= atof(line[0]);
	else
		ft_putendl_fd("ERROR! Orphan Property: roty.", 2);
}
