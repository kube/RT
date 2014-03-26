/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equation_sphere.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/26 18:28:42 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/03/26 18:46:27 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>
#include <ray.h>
#include <object.h>
#include <math.h>

static float	sphere_equation_det(t_object *s, t_ray *ray, float *a, float *b)
{
	t_vector	ray_direction;
	t_point		ray_origin;
	t_point		s_origin;
	float		radius;
	float		c;

	ray_direction = ray->direction;
	ray_origin = ray->origin;
	s_origin = s->origin;
	radius = s->radius;
	*a = ray_direction.x * ray_direction.x + ray_direction.y
		* ray_direction.y + ray_direction.z * ray_direction.z;
	*b = 2 * (ray_direction.x * (ray_origin.x - s_origin.x)
		+ ray_direction.y * (ray_origin.y - s_origin.y)
			+ ray_direction.z * (ray_origin.z - s_origin.z));
	c = (ray_origin.x - s_origin.x) * (ray_origin.x - s_origin.x)
		+ (ray_origin.y - s_origin.y)
		* (ray_origin.y - s_origin.y)
		+ (ray_origin.z - s_origin.z)
		* (ray_origin.z - s_origin.z) - radius * radius;
	return (c);
}

float			sphere_equation(t_object *sphere, t_ray *ray)
{
	float		res;
	float		a;
	float		b;
	float		c;
	float		det;

	c = sphere_equation_det(sphere, ray, &a, &b);
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
