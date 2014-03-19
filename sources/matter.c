/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/09 02:22:30 by kube              #+#    #+#             */
/*   Updated: 2014/03/19 22:57:17 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>
#include <ft_memory.h>
#include <ft_strings.h>

void			load_matter_to_object(t_object *object, t_matter *matter)
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

t_matter		*get_matter(char *name)
{
	t_matter	*current;

	current = env->scene->matters;
	while (current)
	{
		if (ft_strequ(current->name, name))
			return (current);
		current = current->next;
	}
	return (0);
}

void			add_matter(t_matter *matter)
{
	if (!get_matter(matter->name))
	{
		matter->next = env->scene->matters;
		env->scene->matters = matter;
	}
}

t_matter		*new_matter(char *name)
{
	t_matter	*matter;

	matter = (t_matter*)ft_memalloc(sizeof(t_matter));
	matter->name = ft_strdup(name);
	matter->opacity = 1.0;
	matter->color.color = 0xFFFFFFFF;
	matter->refract_index = 1.0;
	matter->next = 0;
	return (matter);
}
