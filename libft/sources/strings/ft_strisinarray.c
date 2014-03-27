/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strisinarray.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/09 16:49:02 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/02/17 21:57:04 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

ssize_t	ft_strinarray(char **array, char *str)
{
	ssize_t	i;

	i = 0;
	while (array[i] && array[i][0])
	{
		if (strequ(array[i], str))
			return (i);
		i++;
	}
	return (0);
}
