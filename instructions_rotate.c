/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_instructions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heltayb <heltayb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 09:43:48 by heltayb           #+#    #+#             */
/*   Updated: 2024/02/25 16:12:17 by heltayb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ra(t_stack **stack_a);
void		rb(t_stack **stack_b);
void		rr(t_stack **stack_a, t_stack **stack_b);
static void	rotate_fuction(t_stack **stack, int id);

void	ra(t_stack **stack_a)
{
	rotate_fuction(stack_a, 1);
}

void	rb(t_stack **stack_b)
{
	rotate_fuction(stack_b, 2);
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	rotate_fuction(stack_a, 0);
	rotate_fuction(stack_b, 3);
}

static void	rotate_fuction(t_stack **stack, int id)
{
	t_stack	*head;
	t_stack	*temp;

	if (!stack || !*stack || lst_size(*stack) < 3)
		return ;
	temp = (*stack)->next;
	head = *stack;
	while (head)
	{
		head = head->next;
		if (!(head->next))
		{
			(*stack)->next = NULL;
			head->next = *stack;
			*stack = temp;
			break ;
		}
	}
	if (id == 1)
		write(1, "ra\n", 3);
	else if (id == 2)
		write(1, "rb\n", 3);
	else if (id == 3)
		write(1, "rr\n", 3);
}
