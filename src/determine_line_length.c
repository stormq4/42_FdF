/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   determine_line_length.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: sde-quai <sde-quai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/31 11:56:16 by sde-quai      #+#    #+#                 */
/*   Updated: 2022/02/18 14:45:30 by stormdequay   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
		while (len * vars->x >= maximum_width)
			len--;
		len = determine_line_length(vars, WIDTH, len);
	}
	else
	{
		compare_len = 20;
		maximum_width = S_WIDTH * 0.5;
		while (compare_len * vars->y >= maximum_width)
			compare_len--;
		if (compare_len < len)
			len = compare_len;
	}
	return (len);
}
