/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/25 04:31:53 by lbinet            #+#    #+#             */
/*   Updated: 2014/03/27 17:15:28 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ray.h>
#include <object.h>
#include <ft_math.h>
#include <math.h>

t_vector		matrix_vector_product(float matrix[9], t_vector *a)
{
	t_vector	b;

	b.x = matrix[0] * a->x + matrix[1] * a->y + matrix[2] * a->z;
	b.y = matrix[3] * a->x + matrix[4] * a->y + matrix[5] * a->z;
	b.z = matrix[6] * a->x + matrix[7] * a->y + matrix[8] * a->z;
	return (b);
}

t_point			matrix_point_product(float matrix[9], t_point *a)
{
	t_point		b;

	b.x = matrix[0] * a->x + matrix[1] * a->y + matrix[2] * a->z;
	b.y = matrix[3] * a->x + matrix[4] * a->y + matrix[5] * a->z;
	b.z = matrix[6] * a->x + matrix[7] * a->y + matrix[8] * a->z;
	return (b);
}

void			transformation_matrix(float matrix[9], t_vector *x,
										t_vector *y, t_vector *z)
{
	matrix[0] = x->x;
	matrix[1] = y->x;
	matrix[2] = z->x;
	matrix[3] = x->y;
	matrix[4] = y->y;
	matrix[5] = z->y;
	matrix[6] = x->z;
	matrix[7] = y->z;
	matrix[8] = z->z;
}

void			invert_matrix(float matrix[9], float inverted_matrix[9])
{
	float		det;

	det = matrix[0] * (matrix[4] * matrix[8] - matrix[7] * matrix[5])
			- matrix[1] * (matrix[3] * matrix[8] - matrix[6] * matrix[5])
			+ matrix[2] * (matrix[3] * matrix[7] - matrix[6] * matrix[4]);
	if (fabs(det) < 0.0005)
		return ;
	inverted_matrix[0] = matrix[4] * matrix[8] - matrix[5] * matrix[7] / det;
	inverted_matrix[1] = -(matrix[1] * matrix[8] - matrix[7] * matrix[2]) / det;
	inverted_matrix[2] = matrix[1] * matrix[5] - matrix[4] * matrix[2] / det;
	inverted_matrix[3] = -(matrix[3] * matrix[8] - matrix[5] * matrix[6]) / det;
	inverted_matrix[4] = matrix[0] * matrix[8] - matrix[6] * matrix[2] / det;
	inverted_matrix[5] = -(matrix[0] * matrix[5] - matrix[3] * matrix[2]) / det;
	inverted_matrix[6] = matrix[3] * matrix[7] - matrix[6] * matrix[4] / det;
	inverted_matrix[7] = -(matrix[0] * matrix[7] - matrix[6] * matrix[1]) / det;
	inverted_matrix[8] = matrix[0] * matrix[4] - matrix[1] * matrix[3] / det;
}
