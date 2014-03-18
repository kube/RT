/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/09 01:50:07 by kube              #+#    #+#             */
/*   Updated: 2014/03/18 16:41:21 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <camera.h>

void			init_cam(t_camera *cam, float x, float y, float z)
{
	cam->x_axis.x = 1.0f;
	cam->x_axis.y = 0.0f;
	cam->x_axis.z = 0.0f;
	cam->y_axis.x = 0.0f;
	cam->y_axis.y = 1.0f;
	cam->y_axis.z = 0.0f;
	cam->z_axis.x = 0.0f;
	cam->z_axis.y = 0.0f;
	cam->z_axis.z = 1.0f;
	cam->origin.x = x;
	cam->origin.y = y;
	cam->origin.z = z;
}

void			init_cam_angle(t_camera *cam, float y, float z)
{
	cam_rot_y(cam, y);
	cam_rot_z(cam, z);
}

void			update_render_cam(t_camera *render_cam, t_camera *camera)
{
	render_cam->origin = camera->origin;
	render_cam->x_axis = camera->x_axis;
	render_cam->y_axis = camera->y_axis;
	render_cam->z_axis = camera->z_axis;
}
