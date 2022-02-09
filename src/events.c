/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   events.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: sde-quai <sde-quai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/02 13:53:11 by sde-quai      #+#    #+#                 */
/*   Updated: 2022/02/09 10:32:52 by sde-quai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
This function renders for the keyhooks called in the function 
render_next_frame() Exit the porgram if ESC is pressed
Value for ESC is in the headerfile fdf.h
 */
static int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == ESC)
		close_screen(keycode, vars);
	return (0);
}

/*
The x and y are registered for the moving of the mouse.
 */
static int	mouse_click(int x, int y, t_vars *vars)
{
	printf("x : %i	y : %i	LEFT CLICK\n", x, y); // delete me
	vars->line_length++;
	vars->line_length--;
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
	x++;
	y++;
	if (keycode == SCROLL_UP)
	{
		make_screen_black(vars);
		vars->line_length++;
		// add adjust z axis
		angle_input(vars);
		put_to_screen(*vars);
	}
	if (keycode == SCROLL_DOWN)
	{
		make_screen_black(vars);
		vars->line_length--;
		// add adjust z axis
		angle_input(vars);
		put_to_screen(*vars);
	}
	if (keycode == LEFT_CLICK)
		mlx_hook(vars->win, 6, 1L << 0, mouse_click, vars);
	return (0);
}

/*
Exit the program if the red cross or ESC is pressed
this function is called so the program is terminated
 */
int	close_screen(int keycode, t_vars *vars)
{
	keycode = 0;
	exit(0);
	free(vars->input);
	free(vars->compute);
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
	mlx_hook(vars->win, RED_CROSS, 0, close_screen, (void *)0);
	mlx_key_hook(vars->win, key_hook, vars);
	mlx_mouse_hook(vars->win, mouse_hook, vars);
	// mlx_hook(vars->win, LEFT_CLICK, 1L << 0, mouse_click, vars);
	return (0);
}
