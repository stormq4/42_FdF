/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   scale_z.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: stormdequay <stormdequay@student.codam.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/18 13:46:29 by stormdequay   #+#    #+#                 */
/*   Updated: 2022/02/21 10:42:45 by sde-quai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
The z_gradien is determined for the height of scaling of the z values.
The abs value helps compute the z_gradient. The z values kan range at 
a maximum of S_HEIGHT / 4.
*/
void	z_gradient(t_vars *vars)
{
	float	abs_z;
	size_t	i;

	i = 0;
	vars->z_max = vars->input[i].z;
	vars->z_min = vars->input[i].z;
	while (i < vars->input_len)
	{
		if (vars->input[i].z > vars->z_max)
			vars->z_max = vars->input[i].z;
		if (vars->input[i].z < vars->z_min)
			vars->z_min = vars->input[i].z;
		i++;
	}
	abs_z = absolute_float(vars->z_max - vars->z_min);
	if (abs_z == 0)
		vars->z_grad = 0;
	else
		vars->z_grad = S_HEIGHT / (4 * abs_z);
}

/*
scale_z creates a scaling gradient called z_grad and multiplies it with the 
given input value of the z in the map. The z_grad is set to a maximum of 125
divided by the absolute values of z-max and z-min
*/
void	scale_z(t_vars *vars, float old_z_grad)
{
	size_t	i;

	i = 0;
	vars->z_grad = vars->z_grad / old_z_grad;
	while (i < vars->input_len)
	{
		vars->input[i].z *= vars->z_grad;
		i++;
	}
}
