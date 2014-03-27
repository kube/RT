/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dynamic_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kube <kube@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/18 01:31:26 by kube              #+#    #+#             */
/*   Updated: 2014/03/18 03:06:28 by kube             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_dynamic_array.h>
#include <ft_memory.h>
#include <stdlib.h>

static void					add_segment(t_dynamic_array *array)
{
	t_dynamic_array_segment	*segment;

	segment = (t_dynamic_array_segment*)malloc(sizeof(t_dynamic_array_segment));
	if (array->last_segment)
		segment->start = array->last_segment->start + array->segment_alloc_size;
	else
		segment->start = 0;
	segment->last = 0;
	segment->data = ft_memalloc(array->segment_alloc_size * sizeof(void*));
	segment->next = NULL;
	if (!array->first_segment)
		array->first_segment = segment;
	else
		array->last_segment->next = segment;
	array->last_segment = segment;
}

void						dynamic_array_set(t_dynamic_array *array,
												unsigned int index,
												void *value)
{
	t_dynamic_array_segment	*current;

	while (array->last_segment->start + array->segment_alloc_size <= index)
		add_segment(array);
	/*
	**	Optimization to do here
	*/
	current = array->first_segment;
	while (current->start + array->segment_alloc_size < index)
		current = current->next;
	current->data[index - array->last_segment->start] = value;
	if (current->last < index - current->start)
		current->last = index - current->start;
}

void						*dynamic_array_get(t_dynamic_array *array,
												unsigned int index)
{
	t_dynamic_array_segment	*current;

	if (array->last_segment->start + array->segment_alloc_size <= index)
		return (NULL);
	/*
	**	Optimization to do here
	*/
	current = array->first_segment;
	while (current->start + array->segment_alloc_size < index)
		current = current->next;
	return (current->data[index - array->last_segment->start]);
}

void						dynamic_array_push(t_dynamic_array *array,
												void *data)
{
	array->last_segment->data[array->last_segment->last] = data;
	array->last_segment->last++;
	if (array->last_segment->last == array->segment_alloc_size)
		add_segment(array);
}

t_dynamic_array				*new_dynamic_array(size_t segment_alloc_size)
{
	t_dynamic_array			*array;

	array = (t_dynamic_array*)malloc(sizeof(t_dynamic_array));
	array->segment_alloc_size = segment_alloc_size;
	array->first_segment = NULL;
	array->last_segment = NULL;
	add_segment(array);
	return (array);
}

