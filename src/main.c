/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: sde-quai <sde-quai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/10 09:37:08 by sde-quai      #+#    #+#                 */
/*   Updated: 2021/12/13 16:57:28 by sde-quai      ########   odam.nl         */
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

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	test_put(t_pixl *lst, t_data img)
{
	int	i;
	int appart;

	appart = 20;
	while (lst)
	{
		i = lst->y * appart;
		while (i < (lst->y) * appart + appart)
		{
			my_mlx_pixel_put(&img, lst->x * appart + S_WIDTH / 4 , lst->y * appart + i + S_HEIGHT / 4, 0x00FF0000);
			i++;
		}
		i = lst->x * appart;
		while (i < (lst->x) * appart + appart)
		{
			my_mlx_pixel_put(&img, lst->x * appart + i + S_WIDTH / 4 , lst->y * appart + S_HEIGHT / 4, 0x00FF0000);
			i++;
		}
		// printf("x :%i -- y:%i -- z:%i\n",lst->x, lst->y, lst->z);
		my_mlx_pixel_put(&img, lst->x * appart + S_WIDTH / 4 , lst->y * appart + S_HEIGHT / 4, 0x00FF0000);
		lst = lst->next;
	}
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
	mlx_win = mlx_new_window(mlx, S_WIDTH, S_HEIGHT, "Hello world!");
	img.img = mlx_new_image(mlx, S_WIDTH, S_HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	test_put(lst, img);
	// printf("test\n");
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
	return (0);
}
