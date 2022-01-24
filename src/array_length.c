/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   array_length.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: sde-quai <sde-quai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/19 15:38:41 by sde-quai      #+#    #+#                 */
/*   Updated: 2022/01/24 15:02:23 by sde-quai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

char	*remove_newline(char *line)
{
	char	*new_line;

	new_line = ft_strdup_c(line, '\n');
	ft_check_malloc(new_line);
	free(line);
	return (new_line);
}

size_t	retrieve_array_length(char **argv)
{
	int		fd;
	char	*line;
	char	**line_2d;
	size_t	x;
	size_t	y;

	fd = open(argv[1], O_RDONLY);
	line = get_next_line(fd);
	line = remove_newline(line);
	line_2d = ft_split(line, ' ');
	ft_check_malloc(line_2d);
	x = ft_split_len(line_2d);
	ft_split_free(line_2d);
	y = 0;
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		y++;
	}
	free(line);
	close(fd);
	return (y * x);
}
