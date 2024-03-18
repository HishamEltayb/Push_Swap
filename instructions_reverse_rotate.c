/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_instructions.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heltayb <heltayb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 10:03:37 by heltayb           #+#    #+#             */
/*   Updated: 2024/02/25 16:12:14 by heltayb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		rra(t_stack **stack_a);
void		rrb(t_stack **stack_b);
void		rrr(t_stack **stack_a, t_stack **stack_b);
static void	reverse_rotate_fuction(t_stack **stack, int id);

void	rra(t_stack **stack_a)
{
	reverse_rotate_fuction(stack_a, 1);
}

void	rrb(t_stack **stack_b)
{
	reverse_rotate_fuction(stack_b, 2);
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	reverse_rotate_fuction(stack_a, 0);
	reverse_rotate_fuction(stack_b, 3);
}

static void	reverse_rotate_fuction(t_stack **stack, int id)
{
	t_stack	*head;
	t_stack	*temp;

	if (!stack || !*stack || lst_size(*stack) < 3)
		return ;
	head = *stack;
	while (head)
	{
		if (!(head->next->next))
		{
			temp = head->next;
			head->next->next = *stack;
			head->next = NULL;
			*stack = temp;
			break ;
		}
		head = head->next;
	}
	if (id == 1)
		write(1, "rra\n", 4);
	else if (id == 2)
		write(1, "rrb\n", 4);
	else if (id == 3)
		write(1, "rrr\n", 4);
}
