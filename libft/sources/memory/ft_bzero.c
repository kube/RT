/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 14:31:22 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/02/18 19:37:29 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void		ft_bzero(void *s, size_t n)
{
	char	*cache;
	size_t	limit;

	cache = (char*)s;
	limit = (size_t)s + n;
	while ((size_t)cache < limit)
	{
		if (cache)
			*cache = 0;
		cache++;
	}
}
