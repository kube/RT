/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/18 23:53:24 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/03/19 23:03:41 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_H
# define LIGHT_H
# include <scene.h>

# define LIGHT_DOT			0
# define LIGHT_SPHERE		1

typedef union				u_light_color
{
	struct
	{
		float				red;
		float				green;
		float				blue;
	};
	struct
	{
		float				r;
		float				g;
		float				b;
	};
}							t_light_color;

typedef struct				s_light
{
	char					*light;
	int						type;
	t_point					origin;
	float					intensity;
	t_vector				direction;
	t_object				*object;
	float					aperture;
	t_light_color			color;
	struct s_light			*next;
}							t_light;

void		remove_light(t_scene *scene, t_light *light);

#endif
