/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/17 20:01:18 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/03/17 20:01:44 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void				pixel_to_image(t_env *env, int x, int y, int color)
{
	unsigned int	i;

	i = env->scene->view_width * (unsigned int)y + (unsigned int)x;
	if (i < env->scene->view_width * env->scene->view_height && (int)y >= 0
		&& (int)x >= 0 && (unsigned int)x < env->scene->view_width)
		env->data[i] = color;
}
