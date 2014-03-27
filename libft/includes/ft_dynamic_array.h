/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dynamic_array.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kube <kube@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/18 01:32:14 by kube              #+#    #+#             */
/*   Updated: 2014/03/18 03:06:42 by kube             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DYNAMIC_ARRAY_H
# define FT_DYNAMIC_ARRAY_H

# include <stddef.h>

typedef struct							s_dynamic_array_segment
{
	size_t								start;
	size_t								last;
	void								**data;
	struct s_dynamic_array_segment		*next;
}										t_dynamic_array_segment;

typedef struct							s_dynamic_array
{
	size_t								segment_alloc_size;
	t_dynamic_array_segment				*first_segment;
	t_dynamic_array_segment				*last_segment;
}										t_dynamic_array;

void				dynamic_array_set(t_dynamic_array *array,
										unsigned int index,
										void *value);
void				*dynamic_array_get(t_dynamic_array *array,
										unsigned int index);
void				dynamic_array_push(t_dynamic_array *array,
										void *data);
t_dynamic_array		*new_dynamic_array(size_t segment_alloc_size);

#endif
