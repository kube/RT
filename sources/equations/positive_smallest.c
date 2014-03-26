/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   positive_smallest.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/05 19:30:09 by lbinet            #+#    #+#             */
/*   Updated: 2014/03/26 18:31:44 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>
#include <ray.h>
#include <object.h>
#include <math.h>

float			positive_smallest(float a, float b)
{
	if (a < 0)
	{
		if (b > 0)
			return (b);
		return (INFINITY);
	}
	if (b < 0)
	{
		if (a > 0)
			return (a);
		return (INFINITY);
	}
	if (a < b)
		return (a);
	return (b);
}
