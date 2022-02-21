/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   zoom.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: sde-quai <sde-quai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/14 09:12:03 by sde-quai      #+#    #+#                 */
/*   Updated: 2022/02/18 14:40:27 by stormdequay   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/* 
Multiply line length increases the line length with the given multiplier such
that the picture can be zoomed in or out
*/
static void	multiply_length(t_vars *vars, float len_multplier)
{
	size_t	i;

	i = 0;
	while (i < vars->input_len)
	{
		vars->input[i].z *= len_multplier;
		i++;
	}
}

/*
Here the screen is initially made black and. The relative line length is the
old line length such that difference is taken in the change for the scrolling
This is important because the z must be increased as well when zooming.
*/
void	zoom(t_vars *vars, t_zoom zoom)
{
	float	relative_len;
	float	len_multplier;

	make_screen_black(vars);
	relative_len = vars->line_length;
	if (zoom == IN)
		vars->line_length++;
	else
		vars->line_length--;
	len_multplier = (float)(vars->line_length / relative_len);
	multiply_length(vars, len_multplier);
	make_vars_compute(vars, vars->angle);
	put_to_screen(*vars);
}

/*
Increase_z increase the z values realitive to the z_gradient if Z or X is pressed
*/
int	increase_z(int keycode, t_vars *vars)
{
	float	old_z_grad;

	make_screen_black(vars);
	old_z_grad = vars->z_grad;
	if (keycode == Z)
		vars->z_grad *= 1.1;
	else if (keycode == X)
		vars->z_grad *= 0.9;
	scale_z(vars, old_z_grad);
	make_vars_compute(vars, vars->angle);
	put_to_screen(*vars);
	return (0);
}
