/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_ray.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/26 13:08:39 by lbinet            #+#    #+#             */
/*   Updated: 2014/03/27 17:17:33 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ray.h>
#include <object.h>
#include <ft_math.h>
#include <math.h>
#include <matrix.h>

void			change_ray(t_ray *ray, t_ray *new_ray, t_object *obj)
{
	float		matrix[9];
	float		inverted_matrix[9];
	t_vector	x;
	t_vector	y;
	t_vector	z;

	z = obj->normal;
	if (z.x == 0 && z.y == 0 && (z.z == 1 || z.z == -1))
		return ;
	if ((z.x == 1 || z.x == -1) && z.y == 0 && z.y == 0)
	{
		x.x = 0;
		x.y = 1;
		x.z = 0;
		y.x = 0;
		y.y = 0;
		y.z = 1;
	}
	else if (z.x == 0 && (z.y == 1 || z.y == -1) && z.z == 0)
	{
		x.x = 0;
		x.y = 0;
		x.z = 1;
		y.x = 1;
		y.y = 0;
		y.z = 0;
	}
	else
	{
		normalize_vector(&z);
		y.x = -z.y;
		y.y = z.x;
		y.z = 0;
		normalize_vector(&y);
		x = vect_product(&y, &z);
		normalize_vector(&x);
	}
	transformation_matrix(matrix, &x, &y, &z);
	invert_matrix(matrix, inverted_matrix);
	new_ray->origin = matrix_point_product(inverted_matrix, &ray->origin);
	new_ray->direction = matrix_vector_product(inverted_matrix, &ray->direction);
}
