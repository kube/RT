/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbinet <lbinet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/05 18:01:22 by lbinet            #+#    #+#             */
/*   Updated: 2014/03/08 17:08:16 by lbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

# include <ft_math.h>
# include <ft_colors.h>

typedef struct				s_object
{
	int						type;
	t_point					origin;
	union
	{
		struct
		{
			float			rotX;
			float			rotY;
			float			rotZ;
		};
		t_vector			normal;
	};
	t_color					color;
	float					opacity;
	float					ambient;
	float					diffuse;
	float					specular;
	float					reflection;
	float					refraction;
	float					refract_index;
	union
	{
		float				radius;
		float				aperture;
	};
	struct s_object			*next;
}							t_object;

#endif
