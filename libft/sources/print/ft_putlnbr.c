/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlnbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/01 16:22:00 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/02/17 19:27:52 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static long int	ft_labs(long int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

void		ft_putlnbr(long int n)
{
	char	a;

	if (n < 0)
		write(1, "-", 1);
	if (n / 10)
		ft_putlnbr(ft_labs(n / 10));
	a = '0' + ft_labs(n % 10);
	write(1, &a, 1);
}
