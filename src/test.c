// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        ::::::::            */
// /*   test.c                                             :+:    :+:            */
// /*                                                     +:+                    */
// /*   By: sde-quai <sde-quai@student.codam.nl>         +#+                     */
// /*                                                   +#+                      */
// /*   Created: 2021/12/10 09:37:08 by sde-quai      #+#    #+#                 */
// /*   Updated: 2021/12/10 12:02:48 by sde-quai      ########   odam.nl         */
// /*                                                                            */
// /* ************************************************************************** */

// #include "fdf.h"
// #include <stdio.h>

// typedef struct	s_data {
// 	void	*img;
// 	char	*addr;
// 	int		bits_per_pixel;
// 	int		line_length;
// 	int		endian;
// }				t_data;

// typedef struct	s_vars {
// 	void	*mlx;
// 	void	*win;
// }				t_vars;

// int	key_hook(int keycode, t_vars *vars)
// {
// 	printf("Hello from key_hook!\n");
// 	return (0);
// }


// void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned int*)dst = color;
// }

// int	main(void)
// {
// 	void	*mlx;
// 	void	*mlx_win;
// 	t_data	img;

// 	mlx = mlx_init();
// 	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello worl");
// 	img.img = mlx_new_image(mlx, 1920, 1080);
// 	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
// 								&img.endian);
// 	my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
// 	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
// 	mlx_put_image_to_window(mlx, mlx_win, img.img, 20, 0);
// 	mlx_loop(mlx);

// 	t_vars	vars;

// 	vars.mlx = mlx_init();
// 	vars.win = mlx_new_window(vars.mlx, 640, 480, "Hello world!");
// 	mlx_key_hook(vars.win, key_hook, &vars);
// 	mlx_loop(vars.mlx);
// }

// typedef struct	s_vars {
// 	void	*mlx;
// 	void	*win;
// }				t_vars;

// static int	closes(int keycode, t_vars *vars)
// {
// 	mlx_destroy_window(vars->mlx, vars->win);
	
// }

// int	main(void)
// {
// 	t_vars	vars;

// 	vars.mlx = mlx_init();
// 	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!");
// 	mlx_hook(vars.win, 2, 1L<<0, closes, &vars);
// 	mlx_loop(vars.mlx);
// }