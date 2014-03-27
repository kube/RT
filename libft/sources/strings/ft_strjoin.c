/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/24 04:40:04 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/02/17 21:24:36 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_strings.h>
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	length;
	char	*new;
	char	nullchar;

	nullchar = 0;
	if (!s1)
		s1 = &nullchar;
	if (!s2)
		s2 = &nullchar;
	length = ft_strlen(s1) + ft_strlen(s2);
	new = (char*)malloc(length * sizeof(*new));
	if (new)
	{
		ft_strcpy(new, s1);
		ft_strcpy(new + ft_strlen(s1), s2);
	}
	return (new);
}
