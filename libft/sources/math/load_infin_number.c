/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_infin_number.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/23 00:11:17 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/02/23 00:32:42 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_math.h>
#include <ft_strings.h>
#include <stdlib.h>

static void				reverse_number(t_infin_number *number)
{
	unsigned int		i;
	unsigned int		length;
	char				*reversed_value;

	length = number->length;
	reversed_value = (char*)malloc((int)length * sizeof(char));
	i = 0;
	while (i < length)
	{
		reversed_value[i] = number->value[length - i - 1] - '0';
		i++;
	}
	number->value = reversed_value;
}

t_infin_number			*load_infin_number(char *value)
{
	t_infin_number		*number;
	unsigned int		length;
	
	number = (t_infin_number*)malloc(sizeof(t_infin_number));
	if (*value == '-')
	{
		number->sign = -1;
		value++;
	}
	else
		number->sign = 1;
	number->value = value;
	while (*value == '0')
		value++;
	length = 0;
	while (ft_isdigit(value[length]))
		length++;
	number->length = length;
	reverse_number(number);
	return (number);
}
