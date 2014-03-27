/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong_shading.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/11 19:10:43 by lbinet            #+#    #+#             */
/*   Updated: 2014/03/27 20:14:38 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>
#include <ray.h>
#include <object.h>
#include <ft_math.h>
#include <ft_memory.h>
#include <math.h>

static t_point	get_point_from_ray_intersection(t_ray *ray, float t)
{
	t_point		point;

	point.x = ray->origin.x + ray->direction.x * t;
	point.y = ray->origin.y + ray->direction.y * t;
	point.z = ray->origin.z + ray->direction.z * t;
	return (point);
}

static float	is_point_exposed_to_light(t_object *object,
											t_point point, t_light *light)
{
	t_ray		ray;
	float		distance_to_light;

	ray.origin.x = point.x;
	ray.origin.y = point.y;
	ray.origin.z = point.z;
	ray.direction.x = light->origin.x - ray.origin.x;
	ray.direction.y = light->origin.y - ray.origin.y;
	ray.direction.z = light->origin.z - ray.origin.z;
	distance_to_light = vect_norm(&ray.direction);
	normalize_vector(&ray.direction);
	throw_ray(&ray, 0, object, 0);
	if (ray.inter_t <= distance_to_light)
		return (0);
	return (1);
}

static void		ambient_lighting(t_ray *ray)
{
	ray->color.red = ((float)ray->closest->color.red)
						* ray->closest->ambient / 255.0;
	ray->color.green = ((float)ray->closest->color.green)
						* ray->closest->ambient / 255.0;
	ray->color.blue = ((float)ray->closest->color.blue)
						* ray->closest->ambient / 255.0;
}

static float	phong_lighting(t_ray *ray)
{
	t_vector	light_vector;
	t_vector	normal;
	t_point		intersection;
	float		lambert;
	t_light		*light;
	t_vector	reflect_light;
	float		specular;
	t_vector	camera;

	intersection = get_point_from_ray_intersection(ray, ray->inter_t);
	if (ray->closest->type == OBJ_SPHERE)
	{
		normal.x = intersection.x - ray->closest->origin.x;
		normal.y = intersection.y - ray->closest->origin.y;
		normal.z = intersection.z - ray->closest->origin.z;
	}
	else if (ray->closest->type == OBJ_CYLINDER)
		get_cylinder_normal(&normal, ray->closest, &intersection);
	else if (ray->closest->type == OBJ_CONE)
		get_cone_normal(&normal, ray->closest, &intersection);
	else
		normal = ray->closest->normal;
	normalize_vector(&normal);
	light = env->scene->lights;
	while (light)
	{
		if (is_point_exposed_to_light(ray->closest, intersection, light))
		{
			light_vector.x = light->origin.x - intersection.x;
			light_vector.y = light->origin.y - intersection.y;
			light_vector.z = light->origin.z - intersection.z;
			normalize_vector(&light_vector);
			lambert = vect_dot(&normal, &light_vector);
			if (lambert > 0)
			{
				ray->color.red += lambert * ((float)ray->closest->color.red
								* ray->closest->diffuse * light->color.red
								* light->intensity / 255.0);
				ray->color.green += lambert * ((float)ray->closest->color.green
								* ray->closest->diffuse * light->color.green
								* light->intensity / 255.0);
				ray->color.blue += lambert * ((float)ray->closest->color.blue
								* ray->closest->diffuse * light->color.blue
								* light->intensity / 255.0);
			}
				reflect_light.x = 2 * vect_dot(&normal, &light_vector) * normal.x - light_vector.x;
				reflect_light.y = 2 * vect_dot(&normal, &light_vector) * normal.y - light_vector.y;
				reflect_light.z = 2 * vect_dot(&normal, &light_vector) * normal.z - light_vector.z;
				normalize_vector(&reflect_light);
				camera.x = env->scene->camera.origin.x - intersection.x;
				camera.y = env->scene->camera.origin.y - intersection.y;
				camera.z = env->scene->camera.origin.z - intersection.z;
				normalize_vector(&camera);
				specular = ray->closest->specular * pow(fmax(0, vect_dot(&reflect_light, &camera)), 500);
				if (specular > 0)
				{
					ray->color.red += specular * (ray->closest->specular * light->intensity);
					ray->color.green += specular * (ray->closest->specular * light->intensity);
					ray->color.blue += specular * (ray->closest->specular * light->intensity);
				}
		}
		light = light->next;
	}
	return (lambert);
}

void			phong_shading(t_ray *ray)
{
	ambient_lighting(ray);
	phong_lighting(ray);
}
