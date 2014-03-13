/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_throw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/05 18:07:34 by lbinet            #+#    #+#             */
/*   Updated: 2014/03/13 19:36:27 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>
#include <ray.h>
#include <object.h>
#include <stdlib.h>
#include <math.h>

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

void			throw_ray(t_env *env, t_ray *ray, int calculate_light)
{
	float		tmp_t;
	t_object	*obj;

	obj = env->objects;

	ray->inter_t = INFINITY;
	ray->closest = NULL;
	while (obj)
	{
		tmp_t = intersection(obj, ray);
		ray->closest = (tmp_t < ray->inter_t) ? obj : ray->closest;
		ray->inter_t = (tmp_t < ray->inter_t) ? tmp_t : ray->inter_t;
		tmp_t = INFINITY;
		obj = obj->next;
	}
	if (calculate_light && ray->inter_t != INFINITY)
		phong_shading(env, ray);
}
