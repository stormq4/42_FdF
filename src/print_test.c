/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_test.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: sde-quai <sde-quai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/18 13:42:45 by sde-quai      #+#    #+#                 */
/*   Updated: 2022/01/24 10:46:47 by sde-quai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void	print_test(t_vars vars)
{
	size_t	i;

	i = 0;
	printf("length : %zu\n", vars.input_len);
	while (i < vars.input_len)
	{
		printf("x: %f	y: %f	z: %f\n", \
		vars.input[i].x, vars.input[i].y, vars.input[i].z);
		i++;
	}
}
