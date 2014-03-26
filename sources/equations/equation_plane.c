/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equation_plane.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/26 18:29:42 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/03/26 18:30:38 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>
#include <ray.h>
#include <object.h>
#include <math.h>

float			plane_equation(t_object *plane, t_ray *ray)
{
	float		n;
	float		d;
	float		res;

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
