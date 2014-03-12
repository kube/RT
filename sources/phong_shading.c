/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong_shading.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/11 19:10:43 by lbinet            #+#    #+#             */
/*   Updated: 2014/03/12 14:26:12 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>
#include <ray.h>
#include <object.h>
#include <ft_math.h>
#include <math.h>

static void		ambient_lighting(t_ray *ray)
{
	ray->color.red = ((float)ray->closest->color.red) * ray->closest->ambient / 255.0;
	ray->color.green = ((float)ray->closest->color.green) * ray->closest->ambient / 255.0;
	ray->color.blue = ((float)ray->closest->color.blue) * ray->closest->ambient / 255.0;
}

static void		diffuse_lighting(t_env *env, t_ray *ray)
{
	t_vector	light_vector;
	t_vector	normal;
	t_point		intersection;
	float		lambert;
	t_light		*current_light;

	intersection.x = ray->origin.x + ray->direction.x * ray->inter_t;
	intersection.y = ray->origin.y + ray->direction.y * ray->inter_t;
	intersection.z = ray->origin.z + ray->direction.z * ray->inter_t;
	normal.x = intersection.x - ray->closest->origin.x;
	normal.y = intersection.y - ray->closest->origin.y;
	normal.z = intersection.z - ray->closest->origin.z;
	normalize_vector(&normal);
	current_light = env->lights;
	while (current_light)
	{
		/*
		**	Check Light Intersection !
		*/
		light_vector.x = current_light->origin.x - intersection.x;
		light_vector.y = current_light->origin.y - intersection.y;
		light_vector.z = current_light->origin.z - intersection.z;
		normalize_vector(&light_vector);
		lambert = fmax(vect_dot(&normal, &light_vector), 0);
		lambert *= lambert * lambert;
		ray->color.red += lambert * ((float)ray->closest->color.red * ray->closest->diffuse * current_light->color.red * current_light->intensity / 255.0);
		ray->color.green += lambert * ((float)ray->closest->color.green * ray->closest->diffuse * current_light->color.green * current_light->intensity / 255.0);
		ray->color.blue += lambert * ((float)ray->closest->color.blue * ray->closest->diffuse * current_light->color.blue * current_light->intensity / 255.0);
		current_light = current_light->next;
	}
}

static void		specular_lighting(t_env *env, t_ray *ray)
{
	t_vector	light_vector;
	t_vector	normal;
	t_point		intersection;
	float		phong;
	t_light		*current_light;

	intersection.x = ray->origin.x + ray->direction.x * ray->inter_t;
	intersection.y = ray->origin.y + ray->direction.y * ray->inter_t;
	intersection.z = ray->origin.z + ray->direction.z * ray->inter_t;
	normal.x = intersection.x - ray->closest->origin.x;
	normal.y = intersection.y - ray->closest->origin.y;
	normal.z = intersection.z - ray->closest->origin.z;
	normalize_vector(&normal);
	current_light = env->lights;
	while (current_light)
	{
		/*
		**	Check Light Intersection !
		*/
		light_vector.x = current_light->origin.x - intersection.x;
		light_vector.y = current_light->origin.y - intersection.y;
		light_vector.z = current_light->origin.z - intersection.z;
		normalize_vector(&light_vector);
		phong = fmax(vect_dot(&normal, &light_vector), 0);
		phong = pow(phong, 900);
		ray->color.red += phong * ((float)ray->closest->color.red * ray->closest->specular * current_light->color.red * current_light->intensity / 255.0);
		ray->color.green += phong * ((float)ray->closest->color.green * ray->closest->specular * current_light->color.green * current_light->intensity / 255.0);
		ray->color.blue += phong * ((float)ray->closest->color.blue * ray->closest->specular * current_light->color.blue * current_light->intensity / 255.0);
		current_light = current_light->next;
	}
}

void			phong_shading(t_env *env, t_ray *ray)
{
	ambient_lighting(ray);
	diffuse_lighting(env, ray);
	specular_lighting(env, ray);
}