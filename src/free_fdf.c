/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free_fdf.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: sde-quai <sde-quai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/02 09:33:18 by sde-quai      #+#    #+#                 */
/*   Updated: 2022/02/02 15:04:07 by sde-quai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
Function to free allocated memory in the end
 */
void	free_fdf(t_vars vars)
{
	free(vars.input);
	free(vars.compute);
}
