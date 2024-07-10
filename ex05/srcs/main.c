/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 15:05:20 by marvin            #+#    #+#             */
/*   Updated: 2024/07/01 16:55:35 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "../includes/utils.h"

int	main(int argc, char **argv)
{
	int		grid_size;
	int		n;
	char	**matrix;

	if (argc != 2)
	{
		printf("Invalid Arguments: star_walking <n_value>\n");
		return (1);
	}
	n = atoi(argv[1]);
	if (n < 2 || n > 100)
	{
		printf("Arguments must be between 2 and 100.\n");
		return (1);
	}
	grid_size = (4 * n) - 3;
	matrix = create_matrix(grid_size);
	if (matrix == NULL)
		return (1);
	place_center_star(matrix, grid_size);
	process_grids(matrix, n);
	print_matrix(matrix, grid_size);
	free_matrix(matrix, grid_size);
	return (0);
}
