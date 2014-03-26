/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equation_cylinder.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/23 21:05:44 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/03/26 19:24:52 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>
#include <ray.h>
#include <object.h>
#include <math.h>
#include <matrix.h>

float			cylinder_equation(t_object *cylinder, t_ray *origin_ray)
{
	float		a;
	float		b;
	float		c;
	float		det;
	float		res;

	t_ray		ray;


	change_ray(origin_ray, &ray, cylinder);

	a = ray.direction.x * ray.direction.x + ray.direction.y * ray.direction.y;
	b = 2 * (ray.origin.x * ray.direction.x + ray.origin.y * ray.direction.y
		- ray.direction.x * cylinder->origin.x - ray.direction.y * cylinder->origin.y);
	c = ray.origin.x * ray.origin.x + ray.origin.y * ray.origin.y + cylinder->origin.x * cylinder->origin.x
		+ cylinder->origin.y * cylinder->origin.y - cylinder->radius * cylinder->radius - 2 * (ray.origin.x * cylinder->origin.x
		+ ray.origin.y * cylinder->origin.y);
	det = b * b - 4 * a * c;
	if (det >= 0)
	{
		det = sqrt(det);
		res = positive_smallest((-b + det) / (2 * a), (-b -det) / (2 * a));
		return (res);
	}
	return (INFINITY);
}
