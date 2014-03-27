/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 15:49:52 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/02/18 19:19:37 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	size_t			i;
	char			*c1;
	const char		*c2;

	i = 0;
	c1 = s1;
	c2 = s2;
	while (i < n)
	{
		c1[i] = c2[i];
		if (c2[i] == c)
		{
			return (void *)&(c1[i + 1]);
		}
		i++;
	}
	return (0);
}
