/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_define_diffuse.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollin <acollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 17:28:38 by acollin           #+#    #+#             */
/*   Updated: 2014/03/27 17:31:38 by acollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_print.h>
#include <parser.h>
#include <rt.h>
#include <object.h>
#include <libft.h>

void				cmd_define_diffuse(t_parser *parser, char **line)
{
	if (parser->last_type == LAST_OBJECT)
		env->scene->objects->diffuse = ft_atoi(line[1]);
	else
		ft_putendl_fd("ERROR! Orphan Property: diffuse.", 2);
}
