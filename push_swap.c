/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heltayb <heltayb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 11:40:32 by heltayb           #+#    #+#             */
/*   Updated: 2024/02/25 19:03:32 by heltayb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_arr	*arr;
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ac > 1)
	{
		arr = convert_to_number(av, ac);
		if (!arr)
			error();
		if (!is_valid(arr))
			return (free_arr(arr), error(), 1);
		stack_a = initialize_stack(arr);
		free_arr(arr);
		sorting(&stack_a, &stack_b);
		free_lst(&stack_a);
		free_lst(&stack_b);
	}
	return (0);
}
