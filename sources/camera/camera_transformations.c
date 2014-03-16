/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_transformations.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 23:38:24 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/03/16 18:04:16 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <camera.h>
#include <ft_math.h>

void			cam_rot_z(t_camera *camera, float angle)
{
	vect_rot_z(&camera->x_axis, angle);
	vect_rot_z(&camera->y_axis, angle);
	vect_rot_z(&camera->z_axis, angle);
}

void			cam_rot_x(t_camera *camera, float angle)
{
	vect_rot_x(&camera->x_axis, angle);
	vect_rot_x(&camera->y_axis, angle);
	vect_rot_x(&camera->z_axis, angle);
}

void			cam_rot_y(t_camera *camera, float angle)
{
	vect_rot_y(&camera->x_axis, angle);
	vect_rot_y(&camera->y_axis, angle);
	vect_rot_y(&camera->z_axis, angle);
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
