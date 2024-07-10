/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 16:12:19 by marvin            #+#    #+#             */
/*   Updated: 2024/07/01 16:17:32 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../includes/utils.h"

void	place_center_star(char **matrix, int grid_size)
{
	int	center;

	center = grid_size / 2;
	matrix[center][center] = '*';
}

void	process_grids(char **matrix, int n)
{
	int	grid_size;
	int	start_pos;
	int	current_n;
	int	current_grid_size;

	current_n = n;
	while (current_n >= 2)
	{
		grid_size = (4 * n) - 3;
		current_grid_size = (4 * current_n) - 3;
		start_pos = (grid_size - current_grid_size) / 2;
		fill_matrix(matrix, current_grid_size, start_pos, start_pos);
		current_n--;
	}
}
