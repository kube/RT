/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/17 03:01:57 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/03/19 19:43:07 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>
#include <ft_print.h>

#include <stdio.h>

static void			display_scene_header()
{
	ft_putendl("scene:");
	ft_putstr("	render_width: ");
	ft_putnbr(env->scene->view_width);
	ft_putendl("");
	ft_putstr("	render_height: ");
	ft_putnbr(env->scene->view_height);
	ft_putendl("");
}

void				command_export(char **line)
{
	t_object		*object;
	t_light			*light;

	(void)line;

	display_scene_header();
	light = env->scene->lights;
	while (light)
	{
		ft_putstr("	light:");
		ft_putendl("");
		light = light->next;
	}
	object = env->scene->objects;
	while (object)
	{
		if (object->type == OBJ_SPHERE)
			ft_putendl("	sphere:");
		else if (object->type == OBJ_PLANE)
			ft_putendl("	plane:");
		object = object->next;
	}
}
