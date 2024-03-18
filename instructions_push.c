/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_instructions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heltayb <heltayb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 09:31:15 by heltayb           #+#    #+#             */
/*   Updated: 2024/02/25 16:12:03 by heltayb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*head;
	t_stack	*temp;
	t_stack	*temp1;

	if (!stack_a || !*stack_a || lst_size(*stack_a) == 0)
		return ;
	head = (*stack_a)->next;
	temp = *stack_a;
	temp1 = *stack_b;
	*stack_a = head;
	*stack_b = temp;
	(*stack_b)->next = temp1;
	write(1, "pb\n", 3);
}

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*head;
	t_stack	*temp;
	t_stack	*temp1;

	if (!stack_b || !*stack_b || lst_size(*stack_b) == 0)
		return ;
	head = (*stack_b)->next;
	temp = *stack_b;
	temp1 = *stack_a;
	*stack_b = head;
	*stack_a = temp;
	(*stack_a)->next = temp1;
	write(1, "pa\n", 3);
}
