/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/23 08:07:49 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/02/17 21:24:10 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_strings.h>

char	*ft_strcat(char *s1, const char *s2)
{
	size_t	i;
	size_t	len1;

	len1 = ft_strlen(s1);
	i = 0;
	while (s2[i])
	{
		s1[len1 + i] = s2[i];
		i++;
	}
	s1[len1 + i] = 0;
	return (s1);
}
