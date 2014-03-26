/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/26 18:47:14 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/03/26 18:51:34 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_H
# define MATRIX_H

t_vector	matrix_vector_product(float matrix[9], t_vector *a);
t_point		matrix_point_product(float matrix[9], t_point *a);
void		transformation_matrix(float matrix[9], t_vector *x,
									t_vector *y, t_vector *z);
void		invert_matrix(float matrix[9], float inverted_matrix[9]);

#endif
