/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/01 15:37:23 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/02/17 21:21:00 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_memory.h>
#include <stdlib.h>

void	*ft_memdup(const void *oldmem, size_t size)
{
	void	*newmem;

	if (oldmem)
	{
		newmem = malloc(size);
		if (newmem)
			ft_memmove(newmem, oldmem, size);
		return (newmem);
	}
	return (0);
}
