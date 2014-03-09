/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kube <kube@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/09 01:50:07 by kube              #+#    #+#             */
/*   Updated: 2014/03/09 01:54:32 by kube             ###   ########.fr       */
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
