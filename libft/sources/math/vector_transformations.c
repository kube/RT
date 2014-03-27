/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_transformations.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kube <kube@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/19 01:51:22 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/03/10 02:13:39 by kube             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_math.h>

#ifdef USE_MATH
# include <math.h>
# define COS cos
# define SIN sin
#else
# define COS ft_cos
# define SIN ft_sin
#endif

void			vect_rot_z(t_vector *v, float angle)
{
	t_point		a;

	a.x = v->x;
	a.y = v->y;
	v->x = a.x * COS(angle) - a.y * SIN(angle);
	v->y = a.x * SIN(angle) + a.y * COS(angle);
}

void			vect_rot_x(t_vector *v, float angle)
{
	t_point		a;

	a.y = v->y;
	a.z = v->z;
	v->y = a.y * SIN(angle) + a.z * COS(angle);
	v->z = a.y * COS(angle) - a.z * SIN(angle);
}

void			vect_rot_y(t_vector *v, float angle)
{
	t_point		a;

	a.x = v->x;
	a.z = v->z;
	v->x = a.z * SIN(angle) + a.x * COS(angle);
	v->z = a.z * COS(angle) - a.x * SIN(angle);
}

void			vect_scale(t_vector *v, float coeff)
{
	v->x *= coeff;
	v->y *= coeff;
	v->z *= coeff;
}

void			normalize_vector(t_vector *a)
{
	float		norm;

	norm = vect_norm(a);
	a->x /= norm;
	a->y /= norm;
	a->z /= norm;
}
