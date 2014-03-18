/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/02 17:42:56 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/03/18 16:41:48 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H
# include <ft_math.h>

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
void	cam_translate_vector(t_camera *camera, t_vector *v, float coeff);
void	cam_move_to(t_camera *camera, float x, float y, float z);

void	init_cam(t_camera *cam, float x, float y, float z);
void	init_cam_angle(t_camera *cam, float y, float z);
void	update_render_cam(t_camera *render_cam, t_camera *camera);

#endif
