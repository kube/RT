/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_define_axisz.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollin <acollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 20:03:41 by acollin           #+#    #+#             */
/*   Updated: 2014/03/27 20:04:51 by acollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_print.h>
#include <parser.h>
#include <rt.h>
#include <object.h>
#include <libft.h>
#include <stdlib.h>

void				cmd_define_z_axisx(t_parser *parser, char **line)
{
	if (parser->last_type == LAST_CAMERA)
		env->scene->camera.z_axis.x = atof(line[0]);
	else
		ft_putendl_fd("ERROR! Orphan Property z_axis.", 2);
}

void				cmd_define_z_axisy(t_parser *parser, char **line)
{
	if (parser->last_type == LAST_CAMERA)
		env->scene->camera.z_axis.y = atof(line[0]);
	else
		ft_putendl_fd("ERROR! Orphan Property z_axis.", 2);
}

void				cmd_define_z_axisz(t_parser *parser, char **line)
{
	if (parser->last_type == LAST_CAMERA)
		env->scene->camera.z_axis.z = atof(line[0]);
	else
		ft_putendl_fd("ERROR! Orphan Property z_axis.", 2);
}
