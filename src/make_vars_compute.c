/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   make_vars_compute.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: sde-quai <sde-quai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/14 12:07:46 by sde-quai      #+#    #+#                 */
/*   Updated: 2022/02/18 16:39:05 by stormdequay   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/* 
This function creates a starting point for the x and y values called x_n
and y_n respectivelly. Fort each point in the input values the compute
vales are changed. They are changed in the funciton of rotate_z_axis
*/
void	make_vars_compute(t_vars *vars, t_angle angle)
{
	size_t	x_n;
	size_t	y_n;
	size_t	i;
	t_pixel	point;

	if (!vars->line_length)
	{
		x_n = (S_WIDTH - ((vars->x + 1))) / 2;
		y_n = (S_HEIGHT - ((vars->y + 1))) / 2;
	}
	else
	{
		x_n = (S_WIDTH - ((vars->x + 1) * vars->line_length)) / 2;
		y_n = (S_HEIGHT - ((vars->y + 1) * vars->line_length)) / 2;
	}
	i = 0;
	while (i < vars->input_len)
	{
		point.x = x_n + vars->input[i].x + vars->input[i].x * vars->line_length;
		point.y = y_n + vars->input[i].y + vars->input[i].y * vars->line_length;
		point.z = vars->input[i].z;
		vars->compute[i] = rotate_z_axis(vars, point, angle);
		i++;
	}
}
