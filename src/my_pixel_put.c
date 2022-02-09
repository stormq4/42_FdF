/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   my_pixel_put.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: sde-quai <sde-quai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/14 10:27:26 by sde-quai      #+#    #+#                 */
/*   Updated: 2022/02/09 10:25:35 by sde-quai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
If this function is called a specific pixel is put on the map.
The x and y coordinate determine the location of the pixel. The
color is put into the integer of int color.
*/
void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

/*
This function estimates if the pixel falls within the screen with S_WIDTH
and S_HEIGHT
 */
int	estimate_pixel_in_window(float x, float y)
{
	if (x >= 0 && x <= S_WIDTH && y >= 0 && y <= S_HEIGHT)
		return (TRUE);
	return (FALSE);
}

/*
This function makes the screen black and calls my pixel put to put the 
black pixels on the screen
 */
void	make_screen_black(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	while (i < S_HEIGHT)
	{
		j = 0;
		while (j < S_WIDTH)
		{
			my_mlx_pixel_put(&vars->img, j, i, BLACK_COLOR);
			j++;
		}
		i++;
	}
}
