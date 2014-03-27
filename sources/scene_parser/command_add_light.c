/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_add_light.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollin <acollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 15:12:06 by acollin           #+#    #+#             */
/*   Updated: 2014/03/27 16:48:38 by acollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <ft_print.h>
#include <parser.h>
#include <rt.h>
#include <object.h>
#include <libft.h>

void				cmd_add_light(t_parser *parser, char **line)
{
	t_light		*new_light;

	(void)line;
	new_light = (t_light *)ft_memalloc(sizeof(t_light));
	new_light->intensity = 1.0;
	new_light->color.red = 1.0;
	new_light->color.green = 1.0;
	new_light->color.blue = 1.0;
	new_light->next = env->scene->lights;
	env->scene->lights = new_light;
	parser->last_type = LAST_LIGHT;
}
