/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_throw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/05 18:07:34 by lbinet            #+#    #+#             */
/*   Updated: 2014/03/26 18:34:51 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>
#include <ray.h>
#include <object.h>
#include <stdlib.h>
#include <math.h>

static float	intersection(t_object *obj, t_ray *ray)
{
	if (obj->type == OBJ_SPHERE)
		return (sphere_equation(obj, ray));
	else if (obj->type == OBJ_PLANE)
		return (plane_equation(obj, ray));
	else if (obj->type == OBJ_CYLINDER)
		return (cylinder_equation(obj, ray));
	else if (obj->type == OBJ_CONE)
		return (cone_equation(obj, ray));
	return (INFINITY);
}

static void		calculate_reflected(t_ray *a, t_ray *b)
{
	t_vector	n;
	t_point		intersection;

	intersection.x = a->origin.x + a->direction.x * a->inter_t;
	intersection.y = a->origin.y + a->direction.y * a->inter_t;
	intersection.z = a->origin.z + a->direction.z * a->inter_t;
	if (a->closest->type == OBJ_SPHERE)
	{
		n.x = intersection.x - a->closest->origin.x;
		n.y = intersection.y - a->closest->origin.y;
		n.z = intersection.z - a->closest->origin.z;
	}
	else
		n = a->closest->normal;
	b->origin.x = intersection.x;
	b->origin.y = intersection.y;
	b->origin.z = intersection.z;
	a->direction.x = -a->direction.x;
	a->direction.y = -a->direction.y;
	a->direction.z = -a->direction.z;
	b->direction.x = 2 * (vect_dot(&n, &a->direction)) * n.x - a->direction.x;
	b->direction.y = 2 * (vect_dot(&n, &a->direction)) * n.y - a->direction.y;
	b->direction.z = 2 * (vect_dot(&n, &a->direction)) * n.z - a->direction.z;
	normalize_vector(&b->direction);
}

void			throw_ray(t_ray *ray, int calculate_light,
							t_object *to_ignore, int recursivity)
{
	float		tmp_t;
	t_object	*obj;
	t_ray		reflected;

	obj = env->scene->objects;
	ray->inter_t = INFINITY;
	ray->closest = NULL;
	ray->color.red = 0.0;
	ray->color.green = 0.0;
	ray->color.blue = 0.0;
	while (obj)
	{
		if (!to_ignore || obj != to_ignore)
		{
			tmp_t = intersection(obj, ray);
			ray->closest = (tmp_t < ray->inter_t) ? obj : ray->closest;
			ray->inter_t = (tmp_t < ray->inter_t) ? tmp_t : ray->inter_t;
			tmp_t = INFINITY;
		}
		obj = obj->next;
	}
	if (calculate_light && ray->inter_t != INFINITY)
	{
		phong_shading(ray);
		if (ray->closest->reflection > 0.0 && recursivity > 0)
		{
			calculate_reflected(ray, &reflected);
			throw_ray(&reflected, 1, ray->closest, recursivity - 1);
			ray->color.red *= (1 - ray->closest->reflection);
			ray->color.green *= (1 - ray->closest->reflection);
			ray->color.blue *= (1 - ray->closest->reflection);
			if (reflected.closest)
				ray->color.r += ray->closest->reflection * reflected.color.r;
				ray->color.g += ray->closest->reflection * reflected.color.g;
				ray->color.b += ray->closest->reflection * reflected.color.b;
		}
	}
}
