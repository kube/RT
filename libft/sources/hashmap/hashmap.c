/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/19 23:40:35 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/02/20 00:36:30 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_hashmap.h>
#include <ft_strings.h>
#include <ft_convert.h>
#include <ft_memory.h>
#include <stdlib.h>

t_hashmap_var		*set_var(unsigned int hash, char *name, void *object)
{
	t_hashmap_var	*new_var;

	if (!(new_var = (t_hashmap_var*)malloc(sizeof(t_hashmap_var))))
		exit(1);
	new_var->hash = hash;
	new_var->name = ft_strdup(name);
	new_var->object = object;
	new_var->next = 0;
	return (new_var);
}

t_hashmap_var		*get_var(unsigned int hash, char *name, t_hashmap *hashmap)
{
	t_hashmap_var			*current;

	if (hashmap->vars[hash % hashmap->size])
	{
		current = hashmap->vars[hash % hashmap->size];
		while (current)
		{
			if (current->hash == hash && ft_strequ(current->name, name))
				return (current);
			current = current->next;
		}
	}
	return (0);
}

int					index_var(char *name, void *object, t_hashmap *hashmap)
{
	unsigned int	index;
	unsigned int	hash;
	char			*toupdate;
	t_hashmap_var	*new_var;

	hash = basic_hash(name);
	if ((new_var = get_var(hash, name, hashmap)))
	{
		toupdate = new_var->object;
		new_var->object = object;
		free(toupdate);
		return (0);
	}
	new_var = set_var(hash, name, object);
	index = hash % hashmap->size;
	if (hashmap->vars[index])
		new_var->next = hashmap->vars[index];
	hashmap->vars[index] = new_var;
	return (0);
}

t_hashmap			*create_hashmap(unsigned int size)
{
	unsigned int	i;
	t_hashmap		*hashmap;

	i = 0;
	hashmap = ft_memalloc(sizeof(t_hashmap));
	hashmap->size = size;
	hashmap->vars = ft_memalloc(size * sizeof(t_hashmap_var));
	return (hashmap);
}
