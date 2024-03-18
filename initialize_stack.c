/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heltayb <heltayb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 09:18:05 by heltayb           #+#    #+#             */
/*   Updated: 2024/02/26 07:31:10 by heltayb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//stack initilize(stacks/stacks.c)
int				lst_size(t_stack *stack);
t_stack			*initialize_stack(t_arr *arr);
static t_stack	*lstnew(long num, t_sorted_arr *arr);
static void		lst_addback(t_stack **lst, t_stack *new_node);
t_sorted_arr	*sort_arr(t_arr *arr);

t_sorted_arr	*sort_arr(t_arr *arr)
{
	int				i;
	t_sorted_arr	*arr_sorted;
	int				temp;

	i = -1;
	arr_sorted = malloc(sizeof(t_sorted_arr));
	arr_sorted->value = malloc(sizeof(int) * arr->size);
	arr_sorted->size = arr->size;
	while (++i < arr->size)
		arr_sorted->value[i] = arr->value[i];
	i = 0;
	while (i < (arr_sorted->size - 1))
	{
		if (arr_sorted->value[i] > arr_sorted->value[i + 1])
		{
			temp = arr_sorted->value[i];
			arr_sorted->value[i] = arr_sorted->value[i + 1];
			arr_sorted->value[i + 1] = temp;
			i = -1;
		}
		i++;
	}
	return (arr_sorted);
}

t_stack	*initialize_stack(t_arr *arr)
{
	t_stack			*stack;
	t_stack			*new_node;
	t_sorted_arr	*arr_sorted;
	int				i;

	if (!arr)
		return (NULL);
	arr_sorted = sort_arr(arr);
	stack = NULL;
	i = 0;
	while (i < arr->size)
	{
		new_node = lstnew(arr->value[i], arr_sorted);
		lst_addback(&stack, new_node);
		i++;
	}
	free_arr_sort(arr_sorted);
	return (stack);
}

static void	lst_addback(t_stack **lst, t_stack *new_node)
{
	t_stack	*head;

	if (lst == NULL)
		return ;
	if (!*lst)
	{
		*lst = new_node;
		return ;
	}
	head = *lst;
	while (head->next)
		head = head->next;
	head->next = new_node;
}

static t_stack	*lstnew(long num, t_sorted_arr *arr)
{
	int		j;
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	new_node->value = num;
	j = 0;
	while (j < arr->size)
	{
		if (num == arr->value[j])
		{
			new_node->sorted_index = j;
			break ;
		}
		j++;
	}
	new_node->next = NULL;
	return (new_node);
}

int	lst_size(t_stack *stack)
{
	t_stack	*head;
	int		i;

	i = 0;
	head = stack;
	while (head != NULL)
	{
		head = head->next;
		i++;
	}
	return (i);
}
