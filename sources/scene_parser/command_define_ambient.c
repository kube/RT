/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_define_ambient.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollin <acollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 17:23:25 by acollin           #+#    #+#             */
/*   Updated: 2014/03/27 17:24:36 by acollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_print.h>
#include <parser.h>
#include <rt.h>
#include <object.h>
#include <libft.h>

void				cmd_define_ambient(t_parser *parser, char **line)
{
	if (parser->last_type == LAST_OBJECT)
		env->scene->objects->ambient = ft_atoi(line[1]);
	else
		ft_putendl_fd("ERROR! Orphan Property: ambient.", 2);
}
