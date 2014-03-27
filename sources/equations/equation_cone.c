/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equation_cone.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/26 18:27:36 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/03/27 20:24:49 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>
#include <ray.h>
#include <object.h>
#include <math.h>
#include <matrix.h>

float			cone_equation(t_object *cone, t_ray *ray)
{
	double	a;
	double	b;
	double	c;
	double	det;
	double	angle;

	angle = cone->aperture * (M_PI / 180);
	a = ray->direction.x * ray->direction.x + ray->direction.y * ray->direction.y - ray->direction.z * ray->direction.z
		* tan(angle) * tan(angle);
	b = 2 * (ray->origin.x * ray->direction.x + ray->origin.y * ray->direction.y - ray->direction.x * cone->origin.x
		- ray->direction.y * cone->origin.y + (ray->direction.z * (cone->origin.z - ray->origin.z))
			* tan(angle) * tan(angle));
	c = ray->origin.x * ray->origin.x + ray->origin.y * ray->origin.y + cone->origin.x * cone->origin.x
		+ cone->origin.y * cone->origin.y - 2 * (ray->origin.x * cone->origin.x + ray->origin.y * cone->origin.y)
			- (ray->origin.z * ray->origin.z - 2 * (ray->origin.z * cone->origin.z) + cone->origin.z * cone->origin.z)
				* tan(angle) * tan(angle);
	det = b * b - 4 * a * c;
	if (det >= 0)
	{
		det = sqrt(det);
		return (positive_smallest((-b + det) / (2 * a), (-b - det) / (2 * a)));
	}
	return (INFINITY);
}
