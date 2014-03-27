/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 02:02:58 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/02/17 21:22:49 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_strings.h>

char	*ft_strcpy(char *s1, const char *s2)
{
	unsigned int	i;
	size_t			len2;

	i = 0;
	len2 = ft_strlen((char*)s2);
	while (s2[i] && i < len2)
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = 0;
	return (s1);
}
