/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rotate.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: stormdequay <stormdequay@student.codam.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/18 10:50:02 by stormdequay   #+#    #+#                 */
/*   Updated: 2022/02/19 10:40:55 by stormdequay   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/* 
The keys are rendered and they increase or decrease the angle
with 0.1 given the key. the axis changed according to the key 
is next is given below in the corrosponding statement. If one
of the keys is stroked the screen is made black. And the new 
compute values are put in the vars compute function. And then
put to screen.
*/
int	rotate_angle(int keycode, t_vars *vars)
{
	if (keycode == Q)
		vars->angle.d_x += 0.01;
	else if (keycode == A)
		vars->angle.d_x -= 0.01;
	else if (keycode == W)
		vars->angle.d_y += 0.01;
	else if (keycode == S)
		vars->angle.d_y -= 0.01;
	else if (keycode == E)
		vars->angle.d_z += 0.01;
	else if (keycode == D)
		vars->angle.d_z -= 0.01;
	else
		return (0);
	make_screen_black(vars);
	make_vars_compute(vars, vars->angle);
	put_to_screen(*vars);
	return (0);
}

/*
This function is called by the rotate_x_axis and rotates around the y 
axis. 
*/
static t_pixel	rotate_y_axis(t_rotation rot, t_vars *vars, t_pixel point, \
t_angle angle)
{
	rot.angle = 0 + angle.d_x;
	rot.x_0 = rot.x_1;
	rot.x_1 = rot.x_0 * cos(rot.angle) + rot.z_1 * sin(rot.angle);
	point.x = rot.x_1 + vars->x_origin;
	point.y = rot.y_1 + vars->y_origin;
	point.z = point.z;
	return (point);
}

/*
This function is called by the rotate_z_axis and rotates the x_axis with
the variables rot, vars, point, and angle. x_axis remains the same and 
the y and z are adjusted.
*/
static t_pixel	rotate_x_axis(t_rotation rot, t_vars *vars, t_pixel point, \
t_angle angle)
{
	t_pixel		compute_point;

	rot.angle = M_PI_4 + angle.d_y;
	rot.y_0 = rot.y_1;
	rot.y_1 = rot.y_0 * cos(rot.angle) - point.z * sin(rot.angle);
	rot.z_1 = rot.y_0 * sin(rot.angle) + point.z * cos(rot.angle);
	compute_point = rotate_y_axis(rot, vars, point, angle);
	return (compute_point);
}

/* 
The rotate_z_axis is called by the make_vars_compute function. It passes 
the vars struct, the point to be adjusted from the input and the angle.
vars->x_origin and y->origin is the middle of the screen and is detucted
from the point.x and point.y as base. When adjusting the z_axis the z 
remains the same. The rot variable takes the values for the adjusted x, y 
and z values.
*/
t_pixel	rotate_z_axis(t_vars *vars, t_pixel point, t_angle angle)
{
	t_rotation	rot;
	t_pixel		compute_point;

	rot.x_0 = point.x - vars->x_origin;
	rot.y_0 = point.y - vars->y_origin;
	rot.angle = M_PI_4 + angle.d_z;
	rot.x_1 = rot.x_0 * cos(rot.angle) - rot.y_0 * sin(rot.angle);
	rot.y_1 = rot.y_0 * cos(rot.angle) + rot.x_0 * sin(rot.angle);
	compute_point = rotate_x_axis(rot, vars, point, angle);
	return (compute_point);
}
