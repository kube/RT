/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/10 02:14:08 by kube              #+#    #+#             */
/*   Updated: 2014/03/26 19:42:51 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_math.h>

t_vector		*vector_add(t_vector *a, t_vector *b, float coeff)
{
	a->x += b->x * coeff;
	a->y += b->y * coeff;
	a->z += b->z * coeff;
	return (a);
}

t_vector		vect_product(t_vector *a, t_vector *b)
{
	t_vector	c;

	c.x = a->y * b->z - a->z * b->y;
	c.y = a->z * b->x - a->x * b->z;
	c.z = a->x * b->y - a->y * b->x;
	return (c);
}
