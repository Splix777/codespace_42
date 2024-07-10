/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 16:08:44 by marvin            #+#    #+#             */
/*   Updated: 2024/07/01 16:16:25 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

// Utils.c
char	**allocate_matrix(int grid_size);
char	**create_matrix(int grid_size);
void	free_matrix(char **matrix, int grid_size);
void	print_matrix(char **matrix, int grid_size);
void	fill_matrix(char **matrix, int grid_size, int start_row, int start_col);
// Utils2.c
void	place_center_star(char **matrix, int grid_size);
void	process_grids(char **matrix, int n);

#endif
