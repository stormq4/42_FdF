/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: sde-quai <sde-quai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/10 09:37:08 by sde-quai      #+#    #+#                 */
/*   Updated: 2022/01/24 10:47:12 by sde-quai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int	main(int argc, char **argv)
{
	t_vars	vars;
	// t_data	img;

	if (argc != 2)
		return (0);
	vars.input_len = retrieve_array_length(argv);
	vars.input = convert_input(argv, vars.input_len);
	print_test(vars);
	// vars.mlx = mlx_init();
	// vars.win = mlx_new_window(vars.mlx, S_WIDTH, S_HEIGHT, "FdF");
	// img.img = mlx_new_image(vars.mlx, S_WIDTH, S_HEIGHT);
	// img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
	// 							&img.endian);
	// test_put(lst, img);
	// mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	// mlx_loop(vars.mlx);
	free(vars.input);
	// system("leaks fdf");
	return (0);
}
