/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infin_number_gt.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/23 00:18:16 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/02/23 00:27:02 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_math.h>

int						infin_number_gt(t_infin_number *a, t_infin_number *b)
{
	int					i;

	if (a->length > b->length)
		return (1);
	else if (b->length > a->length)
		return (0);
	i = a->length;
	while (i >= 0)
	{
		if (b->value[i] > a->value[i])
			return (0);
		else if (b->value[i] < a->value[i])
			return (1);
		i--;
	}
	return (0);
}
