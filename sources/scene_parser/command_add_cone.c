/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_add_cone.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollin <acollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 15:22:51 by acollin           #+#    #+#             */
/*   Updated: 2014/03/27 15:22:56 by acollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_print.h>
#include <parser.h>
#include <rt.h>
#include <object.h>

void				cmd_add_cone(t_parser *parser, char **line)
{
	(void)line;
	parser->last_type = LAST_OBJECT;
	add_object(env->scene, new_object(OBJ_CONE));
}
