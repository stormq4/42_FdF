/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: sde-quai <sde-quai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/10 12:19:54 by sde-quai      #+#    #+#                 */
/*   Updated: 2021/12/13 16:16:57 by sde-quai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define S_WIDTH 1000
# define S_HEIGHT 1000
# include "../mlx/mlx.h"
# include "../gnl/get_next_line.h"
# include "../libft/libft.h"

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

typedef struct	s_pixl {
	int	x;
	int	y;
	int	z;
	struct	s_pixl *next;
}				t_pixl;

void	check_malloc(void *ptr);
t_pixl	*pixl_lstnew(int i, int j, int k);
void	pixl_lstadd_back(t_pixl **lst, t_pixl *new);
t_pixl	*pixl_lstlast(t_pixl *lst);

#endif
