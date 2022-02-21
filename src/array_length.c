/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   array_length.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: sde-quai <sde-quai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/19 15:38:41 by sde-quai      #+#    #+#                 */
/*   Updated: 2022/02/19 10:20:04 by stormdequay   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
Removes newline at the end of a string
 */
char	*remove_newline(char *line)
{
	char	*new_line;

	new_line = ft_strdup_c(line, '\n');
	ft_check_malloc(new_line);
	free(line);
	return (new_line);
}

/*
Fills the height, width and length of the total array and places it in the 
struct of t_vars in vars
 */
static void	fill_array_data(t_vars *vars, size_t x, char *line, int fd)
{
	size_t	y;

	y = 0;
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		y++;
	}
	free(line);
	close(fd);
	vars->x = x;
	vars->y = y;
	vars->input_len = x * y;
}

/*
This function retrieves the dimensions of the parsed map in terms of 
width(x), height(y) and input_length.
It uses get_next_line(gnl) and ft_split and strdup_c. x_origin and 
y_origin is the middle of the screen for the x and values.
 */
void	retrieve_array_length(char **argv, t_vars *vars)
{
	int		fd;
	char	*line;
	char	**line_2d;
	size_t	x;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0 || fd > OPEN_MAX)
		exit(1);
	line = get_next_line(fd);
	line = remove_newline(line);
	line_2d = ft_split(line, ' ');
	ft_check_malloc(line_2d);
	x = ft_split_len(line_2d);
	ft_split_free(line_2d);
	fill_array_data(vars, x, line, fd);
	vars->x_origin = S_WIDTH / 2;
	vars->y_origin = S_HEIGHT / 2;
}
