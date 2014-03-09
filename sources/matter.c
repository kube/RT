/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kube <kube@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/09 02:22:30 by kube              #+#    #+#             */
/*   Updated: 2014/03/09 03:00:19 by kube             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>
#include <ft_memory.h>
#include <ft_strings.h>

t_matter		*get_matter(t_env *env, char *name)
{
	t_matter	*current;

	current = env->matters;
	while (current)
	{
		if (ft_strequ(current->name, name))
			return (current);
		current = current->next;
	}
	return (0);
}

void			add_matter(t_env *env, t_matter *matter)
{
	if (!get_matter(env, matter->name))
	{
		matter->next = env->matters;
		env->matters = matter;
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
	matter->next = NULL;
	return (matter);
}
