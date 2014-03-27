/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_add_plane.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 14:29:14 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/03/27 15:23:03 by acollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_print.h>
#include <parser.h>
#include <rt.h>
#include <object.h>

void				cmd_add_plane(t_parser *parser, char **line)
{
	(void)line;
	parser->last_type = LAST_OBJECT;
	add_object(env->scene, new_object(OBJ_PLANE));
}
