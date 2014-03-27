/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_normal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/26 17:59:22 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/03/27 18:09:53 by cfeijoo          ###   ########.fr       */
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
