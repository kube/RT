/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/11 14:27:23 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/02/17 21:36:21 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_lists.h>

void	ft_lstrev(t_list **alst)
{
	t_list	*new;
	t_list	*old_next;
	t_list	*old_current;

	new = 0;
	old_current = *alst;
	while (old_current)
	{
		old_next = old_current->next;
		old_current->next = new;
		new = old_current;
		old_current = old_next;
	}
	*alst = new;
}
