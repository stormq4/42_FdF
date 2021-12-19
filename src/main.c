/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: sde-quai <sde-quai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/10 09:37:08 by sde-quai      #+#    #+#                 */
/*   Updated: 2021/12/14 13:53:02 by sde-quai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

t_pixl	*conv_mapdata(char **line2d, int i, t_pixl **lst)
{
	t_pixl	*tmp;
	int		j;

	j = 0;
	while (line2d[j])
	{
		tmp = pixl_lstnew(i, j, ft_atoi(line2d[j]));
		pixl_lstadd_back(lst, tmp);
		j++;
	}
	return (*lst);
}

t_pixl	*read_file(char **argv)
{
	char	**line2d;
	int		fd;
	char	*line;
	int		i;
	t_pixl	*lst;

	fd = open(argv[1], O_RDONLY);
	line = get_next_line(fd);
	i = 0;
	while (line)
	{
		line2d = ft_split(line, ' ');
		check_malloc(line2d);
		lst = conv_mapdata(line2d, i, &lst);
		i++;
		line = get_next_line(fd);
	}
	return (lst);
}

int	main(int argc, char **argv)
{
	t_pixl	*lst;
	t_pixl	*tmp;
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	if (argc != 2)
		return (0);
	lst = read_file(argv);
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, S_WIDTH, S_HEIGHT, "FdF");
	img.img = mlx_new_image(mlx, S_WIDTH, S_HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	test_put(lst, img);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
	return (0);
}
