/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_throw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/05 18:07:34 by lbinet            #+#    #+#             */
/*   Updated: 2014/03/27 20:11:36 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>
#include <ray.h>
#include <object.h>
#include <stdlib.h>
#include <math.h>

static float	intersection(t_object *obj, t_ray *ray)
{
	t_ray		new_ray;
	t_object	new_obj;

	new_ray = *ray;
	new_obj = *obj;
	if (obj->type == OBJ_SPHERE)
		return (sphere_equation(obj, ray));
	else if (obj->type == OBJ_PLANE)
		return (plane_equation(obj, ray));
	if (obj->type == OBJ_CYLINDER)
	{
		change_ray(ray, &new_ray, obj, &new_obj);
		return (cylinder_equation(&new_obj, &new_ray));
	}
	if (obj->type == OBJ_CONE)
	{
		change_ray(ray, &new_ray, obj, &new_obj);
		return (cone_equation(&new_obj, &new_ray));
	}
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
	else if (ray->closest->type == OBJ_CYLINDER)
		get_cylinder_normal(&n, ray->closest, &intersection);
	else if (ray->closest->type == OBJ_CONE)
		get_cone_normal(&n, ray->closest, &intersection);
	else
		n = a->closest->normal;
	b->origin = intersection;
	vect_scale(a->direction, -1);
	b->direction.x = 2 * (vect_dot(&n, &a->direction)) * n.x - a->direction.x;
	b->direction.y = 2 * (vect_dot(&n, &a->direction)) * n.y - a->direction.y;
	b->direction.z = 2 * (vect_dot(&n, &a->direction)) * n.z - a->direction.z;
	normalize_vector(&b->direction);
}

t_ray			get_ray_from_point(float i, float j)
{
	t_ray		ray;

	ray.origin.x = env->scene->render_cam.origin.x;
	ray.origin.y = env->scene->render_cam.origin.y;
	ray.origin.z = env->scene->render_cam.origin.z;
	ray.direction.x = env->scene->render_cam.x_axis.x;
	ray.direction.y = env->scene->render_cam.x_axis.y;
	ray.direction.z = env->scene->render_cam.x_axis.z;
	i -= env->scene->view_width / 2;
	j -= env->scene->view_height / 2;
	ray.direction.x -= (env->scene->render_cam.y_axis.x / VIEWPLANE_PLOT) * i;
	ray.direction.y -= (env->scene->render_cam.y_axis.y / VIEWPLANE_PLOT) * i;
	ray.direction.z -= (env->scene->render_cam.y_axis.z / VIEWPLANE_PLOT) * i;
	ray.direction.x -= (env->scene->render_cam.z_axis.x / VIEWPLANE_PLOT) * j;
	ray.direction.y -= (env->scene->render_cam.z_axis.y / VIEWPLANE_PLOT) * j;
	ray.direction.z -= (env->scene->render_cam.z_axis.z / VIEWPLANE_PLOT) * j;
	return (ray);
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
