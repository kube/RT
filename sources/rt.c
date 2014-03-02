/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/02 14:30:35 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/03/02 17:17:35 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_print.h>
#include <ft_math.h>

#include <stdio.h>

int			main(void)
{
	t_vector	v;

	v.x = 2;
	v.y = 3;
	v.z = 5;
	ft_putendl("Raytracer");
	ft_putendl("Nothing works.");

	printf("%f %f %f\n", v.x, v.y, v.z);
	vect_rot_z(&v, FT_PI / 4);
	printf("%f %f %f\n", v.x, v.y, v.z);
	return (0);
}
