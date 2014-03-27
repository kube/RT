/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_define_specular.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollin <acollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 17:32:16 by acollin           #+#    #+#             */
/*   Updated: 2014/03/27 17:32:56 by acollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_print.h>
#include <parser.h>
#include <rt.h>
#include <object.h>
#include <libft.h>

void				cmd_define_specular(t_parser *parser, char **line)
{
	if (parser->last_type == LAST_OBJECT)
		env->scene->objects->specular = ft_atoi(line[1]);
	else
		ft_putendl_fd("ERROR! Orphan Property: specular.", 2);
}
