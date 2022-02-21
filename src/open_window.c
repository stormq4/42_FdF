/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   open_window.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: sde-quai <sde-quai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/11 10:23:31 by sde-quai      #+#    #+#                 */
/*   Updated: 2022/02/11 10:23:46 by sde-quai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
This function opens a new window with height and width of S_WIDTH and S_HEIGTH
 */
void	open_window(t_data *img, t_vars *vars)
{
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, S_WIDTH, S_HEIGHT, "FdF");
	img->img = mlx_new_image(vars->mlx, S_WIDTH, S_HEIGHT);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, \
	&img->line_length, &img->endian);
}
