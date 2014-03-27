/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_add_sphere.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 14:29:14 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/03/27 14:47:58 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_print.h>
#include <parser.h>
#include <rt.h>
#include <object.h>

void				cmd_add_sphere(t_parser *parser, char **line)
{
	(void)line;
	parser->last_type = LAST_OBJECT;
	add_object(env->scene, new_object(OBJ_SPHERE));
}
