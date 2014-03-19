/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_remove.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/17 03:01:57 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/03/19 18:50:29 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>
#include <ft_print.h>
#include <ft_convert.h>

void				command_remove(char **line)
{
	int				search;
	t_object		*object;
	t_light			*light;

	if (*line)
	{
		search = (unsigned int)ft_atoi(*line);
		object = env->scene->objects;
		while (object)
		{
			if ((int)object == search)
			{
				remove_object(env->scene, object);
				return ;
			}
			object = object->next;
		}
		light = env->scene->lights;
		while (light)
		{
			if ((int)light == search)
			{
				remove_light(env->scene, light);
				return ;
			}
			light = light->next;
		}
		ft_putendl("Object not found.");
	}
	else
		ft_putendl("usage: remove <object_adress>");
}
