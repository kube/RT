/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_define_rgb.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollin <acollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 17:10:22 by acollin           #+#    #+#             */
/*   Updated: 2014/03/27 17:14:32 by acollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_print.h>
#include <parser.h>
#include <rt.h>
#include <object.h>
#include <libft.h>

void				cmd_define_red(t_parser *parser, char **line)
{
	if (parser->last_type == LAST_LIGHT)
		env->scene->lights->color.red = ft_atoi(line[1]);
	else
		ft_putendl_fd("ERROR! Orphan Property: red.", 2);
}

void				cmd_define_green(t_parser *parser, char **line)
{
	if (parser->last_type == LAST_LIGHT)
		env->scene->lights->color.green = ft_atoi(line[1]);
	else
		ft_putendl_fd("ERROR! Orphan Property: green.", 2);
}

void				cmd_define_blue(t_parser *parser, char **line)
{
	if (parser->last_type == LAST_LIGHT)
		env->scene->lights->color.blue = ft_atoi(line[1]);
	else
		ft_putendl_fd("ERROR! Orphan Property: blue.", 2);
}
