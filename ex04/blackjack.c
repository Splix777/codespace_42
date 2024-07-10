/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blackjack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 10:58:18 by marvin            #+#    #+#             */
/*   Updated: 2024/07/01 16:47:27 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void	check_valid_card(char card)
{
	if (strchr("23456789TJDKA", card) == NULL)
	{
		printf("Error: Invalid card '%c' found.\n", card);
		exit(1);
	}
}

void	update_points(char card, int *total_points, int *num_aces)
{
	check_valid_card(card);
	if (strchr("23456789", card) != NULL)
		*total_points += (card - '0');
	else if (strchr("TJDK", card) != NULL)
		*total_points += 10;
	else if (card == 'A')
	{
		*total_points += 11;
		(*num_aces)++;
	}
}

void	adjust_for_aces(int *total_points, int *num_aces)
{
	while (*total_points > 21 && *num_aces > 0)
	{
		*total_points -= 10;
		(*num_aces)--;
	}
}

void	print_result(int total_points)
{
	if (total_points == 21)
		printf("Blackjack!\n");
	else if (total_points > 21)
		printf("BUST! '%d'\n", total_points);
	else
		printf("Hand Value: %d\n", total_points);
}

int	main(int argc, char **argv)
{
	char	*hand;
	int		total_points;
	int		num_aces;
	int		i;

	if (argc != 2)
	{
		printf("Invalid arguments: blackjack <cards>");
		exit(1);
	}
	total_points = 0;
	num_aces = 0;
	i = 0;
	hand = argv[1];
	while (hand[i] != '\0')
	{
		update_points(hand[i], &total_points, &num_aces);
		i++;
	}
	adjust_for_aces(&total_points, &num_aces);
	print_result(total_points);
	return (0);
}
