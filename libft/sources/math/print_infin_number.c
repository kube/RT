/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_infin_number.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/23 00:20:46 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/02/23 00:32:26 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_math.h>
#include <unistd.h>

void					print_infin_number(t_infin_number *number)
{
	int					i;
	char				digit;

	i = number->length - 1;
	if (number->length > 0)
	{
		if (number->sign == -1)
			write(1, "-", 1);
		while (i >= 0)
		{
			digit = '0' + number->value[i];
			write(1, &digit, 1);
			i--;
		}
	}
	else
		write(1, "0", 1);
}
