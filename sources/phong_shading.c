/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong_shading.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/11 19:10:43 by lbinet            #+#    #+#             */
/*   Updated: 2014/03/12 02:22:56 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>
#include <ray.h>
#include <object.h>
#include <ft_math.h>
#include <math.h>

#include <stdio.h>

// static float	min(float a, float b)
// {
// 	if (a > b)
// 		return b;
// 	return a;
// }

static void		ambient_lightning(t_ray *ray)
{
	ray->color.red = ((float)ray->closest->color.red) * ray->closest->ambient / 255.0;
	ray->color.green = ((float)ray->closest->color.green) * ray->closest->ambient / 255.0;
	ray->color.blue = ((float)ray->closest->color.blue) * ray->closest->ambient / 255.0;
}

static void		diffuse_lightning(t_env *env, t_ray *ray)
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
		light_vector.x = current_light->origin.x - intersection.x;
		light_vector.y = current_light->origin.y - intersection.y;
		light_vector.z = current_light->origin.z - intersection.z;
		normalize_vector(&light_vector);
		lambert = fmax(vect_dot(&normal, &light_vector), 0);
		// lambert *= lambert;
		ray->color.red += lambert * 1.0;//((float)ray->closest->color.red * ray->closest->diffuse * current_light->color.red * current_light->intensity / 255.0);
		ray->color.green += lambert * 1.0;//((float)ray->closest->color.green * ray->closest->diffuse * current_light->color.green * current_light->intensity / 255.0);
		ray->color.blue += lambert * 1.0;	//((float)ray->closest->color.blue * ray->closest->diffuse * current_light->color.blue * current_light->intensity / 255.0);
		current_light = current_light->next;
	}
}

void			phong_shading(t_env *env, t_ray *ray)
{
	ambient_lightning(ray);
	diffuse_lightning(env, ray);
	// ray->f_color.red = min(ray->color.red * 255 / DIAPHRAGM, 255);
	// ray->f_color.green = min(ray->color.green * 255 / DIAPHRAGM, 255);
	// ray->f_color.blue = min(ray->color.blue * 255 / DIAPHRAGM, 255);
}