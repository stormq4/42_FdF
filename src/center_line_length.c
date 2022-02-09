/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   center_line_length.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: sde-quai <sde-quai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/31 11:56:16 by sde-quai      #+#    #+#                 */
/*   Updated: 2022/02/08 15:44:55 by sde-quai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
The data of the map is centered in the window by determining the value most 
outer x and y values which are added to the x and y. The z value is substracted
to y values since axis have tilted upside down.
 */
static void	center_angle(t_vars *vars)
{
	size_t	i;
	size_t	x_n;
	size_t	y_n;

	x_n = (S_WIDTH - vars->compute[vars->x - 1].x - \
	vars->compute[vars->x * (vars->y - 1)].x) / 2;
	y_n = (S_HEIGHT - vars->compute[vars->input_len - 1].y) / 2;
	i = 0;
	while (i < vars->input_len)
	{
		vars->compute[i].x += (float)x_n;
		vars->compute[i].y += (-vars->input[i].z + (float)y_n);
		i++;
	}
}

/*
This function tilts the input to a 45 degree view from above and puts the input
values from hte map in the compute values from the t_vars struct vars. the y 
value becomes 2 times smaller then the x value.the points are still seperated
with the line length
 */
void	angle_input(t_vars *vars)
{
	size_t	i;
	t_pixel	tmp;

	i = 0;
	vars->compute = malloc(sizeof(t_pixel) * vars->input_len);
	ft_check_malloc(vars->compute);
	while (i < vars->input_len)
	{
		tmp.x = (vars->input[i].x - vars->input[i].y) * \
		vars->line_length;
		tmp.y = (vars->input[i].x + vars->input[i].y) * \
		vars->line_length / 2;
		vars->compute[i] = tmp;
		i++;
	}
	center_angle(vars);
}

/*
With this funciton the line length is determined with a maximum width of 
50% of the S_HEIGHT and S_WIDTH with regard to the maximum x and y values.
 */
size_t	determine_line_length(t_vars *vars, t_wl DIM, size_t len)
{
	size_t	maximum_width;
	size_t	compare_len;

	if (DIM == HEIGHT)
	{
		maximum_width = S_HEIGHT * 0.5;
		while (len * vars->x > maximum_width)
			len--;
		len = determine_line_length(vars, WIDTH, len);
	}
	else
	{
		compare_len = 20;
		maximum_width = S_WIDTH * 0.5;
		while (compare_len * vars->y > maximum_width)
			compare_len--;
		if (compare_len < len)
			len = compare_len;
	}
	return (len);
}
