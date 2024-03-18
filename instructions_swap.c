/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_swap.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heltayb <heltayb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 09:41:27 by heltayb           #+#    #+#             */
/*   Updated: 2024/02/26 07:34:15 by heltayb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		sa(t_stack **stack_a);
void		sb(t_stack **stack_b);
void		ss(t_stack **stack_a, t_stack **stack_b);
static void	swap_instructions(t_stack **stack, int id);

void	sa(t_stack **stack_a)
{
	swap_instructions(stack_a, 1);
}

void	sb(t_stack **stack_b)
{
	swap_instructions(stack_b, 2);
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	swap_instructions(stack_a, 0);
	swap_instructions(stack_b, 3);
}

static void	swap_instructions(t_stack **stack, int id)
{
	int		temp;
	int		temp_index_sorted;

	if (!stack || !*stack || lst_size(*stack) < 2)
		return ;
	temp = (*stack)->value;
	temp_index_sorted = (*stack)->sorted_index;
	(*stack)->value = (*stack)->next->value;
	(*stack)->sorted_index = (*stack)->next->sorted_index;
	(*stack)->next->value = temp;
	(*stack)->next->sorted_index = temp_index_sorted;
	if (id == 0)
		return ;
	else if (id == 1)
		write(1, "sa\n", 3);
	else if (id == 2)
		write(1, "sb\n", 3);
	else if (id == 3)
		write(1, "ss\n", 3);
}
