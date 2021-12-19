/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   testput.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: sde-quai <sde-quai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/14 13:52:45 by sde-quai      #+#    #+#                 */
/*   Updated: 2021/12/16 12:33:09 by sde-quai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	check_within_frame(int size)
{
	if (size >= S_WIDTH)
		return (FALSE);
	return (TRUE);
}

void	test_put(t_pixl *lst, t_data img)
{
	int		i;
	int		appart;
	t_pixl	*tmp;
	int		x_max;
	int		y_max;

	tmp = pixl_lstlast(lst);
	x_max = tmp->x;
	y_max = tmp->y;
	appart = 30;
	while (lst)
	{
		if (lst->x < x_max)
		{
			i = lst->x * appart;
			while (i < lst->x * appart + appart)
			{
				if (check_within_frame(i + S_WIDTH / 4) && check_within_frame(lst->y * appart + S_HEIGHT / 4))
					my_mlx_pixel_put(&img, i + S_WIDTH / 4, lst->y * appart + S_HEIGHT / 4, 0x00FF0000);
				else
					break ;
				i++;
			}
		}
		if (lst->y < y_max)
		{
			i = lst->y * appart;
			while (i < lst->y * appart + appart)
			{
				if (check_within_frame(lst->x * appart + S_WIDTH / 4) && check_within_frame(i + S_HEIGHT / 4))
					my_mlx_pixel_put(&img, lst->x * appart + S_WIDTH / 4, i + S_HEIGHT / 4, 0x00FF0000);
				else
					break ;
				i++;
			}
		}
		if (check_within_frame(lst->x * appart + S_WIDTH / 4) && check_within_frame(lst->y * appart + S_HEIGHT / 4))
			my_mlx_pixel_put(&img, lst->x * appart + S_WIDTH / 4, lst->y * appart + S_HEIGHT / 4, 0x00FF0000);
		lst = lst->next;
	}
}
