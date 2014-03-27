/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/24 05:03:58 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/03/17 22:18:22 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_print.h>
#include <ft_convert.h>
#include <unistd.h>

void		ft_putunbr(unsigned int n)
{
	char	a;

	if (n / 10)
		ft_putunbr(n / 10);
	a = '0' + n % 10;
	write(1, &a, 1);
}
