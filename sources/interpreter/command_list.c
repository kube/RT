/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/17 03:01:57 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/03/19 18:50:05 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>
#include <ft_print.h>

#include <stdio.h>

void				command_list(char **line)
{
	t_object		*object;
	t_light			*light;

	(void)line;
	object = env->scene->objects;
	ft_putendl("OBJECTS:");
	while (object)
	{
		if (object->type == OBJ_SPHERE)
			ft_putstr("Sphere ");
		else if (object->type == OBJ_PLANE)
			ft_putstr("Plane ");
		printf("\t%u\n", (unsigned int)object);
		ft_putendl("");
		object = object->next;
	}
	light = env->scene->lights;
	ft_putendl("\nLIGHTS:");
	while (light)
	{
		ft_putstr("Light ");
		printf("\t%u\n", (unsigned int)light);
		ft_putendl("");
		light = light->next;
	}
}
