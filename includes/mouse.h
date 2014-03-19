/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/13 02:32:09 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/03/19 22:22:41 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOUSE_H
# define MOUSE_H

int			mousepress_ev(int button, int x, int y);
int			mouserelease_ev(int button, int x, int y);
int			motionnotify_ev(int x, int y, t_env *env);

#endif
