/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blend_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/02 17:53:52 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/03/02 21:38:14 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_colors.h>

int					blend_colors(int color1, int color2, float coeff, int type)
{
	t_color			a;
	t_color			b;

	a.color = color1;
	b.color = color2;
	if (coeff < 1)
		b.color = fade_color(b, coeff).color;
	if (type == COLOR_BLEND_ADD)
		return (color_blend_add(a, b).color);
	else if (type == COLOR_BLEND_SUB)
		return (color_blend_sub(a, b).color);
	else
		return (color_blend_over(a, b).color);
}
