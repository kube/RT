/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_throw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/05 18:07:34 by lbinet            #+#    #+#             */
/*   Updated: 2014/03/22 18:12:53 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>
#include <ray.h>
#include <object.h>
#include <stdlib.h>
#include <math.h>


#include <stdio.h>

static float	intersection(t_object *obj, t_ray *ray)
{
	/*
	**	Should use functions tabled here (Better performance)
	*/

	if (obj->type == OBJ_SPHERE)
		return (sphere_equation(obj, ray));
	else if (obj->type == OBJ_PLANE)
		return (plane_equation(obj, ray));
	/*if (obj->type == OBJ_CYLINDER)
		return (cylinder_equation(obj, ray));
	if (obj->type == OBJ_CONE)
		return (cone_equation(obj, ray));*/
	return (INFINITY);
}

static void		calculate_reflected_ray(t_ray *ray, t_ray *reflected_ray)
{
	t_vector	normal;
	t_point		intersection;

	intersection.x = ray->origin.x + ray->direction.x * ray->inter_t;
	intersection.y = ray->origin.y + ray->direction.y * ray->inter_t;
	intersection.z = ray->origin.z + ray->direction.z * ray->inter_t;

	if (ray->closest->type == OBJ_SPHERE)
	{
		normal.x = intersection.x - ray->closest->origin.x;
		normal.y = intersection.y - ray->closest->origin.y;
		normal.z = intersection.z - ray->closest->origin.z;
	}
	else
		normal = ray->closest->normal;
	reflected_ray->origin.x = intersection.x;
	reflected_ray->origin.y = intersection.y;
	reflected_ray->origin.z = intersection.z;
	ray->direction.x = -ray->direction.x;
	ray->direction.y = -ray->direction.y;
	ray->direction.z = -ray->direction.z;
	reflected_ray->direction.x = 2 * (vect_dot(&normal, &ray->direction)) * normal.x - ray->direction.x;
	reflected_ray->direction.y = 2 * (vect_dot(&normal, &ray->direction)) * normal.y - ray->direction.y;
	reflected_ray->direction.z = 2 * (vect_dot(&normal, &ray->direction)) * normal.z - ray->direction.z;
	normalize_vector(&reflected_ray->direction);
}

void			throw_ray(t_ray *ray, int calculate_light,
							t_object *to_ignore, int recursivity)
{
	float		tmp_t;
	t_object	*obj;
	t_ray		reflected_ray;

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
			calculate_reflected_ray(ray, &reflected_ray);
			throw_ray(&reflected_ray, 1, ray->closest, recursivity - 1);

			ray->color.red *= (1 - ray->closest->reflection);
			ray->color.green *= (1 - ray->closest->reflection);
			ray->color.blue *= (1 - ray->closest->reflection);
			if (reflected_ray.closest)
				ray->color.red += ray->closest->reflection * reflected_ray.color.red;
				ray->color.green += ray->closest->reflection * reflected_ray.color.green;
				ray->color.blue += ray->closest->reflection * reflected_ray.color.blue;
		}
	}
}
