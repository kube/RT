/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_define_axisy.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollin <acollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 20:01:22 by acollin           #+#    #+#             */
/*   Updated: 2014/03/27 20:03:13 by acollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_print.h>
#include <parser.h>
#include <rt.h>
#include <object.h>
#include <libft.h>
#include <stdlib.h>

void				cmd_define_y_axisx(t_parser *parser, char **line)
{
	if (parser->last_type == LAST_CAMERA)
		env->scene->camera.y_axis.x = atof(line[0]);
	else
		ft_putendl_fd("ERROR! Orphan Property y_axis.", 2);
}

void				cmd_define_y_axisy(t_parser *parser, char **line)
{
	if (parser->last_type == LAST_CAMERA)
		env->scene->camera.y_axis.y = atof(line[0]);
	else
		ft_putendl_fd("ERROR! Orphan Property y_axis.", 2);
}

void				cmd_define_y_axisz(t_parser *parser, char **line)
{
	if (parser->last_type == LAST_CAMERA)
		env->scene->camera.y_axis.z = atof(line[0]);
	else
		ft_putendl_fd("ERROR! Orphan Property y_axis.", 2);
}
