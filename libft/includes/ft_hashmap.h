/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hashmap.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/19 23:41:10 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/02/20 00:27:01 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HASHMAP_H
# define FT_HASHMAP_H
# include <strings.h>

typedef struct				s_hashmap_var
{
	unsigned int			hash;
	char					*name;
	void					*object;
	struct s_hashmap_var	*next;
}							t_hashmap_var;

typedef struct				s_hashmap
{
	unsigned int			size;
	t_hashmap_var			**vars;
}							t_hashmap;

#endif
