/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 16:06:41 by marvin            #+#    #+#             */
/*   Updated: 2024/07/01 17:48:32 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../includes/utils.h"

void	free_matrix(char **matrix, int grid_size)
{
	int	i;

	i = 0;
	while (i < grid_size)
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

char	**allocate_matrix(int grid_size)
{
	char	**matrix;
	int		i;

	matrix = malloc(grid_size * sizeof(char *));
	if (matrix == NULL)
		return (NULL);
	i = 0;
	while (i < grid_size)
	{
		matrix[i] = malloc(grid_size * sizeof(char));
		if (matrix[i] == NULL)
		{
			free_matrix(matrix, i);
			return (NULL);
		}
		i++;
	}
	return (matrix);
}

char	**create_matrix(int grid_size)
{
	char	**matrix;
	int		i;

	matrix = allocate_matrix(grid_size);
	if (matrix == NULL)
		return (NULL);
	i = 0;
	while (i < grid_size)
	{
		memset(matrix[i], ' ', grid_size * sizeof(char));
		i++;
	}
	return (matrix);
}

void	print_matrix(char **matrix, int grid_size)
{
	int	i;
	int	j;

	i = 0;
	while (i < grid_size)
	{
		j = 0;
		while (j < grid_size)
		{
			printf("%c", matrix[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

void	fill_matrix(char **matrix, int grid_size, int start_row, int start_col)
{
	int	i;
	int	j;

	i = 0;
	while (i < grid_size)
	{
		j = 0;
		while (j < grid_size)
		{
			if (i == 0 || i == grid_size - 1 || j == 0 || j == grid_size - 1)
				matrix[start_row + i][start_col + j] = '*';
			j++;
		}
		i++;
	}
}
