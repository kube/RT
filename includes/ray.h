/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/07 16:30:00 by lbinet            #+#    #+#             */
/*   Updated: 2014/03/27 20:18:44 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H
# include <rt.h>
# include <ft_colors.h>

typedef struct						s_ray
{
	t_point							origin;
	t_vector						direction;
	float							intensity;
	t_light_color					color;
	t_object						*closest;
	float							inter_t;
}									t_ray;

t_ray		get_ray_from_point(float i, float j);
void		throw_ray(t_ray *ray, int calculate_light,
						t_object *to_ignore, int recursivity);
void		throw_ray_predefined(t_ray *ray, int calculate_light,
								t_object *obj);
void		change_ray(t_ray *ray, t_ray *new_ray, t_object *obj,
						t_object *new_obj);
void		phong_shading(t_ray *ray);
float		sphere_equation(t_object *sphere, t_ray *ray);
float		plane_equation(t_object *plane, t_ray *ray);
float		cylinder_equation(t_object *cylinder, t_ray *ray);
float		cone_equation(t_object *cone, t_ray *ray);
float		positive_smallest(float a, float b);
void		get_cylinder_normal(t_vector *normal,
								t_object *cylinder, t_point *intersection);
void		get_cone_normal(t_vector *normal, t_object *cone,
							t_point *intersection);

#endif
