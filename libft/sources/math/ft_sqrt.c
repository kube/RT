/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/05 19:02:45 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/02/18 04:38:56 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Quake 3's Fast Inverse Square Root
*/

float		ft_invsqrt (float x)
{
	int		i;
	float	xhalf;

	xhalf = 0.5f * x;
	i = *(int*)&x;
	i = 0x5f3759df - (i >> 1);
	x = *(float*)&i;
	x = x * (1.5f - xhalf * x * x);
	x = x * (1.5f - (xhalf * x * x));
	return (x);
}

float		ft_sqrt(float x)
{
	return (1.0 / ft_invsqrt(x));
}
