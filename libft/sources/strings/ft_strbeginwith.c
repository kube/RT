/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strbeginwith.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/22 15:29:31 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/02/22 15:32:16 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Checks that string A begins with string B
*/

int		ft_strbeginwith(char *a, char *b)
{
	while (*b && *a == *b)
	{
		a++;
		b++;
	}
	if (!*a)
		return (1);
	return (0);
}
