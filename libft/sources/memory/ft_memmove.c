/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 18:13:36 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/02/17 21:38:36 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>

void	*ft_memmove(void *s1, const void *s2, size_t n)
{
	size_t			i;
	int				sens;
	char			*c1;
	const char		*c2;

	if (s1 && s2)
	{
		i = 0;
		sens = 1;
		c1 = s1;
		c2 = s2;
		if (s1 >= s2 && n > 0)
		{
			i = n - 1;
			sens = -1;
		}
		while (i != n * sens)
		{
			c1[i] = c2[i];
			i += sens;
		}
	}
	return (s1);
}
