/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matter.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kube <kube@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/09 02:17:51 by kube              #+#    #+#             */
/*   Updated: 2014/03/09 03:03:12 by kube             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATTER_H
# define MATTER_H

# include <ft_colors.h>
# define OBJ_SPHERE		0
# define OBJ_PLANE		1
# define OBJ_CONE		2
# define OBJ_CYLINDER	3

typedef struct				s_matter
{
	char					*name;
	t_color					color;
	float					opacity;
	float					ambient;
	float					diffuse;
	float					specular;
	float					reflection;
	float					refraction;
	float					refract_index;
	struct s_matter			*next;
}							t_matter;

#endif
