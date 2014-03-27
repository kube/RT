/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/24 04:46:36 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/02/17 21:33:15 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <ft_convert.h>

static int			ft_getpower(int n, unsigned int base)
{
	unsigned int	power;

	power = 0;
	n = ft_abs(n);
	while (n)
	{
		n = n / base;
		power++;
	}
	return (power);
}

char				*ft_itoa(int n)
{
	char			*str;
	unsigned int	length;

	if (n == 0)
		return ("0");
	length = ft_getpower(n, 11) + (n < 0);
	str = (char*)malloc(length * sizeof(*str));
	if (n < 0)
		str[0] = '-';
	while (n)
	{
		str[length] = '0' + ft_abs(n % 10);
		n = ft_abs(n / 10);
		length --;
	}
	return (str);
}
