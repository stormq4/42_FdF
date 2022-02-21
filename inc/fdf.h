/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: sde-quai <sde-quai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/10 12:19:54 by sde-quai      #+#    #+#                 */
/*   Updated: 2022/02/21 10:44:42 by sde-quai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include "libft.h"
# include "get_next_line.h"
# include "mlx.h"

# define _USE_MATH_DEFINES

# define S_WIDTH 1000
# define S_HEIGHT 1000
# define RED_COLOR 16711680
# define WHITE_COLOR 16777215
# define BLACK_COLOR 0

typedef enum e_keys {
	ESC = 53,
	RED_CROSS = 17,
	SCROLL_DOWN = 4,
	SCROLL_UP = 5,
	LEFT_CLICK = 1,
	A = 0,
	S = 1,
	D = 2,
	Z = 6,
	X = 7,
	Q = 12,
	W = 13,
	E = 14
}			t_keys;

typedef enum e_wl {
	HEIGHT,
	WIDTH
}			t_wl;

typedef enum e_zoom {
	IN,
	OUT
}			t_zoom;

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_plot {
	float	dy;
	float	dx;
	float	yi;
	float	xi;
	float	dis;
	float	initial_val;
}				t_plot;

typedef struct s_pixel {
	float	x;
	float	y;
	float	z;
}				t_pixel;

typedef struct s_rotate {
	float	x_0;
	float	y_0;
	float	x_1;
	float	y_1;
	float	z_1;
	float	angle;
}				t_rotation;

typedef struct s_angle {
	float	d_x;
	float	d_y;
	float	d_z;
}				t_angle;

typedef struct s_vars {
	t_data	img;
	t_pixel	*input;
	t_pixel	*compute;
	t_angle	angle;
	void	*mlx;
	void	*win;
	size_t	input_len;
	size_t	x;
	size_t	y;
	float	z_max;
	float	z_min;
	float	z_grad;
	size_t	line_length;
	float	x_origin;
	float	y_origin;
}				t_vars;

t_pixel	*convert_input(char **argv, size_t input_len);
void	retrieve_array_length(char **argv, t_vars *vars);
char	*remove_newline(char *line);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	put_to_screen(t_vars vars);
float	absolute_float(float abs);
size_t	determine_line_length(t_vars *vars, t_wl DIM, size_t len);
void	open_window(t_data *img, t_vars *vars);
void	free_fdf(t_vars vars);
int		close_screen(int keycode, t_vars *vars);
void	render_key_events(int keycode, t_vars *ars);
int		render_next_frame(t_vars *vars);
void	make_screen_black(t_vars *vars);
int		estimate_pixel_in_window(float x, float y);
void	draw_line(t_vars *vars, t_pixel vars0, t_pixel vars1);
void	zoom(t_vars *vars, t_zoom zoom);
t_pixel	*create_compute_array(size_t input_len);
void	make_vars_compute(t_vars *vars, t_angle angle);
int		increase_z(int keycode, t_vars *vars);
t_pixel	rotate_z_axis(t_vars *vars, t_pixel point, t_angle angle);
int		rotate_angle(int keycode, t_vars *vars);
void	create_angle_struct(t_vars *vars);
void	scale_z(t_vars *vars, float old_z_grad);
void	z_gradient(t_vars *vars);

#endif
