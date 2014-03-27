/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_define_axisx.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollin <acollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 19:55:11 by acollin           #+#    #+#             */
/*   Updated: 2014/03/27 20:06:38 by acollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_print.h>
#include <parser.h>
#include <rt.h>
#include <object.h>
#include <libft.h>
#include <stdlib.h>

void				cmd_define_x_axisx(t_parser *parser, char **line)
{
	if (parser->last_type == LAST_CAMERA)
		env->scene->camera.x_axis.x = atof(line[0]);
	else
		ft_putendl_fd("ERROR! Orphan Property x_axis.", 2);
}

void				cmd_define_x_axisy(t_parser *parser, char **line)
{
	if (parser->last_type == LAST_CAMERA)
		env->scene->camera.x_axis.y = atof(line[0]);
	else
		ft_putendl_fd("ERROR! Orphan Property x_axis.", 2);
}

void				cmd_define_x_axisz(t_parser *parser, char **line)
{
	if (parser->last_type == LAST_CAMERA)
		env->scene->camera.x_axis.z = atof(line[0]);
	else
		ft_putendl_fd("ERROR! Orphan Property x_axis.", 2);
}
