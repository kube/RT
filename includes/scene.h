/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kube <kube@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/19 23:03:03 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/03/24 23:09:18 by kube             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

typedef struct				s_scene
{
	struct s_camera			camera;
	struct s_camera			render_cam;
	unsigned int			view_width;
	unsigned int			view_height;
	float					diaphragm;
	int						recursivity;
	int						background_color;
	struct s_matter			*matters;
	struct s_object			*objects;
	struct s_light			*lights;
	unsigned int			antialiasing;
}							t_scene;

#endif
