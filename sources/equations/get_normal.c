/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_normal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/26 17:59:22 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/03/26 17:59:43 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ray.h>
#include <object.h>
#include <ft_math.h>
#include <math.h>

void			get_cylinder_normal(t_vector *normal, t_ray *ray,
									t_object *cylinder, t_point *intersection)
{
	t_vector	v;
	t_vector	project;

	(void)ray;
	// intersection->x = ray->origin.x + ray->direction.x * ray->inter_t;
	// intersection->y = ray->origin.y + ray->direction.y * ray->inter_t;
	// intersection->z = ray->origin.z + ray->direction.z * ray->inter_t;
	v.x = intersection->x - cylinder->origin.x;
	v.y = intersection->y - cylinder->origin.y;
	v.z = intersection->z - cylinder->origin.z;
	project.x = vect_dot(&v, &cylinder->normal) * cylinder->normal.x;
	project.y = vect_dot(&v, &cylinder->normal) * cylinder->normal.y;
	project.z = vect_dot(&v, &cylinder->normal) * cylinder->normal.z;
	normal->x = v.x - project.x;
	normal->y = v.y - project.y;
	normal->z = v.z - project.z;
	normalize_vector(normal);
}
