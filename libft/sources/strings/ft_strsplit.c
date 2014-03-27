/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/24 04:44:28 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/02/17 21:45:30 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_strings.h>
#include <stdlib.h>

static int			ft_getwordsnb(char const *s, char c)
{
	unsigned int	nb;
	size_t			i;

	i = 0;
	nb = 0;
	while (s && s[i])
	{
		while ((char)s[i] == c)
			i++;
		if(s[i] && (char)s[i] != c)
			nb++;
		while(s[i] && (char)s[i] != c)
			i++;
	}
	return (nb);
}

char				**ft_strsplit(char const *s, char c)
{
	char			*t;
	char			**splited;
	size_t			k;

	splited = (char**)malloc((ft_getwordsnb(s, c) + 1) * sizeof(char*));
	t = ft_strdup(s);
	k = 0;
	while (t && *t)
	{
		while (*t == c)
		{
			*t = 0;
			t++;
		}
		if (*t && *t != c)
		{
			splited[k] = t;
			k++;
		}
		while(*t && *t != c)
			t++;
	}
	splited[k] = 0;
	return (splited);
}
