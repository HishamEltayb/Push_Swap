/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heltayb <heltayb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 13:19:30 by heltayb           #+#    #+#             */
/*   Updated: 2024/02/25 16:25:27 by heltayb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//free (free_functions.c)
void	free_lst(t_stack **stack);
void	free_arr(t_arr *num);
void	free_arr_sort(t_sorted_arr *num);
void	free_split_of_splits(char ***ptr, int i);

//EXITING and printing the error message
void	error(void);

void	free_lst(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*head;

	if (!stack || !*stack)
		return ;
	head = *stack;
	while (head)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
	*stack = NULL;
}

void	free_arr(t_arr *num)
{
	free(num->value);
	free(num);
}

void	free_arr_sort(t_sorted_arr *num)
{
	free(num->value);
	free(num);
}

void	error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	free_split_of_splits(char ***ptr, int i)
{
	int	j;

	if (!ptr)
		return ;
	if (ptr[i] == NULL)
	{
		free(ptr[i]);
		ptr[i] = NULL;
		i--;
	}
	while (i >= 0)
	{
		j = 0;
		while (ptr[i][j])
		{
			free(ptr[i][j]);
			ptr[i][j] = NULL;
			j++;
		}
		free(ptr[i]);
		ptr[i] = NULL;
		i--;
	}
	free(ptr);
	ptr = NULL;
}
