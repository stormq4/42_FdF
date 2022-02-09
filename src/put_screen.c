/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   put_screen.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: sde-quai <sde-quai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/18 13:42:45 by sde-quai      #+#    #+#                 */
/*   Updated: 2022/02/08 15:42:34 by sde-quai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

/*
From the plot the difference in y and x is determined. If the difference in x 
is negative then the y incrementer is negative. The discriminant of the line 
determines if a new pixel on the y axis is drawn.
 */
static void	plot_low_line(t_pixel vars0, t_pixel vars1, t_data img)
{
	t_plot	plot;

	plot.dx = vars1.x - vars0.x;
	plot.dy = vars1.y - vars0.y;
	plot.yi = 1;
	if (plot.dy < 0)
	{
		plot.yi = -1;
		plot.dy = -plot.dy;
	}
	plot.dis = (2 * plot.dy) - plot.dx;
	while (vars0.x <= vars1.x)
	{
		if (estimate_pixel_in_window(vars0.x, vars0.y))
			my_mlx_pixel_put(&img, (int)vars0.x, (int)vars0.y, RED_COLOR);
		if (plot.dis > 0)
		{
			vars0.y += plot.yi;
			plot.dis += 2 * (plot.dy - plot.dx);
		}
		else
			plot.dis += 2 * plot.dy;
		vars0.x++;
	}
}

/*
From the plot the difference in y and x is determined. If the difference in 
x is negative then the x incrementer is negative. The discriminant of the line
determines if a new pixel on the x axis is drawn
 */
static void	plot_high_line(t_pixel vars0, t_pixel vars1, t_data img)
{
	t_plot	plot;

	plot.dx = vars1.x - vars0.x;
	plot.dy = vars1.y - vars0.y;
	plot.xi = 1;
	if (plot.dx < 0)
	{
		plot.xi = -1;
		plot.dx = -plot.dx;
	}
	plot.dis = (2 * plot.dx) - plot.dy;
	while (vars0.y <= vars1.y)
	{
		if (estimate_pixel_in_window(vars0.x, vars0.y))
			my_mlx_pixel_put(&img, (int)vars0.x, (int)vars0.y, WHITE_COLOR);
		if (plot.dis > 0)
		{
			vars0.x += plot.xi;
			plot.dis += 2 * (plot.dx - plot.dy);
		}
		else
			plot.dis += 2 * plot.dx;
		vars0.y++;
	}
}

/*
Draw_line is a switch function which checks if the line ascends or descends with 
an angle more than 45 degrees and must be drawn positive or negative.
 */
static void	draw_line(t_data img, t_pixel vars0, t_pixel vars1)
{
	if (absolute_float(vars1.y - vars0.y) < absolute_float(vars1.x - vars0.x))
	{
		if (vars0.x > vars1.x)
			plot_low_line(vars1, vars0, img);
		else
			plot_low_line(vars0, vars1, img);
	}
	else
	{
		if (vars0.y > vars1.y)
			plot_high_line(vars1, vars0, img);
		else
			plot_high_line(vars0, vars1, img);
	}
}

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
			draw_line(vars.img, vars.compute[i], vars.compute[i + vars.x]);
		if (i < (vars.x) * (y + 1) - 1 && y < vars.y)
			draw_line(vars.img, vars.compute[i], vars.compute[i + 1]);
		else
			y++;
		i++;
	}
	mlx_put_image_to_window(vars.mlx, vars.win, vars.img.img, 0, 0);
}

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
