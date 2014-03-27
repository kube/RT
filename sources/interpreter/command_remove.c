/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_remove.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/17 03:01:57 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/03/27 19:50:48 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>
#include <ft_print.h>
#include <ft_convert.h>

static int			search_objects(int search)
{
	t_object		*object;

	object = env->scene->objects;
	while (object)
	{
		if ((int)object == search)
		{
			remove_object(env->scene, object);
			return (1);
		}
		object = object->next;
	}
	return (0);
}

static int			search_lights(int search)
{
	t_light			*light;

	light = env->scene->lights;
	while (light)
	{
		if ((int)light == search)
		{
			remove_light(env->scene, light);
			return (1);
		}
		light = light->next;
	}
	return (0);
}

void				cmd_remove(char **line)
{
	int				search;

	if (*line)
	{
		search = (unsigned int)ft_atoi(*line);
		if (search_objects(search))
			return ;
		if (search_lights(search))
			return ;
		ft_putendl("Object not found.");
	}
	else
		ft_putendl("usage: remove <object_adress>");
}
