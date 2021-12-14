/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   t_pixl.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: sde-quai <sde-quai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/10 15:54:11 by sde-quai      #+#    #+#                 */
/*   Updated: 2021/12/13 15:23:34 by sde-quai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_pixl	*pixl_lstnew(int i, int j, int k)
{
	t_pixl	*new;

	new = malloc(sizeof(t_pixl));
	check_malloc(new);
	new->x = i;
	new->y = j;
	new->z = k;
	new->next = NULL;
	return (new);
}

void	pixl_lstadd_back(t_pixl **lst, t_pixl *new)
{
	t_pixl *tmp;

	if (*lst)
	{
		tmp = pixl_lstlast(*lst);
		tmp->next = new;
	}
	else
		*lst = new;
}

t_pixl	*pixl_lstlast(t_pixl *lst)
{
	if (!lst)
		return (NULL);
	while (lst)
	{
		if (lst->next == NULL)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}