/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   put_screen.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: sde-quai <sde-quai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/18 13:42:45 by sde-quai      #+#    #+#                 */
/*   Updated: 2022/02/11 15:22:33 by sde-quai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

/*
Put to screen takes all the data points stored in vast.compute and plots 
it in the end with the following functions above
 */
void	put_to_screen(t_vars vars)
{
	size_t	i;
	size_t	y;

	i = 0;
	y = 0;
	while (i < vars.input_len)
	{
		if (estimate_pixel_in_window(vars.compute[i].x, vars.compute[i].y))
			my_mlx_pixel_put(&vars.img, (int)vars.compute[i].x, \
			(int)vars.compute[i].y, WHITE_COLOR);
		if (y < (vars.y - 1))
			draw_line(&vars, vars.compute[i], vars.compute[i + vars.x]);
		if (i < (vars.x) * (y + 1) - 1 && y < vars.y)
			draw_line(&vars, vars.compute[i], vars.compute[i + 1]);
		else
			y++;
		i++;
	}
	mlx_put_image_to_window(vars.mlx, vars.win, vars.img.img, 0, 0);
}
