/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: sde-quai <sde-quai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/10 12:19:54 by sde-quai      #+#    #+#                 */
/*   Updated: 2022/01/24 10:44:31 by sde-quai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define S_WIDTH 1000
# define S_HEIGHT 1000
# define TRUE 1
# define FALSE 0
# include "../mlx/mlx.h"
# include "../gnl/get_next_line.h"
# include "../libft/libft.h"

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_pixel {
	float	x;
	float	y;
	float	z;
}				t_pixel;

typedef struct s_vars {
	void	*mlx;
	void	*win;
	t_pixel	*input;
	size_t	input_len;
}				t_vars;

t_pixel	*convert_input(char **argv, size_t input_len);
size_t	retrieve_array_length(char **argv);
char	*remove_newline(char *line);
void	print_test(t_vars vars); //delete
#endif
