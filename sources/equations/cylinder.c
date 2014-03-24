/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/23 21:05:44 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/03/24 01:16:06 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>
#include <ray.h>
#include <object.h>
#include <math.h>

static float	ctos(float a)
{
	return (sqrt(1 - a));
}

static float	cylinder_equation_det(t_object *cy, t_ray *ray, float *a,
										float *b)
{
	t_vector	ray_direction;
	t_point		ray_origin;
	t_point		cy_origin;
	float		radius;
	float		c;

	ray_direction = ray->direction;
	ray_origin = ray->origin;
	cy_origin = cy->origin;
	radius = cy->radius;
	*a = ctos(cy->normal.x) * ray_direction.x * ray_direction.x
		+ ctos(cy->normal.y) * ray_direction.y * ray_direction.y
		+ ctos(cy->normal.z) * ray_direction.z * ray_direction.z;

	*b = 2 * (ctos(cy->normal.x) * ray_direction.x * (ray_origin.x - cy_origin.x)
		+ ctos(cy->normal.y) * ray_direction.y * (ray_origin.y - cy_origin.y)
		+ ctos(cy->normal.z) * ray_direction.z * (ray_origin.z - cy_origin.z));

	c = ctos(cy->normal.x) * (ray_origin.x - cy_origin.x) * (ray_origin.x - cy_origin.x)
		+ ctos(cy->normal.y) * (ray_origin.y - cy_origin.y) * (ray_origin.y - cy_origin.y)
		+ ctos(cy->normal.z) * (ray_origin.z - cy_origin.z) * (ray_origin.z - cy_origin.z)
		- radius * radius;
	return (c);
}

float			cylinder_equation(t_object *cylinder, t_ray *ray)
{
	float		res;
	float		a;
	float		b;
	float		c;
	float		det;

	c = cylinder_equation_det(cylinder, ray, &a, &b);
	det = b * b - 4 * a * c;
	if (det	>= 0)
	{
		det = sqrt(det);
		res = positive_smallest((-b + det) / (2 * a),
				(-b - det) / (2 * a));
		return (res);
	}
	return (INFINITY);

}
