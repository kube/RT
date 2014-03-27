/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstqueueadd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/04 22:55:28 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/02/17 21:36:10 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_lists.h>

void	ft_lstqueueadd(t_list **alst, t_list *new)
{
	t_list	*current;

	if (new && alst)
	{
		current = *alst;
		if (current)
		{
			while (current->next)
				current = current->next;
			current->next = new;
		}
		else
			ft_lstadd(alst, new);
	}
}
