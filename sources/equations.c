/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbinet <lbinet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/05 19:30:09 by lbinet            #+#    #+#             */
/*   Updated: 2014/03/11 19:04:18 by lbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>
#include <ray.h>
#include <object.h>
#include <math.h>

static float	positive_smallest(float a, float b)
{
	if (a < 0)
	{
		if (b > 0)
			return (b);
		return (INFINITY);
	}
	if (b < 0)
	{
		if (a > 0)
			return (a);
		return (INFINITY);
	}
	if (a < b)
		return (a);
	return (b);
}

float			sphere_equation(t_object *sphere, t_ray *ray)
{
	float	a;
	float	b;
	float	c;
	float	det;
	float	res;

	a = ray->direction.x * ray->direction.x + ray->direction.y
		* ray->direction.y + ray->direction.z * ray->direction.z;
	b = 2 * (ray->direction.x * (ray->origin.x - sphere->origin.x)
		+ ray->direction.y * (ray->origin.y - sphere->origin.y)
			+ ray->direction.z * (ray->origin.z - sphere->origin.z));
	c = (ray->origin.x - sphere->origin.x) * (ray->origin.x - sphere->origin.x)
		+ (ray->origin.y - sphere->origin.y)
		* (ray->origin.y - sphere->origin.y)
		+ (ray->origin.z - sphere->origin.z)
		* (ray->origin.z - sphere->origin.z) - sphere->radius * sphere->radius;
	det = b * b - 4 * a * c;
	if (det >= 0)
	{
		res = positive_smallest((-b + sqrt(det)) / (2 * a),
				(-b - sqrt(det)) / (2 * a));
		return (res);
	}
	return (INFINITY);
}

float		plane_equation(t_object *plane, t_ray *ray)
{
	float	n;
	float	d;
	float	res;

	n = plane->normal.x * (plane->origin.x - ray->origin.x)
		+ plane->normal.y * (plane->origin.y - ray->origin.y)
		+ plane->normal.z * (plane->origin.z - ray->origin.z);
	d = plane->normal.x * ray->direction.x
		+ plane->normal.y * ray->direction.y
		+ plane->normal.z * ray->direction.z;
	if ((res = n / d) > 0)
		return (res);
	return (INFINITY);
}
