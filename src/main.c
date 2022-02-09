/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: sde-quai <sde-quai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/10 09:37:08 by sde-quai      #+#    #+#                 */
/*   Updated: 2022/02/08 11:08:38 by sde-quai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_vars	vars;

	if (argc != 2)
		return (0);
	retrieve_array_length(argv, &vars);
	vars.input = convert_input(argv, vars.input_len);
	vars.line_length = determine_line_length(&vars, HEIGHT, 20);
	angle_input(&vars);
	open_window(&vars.img, &vars);
	put_to_screen(vars);
	render_next_frame(&vars);
	mlx_loop(vars.mlx);
	free_fdf(vars);
	return (0);
}
