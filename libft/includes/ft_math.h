/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/17 19:39:24 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/03/26 19:42:58 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FT_MATH_H
# ifdef USE_MATH
#  include <math.h>
# endif
# define FT_MATH_H
# define LIMITED_DEV_COS_SIN 6
# define FT_PI	3.141592654

typedef struct			s_point
{
	float				x;
	float				y;
	float				z;
}						t_point;

typedef struct			s_vector
{
	float				x;
	float				y;
	float				z;
}						t_vector;

typedef struct			s_infin_number
{
	int					sign;
	char				*value;
	unsigned int		length;
	unsigned int		base;
}						t_infin_number;

float			ft_cos(float x);
float			ft_sin(float x);
float			ft_invsqrt (float x);
float			ft_sqrt(float x);

void			vect_rot_z(t_vector *v, float angle);
void			vect_rot_x(t_vector *v, float angle);
void			vect_rot_y(t_vector *v, float angle);
void			vect_scale(t_vector *v, float coeff);

float			vect_dot(t_vector *a, t_vector *b);
t_vector		vect_product(t_vector *a, t_vector *b);
float			vect_norm(t_vector *a);

t_vector		vector_from_points(t_vector *a, t_vector *b);
float			distance_between_points(t_point *a, t_point *b);

t_vector		*vector_add(t_vector *a, t_vector *b, float coeff);
void			normalize_vector(t_vector *a);

t_infin_number	*infin_add(t_infin_number *a, t_infin_number *b);
int				infin_number_gt(t_infin_number *a, t_infin_number *b);
void			print_infin_number(t_infin_number *number);
t_infin_number	*load_infin_number(char *value);

#endif
