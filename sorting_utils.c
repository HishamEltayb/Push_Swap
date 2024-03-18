/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heltayb <heltayb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 10:19:21 by heltayb           #+#    #+#             */
/*   Updated: 2024/02/25 21:57:57 by heltayb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		is_rotate_looping(t_stack *head, int middle, int point);
static int		is_rotate(t_stack *stack, int middle, int point);
static int		swap_or_rotate(t_stack **stack, int middle, int value);
void			push_to_stack_b(t_stack **stack_a, t_stack **stack_b, int size);
void			push_to_stack_a(t_stack **stack_a,
					t_stack **stack_b, int size_a, int size_b);

static int	is_rotate_looping(t_stack *head, int middle, int point)
{
	int	moves;
	int	i;

	i = 0;
	moves = 0;
	while (head)
	{
		if (!middle && head->sorted_index < point)
		{
			moves = i;
			break ;
		}
		if (middle && head->sorted_index == point)
		{
			moves = i;
			break ;
		}
		if (!head)
			break ;
		head = head->next;
		i++;
	}
	return (moves);
}

static int	is_rotate(t_stack *stack, int middle, int point)
{
	int		moves;
	int		moves_ra;
	int		moves_rra;
	t_stack	*head;

	if (!stack)
		return (-2);
	head = stack;
	moves = is_rotate_looping(head, middle, point);
	moves_ra = moves;
	moves_rra = lst_size(stack) - moves + 1;
	if (moves == 1)
		return (-1);
	if (moves_ra <= moves_rra)
		return (0);
	else if (moves_ra > moves_rra)
		return (1);
	return (0);
}

static int	swap_or_rotate(t_stack **stack, int middle, int value)
{
	if (!middle)
	{
		if (is_rotate(*stack, middle, value) == -2)
			return (0);
		else if (is_rotate(*stack, middle, value) == 0)
			ra(stack);
		else if (is_rotate(*stack, middle, value) == 1)
			rra(stack);
		else if (is_rotate(*stack, middle, value) == -1)
			sa(stack);
	}
	else
	{
		if (is_rotate(*stack, middle, value) == -2)
			return (0);
		else if (is_rotate(*stack, middle, value) == 0)
			rb(stack);
		else if (is_rotate(*stack, middle, value) == 1)
			rrb(stack);
		else if (is_rotate(*stack, middle, value) == -1)
			sb(stack);
	}
	return (1);
}

void	push_to_stack_b(t_stack **stack_a, t_stack **stack_b, int size)
{
	int	min;
	int	max;
	int	chunk;
	int	index;

	index = 0;
	while (lst_size(*stack_a) >= 5)
	{
		min = index;
		chunk = (lst_size(*stack_a) / 5) + (lst_size(*stack_a) % 5);
		max = min + chunk;
		while (index < max && chunk > 0)
		{
			while (index < size && ((*stack_a)->sorted_index < max
					&& index < max))
			{
				if ((index > 0) && ((*stack_a)->value > (*stack_b)->value))
					rb(stack_b);
				pb(stack_a, stack_b);
				index++;
			}
			if ((index < max) && !swap_or_rotate(stack_a, 0, max))
				break ;
		}
	}
}

void	push_to_stack_a(t_stack **stack_a,
			t_stack **stack_b, int size_a, int size_b)
{
	int	index;

	index = 0;
	while (index < size_b)
	{
		if (index >= size_b)
			break ;
		if ((!stack_a || !*stack_a))
		{
			while ((*stack_b)->sorted_index != size_a - 1)
				swap_or_rotate(stack_b, 1, size_a - 1);
			pa(stack_a, stack_b);
			index++;
		}
		else if (index < size_b
			&& ((*stack_b)->sorted_index == ((*stack_a)->sorted_index - 1)))
		{
			pa(stack_a, stack_b);
			index++;
		}
		else if ((index < size_b)
			&& !swap_or_rotate(stack_b, 1, (*stack_a)->sorted_index - 1))
			break ;
	}
}
