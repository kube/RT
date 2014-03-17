/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpreter.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/17 00:50:04 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/03/17 03:37:03 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERPRETER_H
# define INTERPRETER_H

void		command_list(t_env *env, char **line);
void		command_remove(t_env *env, char **line);
void		command_add(t_env *env, char **line);

#endif
