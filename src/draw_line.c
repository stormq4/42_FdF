/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_line.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: sde-quai <sde-quai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/11 10:28:18 by sde-quai      #+#    #+#                 */
/*   Updated: 2022/02/14 10:08:41 by sde-quai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

/*
plot_high_line is called to plot the line between points vars0 and vars1. 
If the plot.dis is greater than 0 then xi is incremented to vars0.y. vars.x
is incremented in the loop.
 */
static void	plot_low_line(t_pixel vars0, t_pixel vars1, \
t_vars *vars, t_plot plot)
{
	while (vars0.x <= vars1.x)
	{
		if (estimate_pixel_in_window(vars0.x, vars0.y))
			my_mlx_pixel_put(&vars->img, (int)vars0.x, (int)vars0.y, \
			WHITE_COLOR);
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
From the plot the difference in y and x is determined. If the difference in x 
is negative then the y incrementer is negative. The discriminant of the line 
determines if a new pixel on the y axis is drawn.
 */
static void	low_line(t_pixel vars0, t_pixel vars1, t_vars *vars)
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
	plot_low_line(vars0, vars1, vars, plot);
}

/*
plot_high_line is called to plot the line between points vars0 and vars1. 
If the plot.dis is greater than 0 then xi is incremented to vars0.x. vars.y
is incremented in the loop.
 */
static void	plot_high_line(t_pixel vars0, t_pixel vars1, \
t_vars *vars, t_plot plot)
{
	while (vars0.y <= vars1.y)
	{
		if (estimate_pixel_in_window(vars0.x, vars0.y))
			my_mlx_pixel_put(&vars->img, (int)vars0.x, (int)vars0.y, \
			WHITE_COLOR);
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
From the plot the difference in y and x is determined. If the difference in 
x is negative then the x incrementer is negative. The discriminant of the line
determines if a new pixel on the x axis is drawn. plot_high_line is called to
plot the line between points vars0 and vars1;
 */
static void	high_line(t_pixel vars0, t_pixel vars1, t_vars *vars)
{
	t_plot	plot;

	plot.dx = vars1.x - vars0.x;
	plot.dy = vars1.y - vars0.y;
	plot.xi = 1;
	plot.initial_val = vars0.x;
	if (plot.dx < 0)
	{
		plot.xi = -1;
		plot.dx = -plot.dx;
	}
	plot.dis = (2 * plot.dx) - plot.dy;
	plot_high_line(vars0, vars1, vars, plot);
}

/*
Draw_line is a switch function which checks if the line ascends or descends with 
an angle more than 45 degrees and must be drawn positive or negative.
 */
void	draw_line(t_vars *vars, t_pixel vars0, t_pixel vars1)
{
	if (absolute_float(vars1.y - vars0.y) < absolute_float(vars1.x - vars0.x))
	{
		if (vars0.x > vars1.x)
			low_line(vars1, vars0, vars);
		else
			low_line(vars0, vars1, vars);
	}
	else
	{
		if (vars0.y > vars1.y)
			high_line(vars1, vars0, vars);
		else
			high_line(vars0, vars1, vars);
	}
}
