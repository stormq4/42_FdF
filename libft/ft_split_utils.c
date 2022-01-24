/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split_utils.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: stormdequay <stormdequay@student.codam.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/12 11:29:19 by stormdequay   #+#    #+#                 */
/*   Updated: 2022/01/18 11:37:25 by sde-quai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_split_free(char **split)
{
	size_t	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

int	ft_split_len(char **split)
{
	int	i;

	i = 0;
	if (!split)
		return (i);
	while (split[i])
		i++;
	return (i);
}