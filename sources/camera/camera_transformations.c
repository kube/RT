/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_transformations.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 23:38:24 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/03/18 22:43:32 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <camera.h>
#include <ft_math.h>
#include <ft_memory.h>

void			cam_rot_z(t_camera *camera, float angle)
{
	t_vector	x_cache;
	t_vector	y_cache;

	ft_memcpy(&x_cache, &camera->x_axis, sizeof(t_vector));
	ft_memcpy(&y_cache, &camera->y_axis, sizeof(t_vector));
	vector_add(&camera->y_axis, &x_cache, -angle);
	vector_add(&camera->x_axis, &y_cache, angle);
	normalize_vector(&camera->y_axis);
	normalize_vector(&camera->x_axis);
}

void			cam_rot_x(t_camera *camera, float angle)
{
	t_vector	y_cache;
	t_vector	z_cache;

	ft_memcpy(&y_cache, &camera->y_axis, sizeof(t_vector));
	ft_memcpy(&z_cache, &camera->z_axis, sizeof(t_vector));
	vector_add(&camera->z_axis, &y_cache, angle);
	vector_add(&camera->y_axis, &z_cache, -angle);
	normalize_vector(&camera->z_axis);
	normalize_vector(&camera->y_axis);
}

void			cam_rot_y(t_camera *camera, float angle)
{
	t_vector	x_cache;
	t_vector	z_cache;

	ft_memcpy(&x_cache, &camera->x_axis, sizeof(t_vector));
	ft_memcpy(&z_cache, &camera->z_axis, sizeof(t_vector));
	vector_add(&camera->z_axis, &x_cache, angle);
	vector_add(&camera->x_axis, &z_cache, -angle);
	normalize_vector(&camera->z_axis);
	normalize_vector(&camera->x_axis);
}

void			cam_translate(t_camera *camera, float x, float y, float z)
{
	camera->origin.x += x;
	camera->origin.y += y;
	camera->origin.z += z;
}

void			cam_translate_vector(t_camera *camera, t_vector *v, float coeff)
{
	camera->origin.x += v->x * coeff;
	camera->origin.y += v->y * coeff;
	camera->origin.z += v->z * coeff;
}
