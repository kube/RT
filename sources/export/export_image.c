/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/23 12:33:26 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/03/23 17:51:13 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>
#include <unistd.h>
#include <fcntl.h>

static void			put_file_header(int file)
{
	int				data[3];

	write(file, "BM", 2);
	data[0] = (unsigned int)(env->scene->view_width
				* env->scene->view_height);
	data[1] = 0;
	data[2] = 54;
	write(file, (char*)data, 12);
}

static void			put_image_header(int file)
{
	int				data[10];

	data[0] = 40;
	data[1] = (int)env->scene->view_width;
	data[2] = (int)env->scene->view_height;
	data[3] = 1 + 24 * 256 * 256;
	data[4] = 0;
	data[5] = 0;
	data[6] = 0;
	data[7] = 0;
	data[8] = 0;
	data[9] = 0;
	write(file, (char*)data, 40);
}

static void			putpixel_to_file(int file, int i, int j)
{
	t_color			pixel;

	pixel.color = light_diaphragm(
		&env->rendering[j * env->scene->view_width + i],
		env->scene->diaphragm);
	write(file, &pixel.b, 1);
	write(file, &pixel.g, 1);
	write(file, &pixel.r, 1);
}

void				export_image(int file)
{
	unsigned int	i;
	unsigned int	j;

	put_file_header(file);
	put_image_header(file);
	j = env->scene->view_height;
	while (j > 0)
	{
		i = 0;
		while (i < env->scene->view_width / 4 * 4)
		{
			putpixel_to_file(file, i, j - 1);
			i++;
		}
		j--;
	}
}
