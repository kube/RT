/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_add_cylinder.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 15:25:36 by acollin           #+#    #+#             */
/*   Updated: 2014/03/27 18:49:34 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_print.h>
#include <parser.h>
#include <rt.h>
#include <object.h>

void				cmd_add_cylinder(t_parser *parser, char **line)
{
	(void)line;
	parser->last_type = LAST_OBJECT;
	add_object(env->scene, new_object(OBJ_CYLINDER));
}
