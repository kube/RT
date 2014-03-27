/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_normal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/26 17:59:22 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/03/27 20:16:07 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ray.h>
#include <object.h>
#include <ft_math.h>
#include <math.h>

void			get_cylinder_normal(t_vector *normal,
									t_object *cylinder, t_point *intersection)
{
	t_vector	v;
	t_vector	project;
	float		dot;
	t_vector	n;

	n = cylinder->normal;
	if (vect_norm(&n) - 1 > 0.05)
		normalize_vector(&cylinder->normal);
	v.x = intersection->x - cylinder->origin.x;
	v.y = intersection->y - cylinder->origin.y;
	v.z = intersection->z - cylinder->origin.z;
	dot = vect_dot(&v, &cylinder->normal);
	project.x = dot * cylinder->normal.x;
	project.y = dot * cylinder->normal.y;
	project.z = dot * cylinder->normal.z;
	normal->x = v.x - project.x;
	normal->y = v.y - project.y;
	normal->z = v.z - project.z;
	normalize_vector(normal);
}

void			get_cone_normal(t_vector *normal, t_object *cone,
								t_point *intersection)
{
	t_vector	v;
	t_vector	project;
	float		dot;
	t_vector	n;

	n = cone->normal;
	if (vect_norm(&n) - 1 > 0.05)
		normalize_vector(&cone->normal);
	v.x = intersection->x - cone->origin.x;
	v.y = intersection->y - cone->origin.y;
	v.z = intersection->z - cone->origin.z;
	dot = vect_dot(&v, &cone->normal);
	project.x = dot * cone->normal.x;
	project.y = dot * cone->normal.y;
	project.z = dot * cone->normal.z;
	normal->x = v.x - project.x;
	normal->y = v.y - project.y;
	normal->z = v.z - project.z;
	normalize_vector(normal);
}
