/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heltayb <heltayb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 19:24:38 by heltayb           #+#    #+#             */
/*   Updated: 2024/02/26 07:28:05 by heltayb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		sorting(t_stack **stack_a, t_stack **stack_b);
static void	sorting_three(t_stack **stack);
static void	sorting_four(t_stack **stack_a, t_stack **stack_b);
static void	sorting_multi(t_stack **stack_a, t_stack **stack_b);

void	sorting(t_stack **stack_a, t_stack **stack_b)
{
	if (lst_size(*stack_a) < 2)
		return ;
	if (!is_sorted(*stack_a))
	{
		if (lst_size(*stack_a) == 2)
			sa(stack_a);
		else if (lst_size(*stack_a) == 3)
			sorting_three(stack_a);
		else if (lst_size(*stack_a) == 4)
			sorting_four(stack_a, stack_b);
		else
		{
			sorting_multi(stack_a, stack_b);
			return ;
		}
	}
}

void	sorting_three(t_stack **stack)
{
	t_stack	*head;
	int		num1;
	int		num2;
	int		num3;

	head = *stack;
	num1 = head->value;
	num2 = head->next->value;
	num3 = head->next->next->value;
	if (num1 > num2 && num1 > num3)
		ra(stack);
	else if (num2 > num1 && num2 > num3)
		rra(stack);
	if ((*stack)->value > (*stack)->next->value)
		sa(stack);
}

void	sorting_four(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*head;
	int		min;

	min = min_sorted_index_four(*stack_a);
	head = *stack_a;
	while (head)
	{
		if ((*stack_a)->sorted_index == min)
		{
			pb(stack_a, stack_b);
			break ;
		}
		else
			ra(stack_a);
	}
	sorting_three(stack_a);
	pa(stack_a, stack_b);
}

void	sorting_multi(t_stack **stack_a, t_stack **stack_b)
{
	int	size_a;
	int	size_b;

	size_a = lst_size(*stack_a);
	push_to_stack_b(stack_a, stack_b, size_a);
	sorting(stack_a, stack_b);
	size_b = lst_size(*stack_b);
	push_to_stack_a(stack_a, stack_b, size_a, size_b);
}
