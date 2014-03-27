/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/26 17:03:35 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/02/17 21:42:46 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_print.h>
#include <ft_convert.h>
#include <unistd.h>

void	ft_putnbrb(long int n, unsigned int base)
{
	int		a;
	char	b[36] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	if (base <= 36 && base > 1)
	{
		if (n < 0)
			write(1, "-", 1);
		if (n / base)
			ft_putnbrb(ft_abs(n / base), base);
		a = ft_abs(n % base);
		write(1, b + a, 1);
	}
}
