/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_blend_over.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/02 20:42:47 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/03/02 21:38:56 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_colors.h>

t_color				color_blend_over(t_color a, t_color b)
{
	t_color			c;

	if (b.a == 0)
		return (a);
	else if (b.a == 255 || a.a == 0)
		return (b);
	else if (a.a < 255)
	{
		c.a = a.a + ((255 - a.a) * b.a) / 255;
		c.r = (a.r * a.a * (255 - b.a) + b.r * b.a) / c.a;
		c.g = (a.g * a.a * (255 - b.a) + b.g * b.a) / c.a;
		c.b = (a.b * a.a * (255 - b.a) + b.b * b.a) / c.a;
	}
	else
	{
		c.a = 255;
		c.r = (a.r * (255 - b.a) + b.r * b.a) / 255;
		c.g = (a.g * (255 - b.a) + b.g * b.a) / 255;
		c.b = (a.b * (255 - b.a) + b.b * b.a) / 255;
	}
	return (c);
}
