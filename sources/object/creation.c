/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kube <kube@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/09 02:12:30 by kube              #+#    #+#             */
/*   Updated: 2014/03/09 03:13:45 by kube             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>
#include <ft_memory.h>

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

void			add_object(t_env *env, t_object *object)
{
	object->next = env->objects;
	env->objects = object;
}

t_object		*new_object(int type)
{
	t_object	*object;

	object = (t_object*)ft_memalloc(sizeof(t_object));
	object->type = type;
	return (object);
}
