/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infin_add.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/23 00:07:06 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/02/23 00:32:07 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <ft_math.h>

static unsigned int		max(unsigned int a, unsigned int b)
{
	if (a > b)
		return (a);
	return (b);
}

t_infin_number			*infin_add(t_infin_number *a, t_infin_number *b)
{
	unsigned int		i;
	t_infin_number		*number;
	char				carry;

	i = 0;
	carry = 0;
	number = (t_infin_number*)malloc(sizeof(t_infin_number));
	number->length = max(a->length, b->length) + 1;
	number->value = (char*)malloc((int)number->length * sizeof(char));
	number->sign = 1;
	if ((a->sign == 1 && b->sign == -1 && infin_number_gt(b, a)) ||
		(a->sign == -1 && b->sign == 1 && infin_number_gt(a, b)))
	{
		a->sign *= -1;
		b->sign *= -1;
		number->sign = -1;
	}
	else if (a->sign == -1 && b->sign == -1)
	{
		a->sign = 1;
		b->sign = 1;
		number->sign = -1;
	}
	while (i < number->length)
	{
		number->value[i] = 0;
		if (i < a->length)
			number->value[i] += (int)a->value[i] * a->sign;
		if (i < b->length)
			number->value[i] += (int)b->value[i] * b->sign;
		if (carry != 0)
		{
			number->value[i] += carry;
			carry = 0;
		}
		if (number->value[i] >= (char)number->base)
		{
			carry = 1;
			number->value[i] -= (char)number->base;
		}
		else if (number->value[i] < 0)
		{
			carry = -1;
			number->value[i] += number->base;
		}
		i++;
	}
	return (number);
}
