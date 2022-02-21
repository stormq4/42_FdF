/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   events.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: sde-quai <sde-quai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/02 13:53:11 by sde-quai      #+#    #+#                 */
/*   Updated: 2022/02/21 11:05:21 by sde-quai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
This function renders for the keyhooks called in the function 
render_next_frame() Exit the porgram if ESC is pressed
Value for ESC is in the headerfile fdf.h. THe QWEASD keys
as well; they change the angle in rotate.c
 */
static int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == ESC)
		close_screen(keycode, vars);
	else if (keycode == Z || keycode == X)
		mlx_hook(vars->win, 2, 1L << 0, increase_z, vars);
	else
		mlx_hook(vars->win, 2, 1L << 0, rotate_angle, vars);
	return (0);
}

/*
The Mouse hook function is called in the MLX library and renders for certain
such as scrolling up or down and left clicking. Scrolling up zooms in, while 
down zooms out. Left clicking is for adjusting the delta x and y functions to
adjust the angle for the view. The keycodes kan be found in the header.
 */
static int	mouse_hook(int keycode, int x, int y, t_vars *vars)
{
	(void)x;
	(void)y;
	if (keycode == SCROLL_UP)
		zoom(vars, IN);
	if (keycode == SCROLL_DOWN)
		zoom(vars, OUT);
	return (0);
}

/*
Exit the program if the red cross or ESC is pressed
this function is called so the program is terminated
 */
int	close_screen(int keycode, t_vars *vars)
{
	(void)keycode;
	(void)vars;
	exit(0);
	return (0);
}

/*
Inside this function certain hooks are activated. The first one is to close
the screen when the red cross is activated and the function close screen is 
to the MLX function. The second, renders for key hooks such as ESC button. 
The the third function is an mlx function where the function mouse hook is 
passed where the actions of the mouse such as scrolling and clicking are
rendered.
 */
int	render_next_frame(t_vars *vars)
{
	mlx_hook(vars->win, RED_CROSS, 0, close_screen, vars);
	mlx_key_hook(vars->win, key_hook, vars);
	mlx_mouse_hook(vars->win, mouse_hook, vars);
	return (0);
}
