/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/02 17:42:56 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/03/02 17:44:06 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

typedef struct						s_camera
{
	t_point							origin;
	t_vector						x_axis;
	t_vector						y_axis;
	t_vector						z_axis;
}									t_camera;

void	cam_rot_z(t_camera *camera, float angle);
void	cam_rot_x(t_camera *camera, float angle);
void	cam_rot_y(t_camera *camera, float angle);
void	cam_translate(t_camera *camera, float x, float y, float z);
void	cam_move_to(t_camera *camera, float x, float y, float z);

#endif
