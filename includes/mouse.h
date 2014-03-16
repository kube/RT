/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/13 02:32:09 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/03/16 18:14:17 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOUSE_H
# define MOUSE_H

# include <rt.h>

int			mousepress_ev(int button, int x, int y, t_env *env);
int			mouserelease_ev(int button, int x, int y, t_env *env);
int			motionnotify_ev(int x, int y, t_env *env);


#endif
