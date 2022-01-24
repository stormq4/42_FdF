/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input_handling.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: sde-quai <sde-quai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/19 14:42:19 by sde-quai      #+#    #+#                 */
/*   Updated: 2022/01/24 10:31:59 by sde-quai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

static t_pixel	*fill_vector_array(char **line_2d, int line_len, \
int y, t_pixel	*array)
{
	t_pixel	tmp;
	int		x;
	int		array_len;

	array_len = line_len * y;
	x = 0;
	while (x < line_len)
	{
		tmp.x = (float)x;
		tmp.y = (float)y;
		tmp.z = (float)ft_atoi(line_2d[x]);
		array[array_len + x] = tmp;
		x++;
	}
	return (array);
}

static t_pixel	*convert_input_to_vector(char *line, \
t_pixel *input_array, int y)
{
	char	**line_2d;
	int		line_len;

	line = remove_newline(line);
	line_2d = ft_split(line, ' ');
	ft_check_malloc(line_2d);
	line_len = ft_split_len(line_2d);
	input_array = fill_vector_array(line_2d, line_len, y, input_array);
	free(line);
	ft_split_free(line_2d);
	return (input_array);
}

t_pixel	*convert_input(char **argv, size_t input_len)
{
	int		fd;
	int		y;
	char	*line;
	t_pixel	*input_array;

	input_array = malloc(sizeof(t_pixel) * input_len);
	ft_check_malloc(input_array);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		exit(1);
	line = get_next_line(fd);
	y = 0;
	while (line)
	{
		input_array = convert_input_to_vector(line, input_array, y);
		line = get_next_line(fd);
		y++;
	}
	close(fd);
	return (input_array);
}
