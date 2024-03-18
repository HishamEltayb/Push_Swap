/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_helpers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heltayb <heltayb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 13:24:55 by heltayb           #+#    #+#             */
/*   Updated: 2024/02/26 07:28:34 by heltayb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		is_sorted(t_stack *stack);
int		min_sorted_index_four(t_stack *stack);

int	is_sorted(t_stack *stack)
{
	int		temp;
	t_stack	*head;

	head = stack;
	while (head->next)
	{
		temp = head->value;
		head = head->next;
		if (temp > head->value)
			return (0);
	}
	return (1);
}

int	min_sorted_index_four(t_stack *stack)
{
	int		min;
	int		i;
	t_stack	*head;

	i = 0;
	min = (stack)->sorted_index;
	head = stack;
	while (i < 4)
	{
		if (head->sorted_index < min)
			min = head->sorted_index;
		head = head->next;
		i++;
	}
	return (min);
}
