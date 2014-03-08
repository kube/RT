/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_throw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbinet <lbinet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/05 18:07:34 by lbinet            #+#    #+#             */
/*   Updated: 2014/03/08 18:18:47 by lbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>
#include <ray.h>
#include <object.h>
#include <stdlib.h>
#include <math.h>

static float	intersection(t_object *obj, t_ray *ray)
{
	if (obj->type == 1)
		return (sphere_equation(obj, ray));
	if (obj->type == 2)
		return (plane_equation(obj, ray));
	/*if (obj->type == 3)
		return (cylinder_equation(obj, ray));
	if (obj->type == 4)
		return (cone_equation(obj, ray));*/
	return (INFINITY);
}

void			throw_ray(t_env *env, t_ray *ray)
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
}