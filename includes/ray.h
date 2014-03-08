/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbinet <lbinet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/07 16:30:00 by lbinet            #+#    #+#             */
/*   Updated: 2014/03/07 16:44:50 by lbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H
# include <ft_colors.h>

typedef struct						s_ray
{
	t_point							origin;
	t_vector						direction;
	unsigned int					recursivity;
	float							intensity;
	t_color							color;
	t_object						*closest;
	float							inter_t;
}									t_ray;

void		throw_ray(t_env *env, t_ray *ray);
float		sphere_equation(t_object *sphere, t_ray *ray);
float		plane_equation(t_object *plane, t_ray *ray);
float		cylinder_equation(t_object *cylinder, t_ray * ray);
float		cone_equation(t_object *cone, t_ray *ray);
#endif
