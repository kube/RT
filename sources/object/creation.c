/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/09 02:12:30 by kube              #+#    #+#             */
/*   Updated: 2014/03/17 21:20:48 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>
#include <ft_memory.h>
#include <stdlib.h>

#include <pthread.h>

void			load_matter_object(t_object *object, t_matter *matter)
{
	object->color = matter->color;
	object->opacity = matter->opacity;
	object->ambient = matter->ambient;
	object->diffuse = matter->diffuse;
	object->specular = matter->specular;
	object->reflection = matter->reflection;
	object->refraction = matter->refraction;
	object->refract_index = matter->refract_index;
}

void			duplicate_object(t_env *env, t_object *object)
{
	t_object	*object_created;

	object_created = new_object(OBJ_SPHERE);
	ft_memcpy(object_created, object, sizeof(t_object));
	add_object(env->scene, object_created);
	env->block_render = 0;
	env->refresh_image = 1;
}

void			remove_light(t_scene *scene, t_light *light)
{
	t_light		*current;
	t_light		*previous;

	previous = NULL;
	current = scene->lights;
	while (current)
	{
		if (current == light)
		{
			if (previous)
				previous->next = current->next;
			else
				scene->lights = current->next;
			free(light);
		}
		previous = current;
		current = current->next;
	}
}

void			remove_object(t_scene *scene, t_object *object)
{
	t_object	*current;
	t_object	*previous;

	previous = NULL;
	current = scene->objects;
	while (current)
	{
		if (current == object)
		{
			if (previous)
				previous->next = current->next;
			else
				scene->objects = current->next;
			free(object);
		}
		previous = current;
		current = current->next;
	}
}

void			add_object(t_scene *scene, t_object *object)
{
	object->next = scene->objects;
	scene->objects = object;
}

t_object		*new_object(int type)
{
	t_object	*object;

	object = (t_object*)ft_memalloc(sizeof(t_object));
	object->type = type;
	return (object);
}
