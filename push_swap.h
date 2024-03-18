/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heltayb <heltayb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 11:29:42 by heltayb           #+#    #+#             */
/*   Updated: 2024/02/26 07:42:36 by heltayb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

//struct of the stacks
typedef struct s_stack
{
	int					value;
	int					sorted_index;
	struct s_stack		*next;
}	t_stack;

//struct of split variables (just for norminitte)
typedef struct s_split
{
	int	index;
	int	words;
	int	first;
}	t_split;

//Struct for the array holding the valid unsorted numbers as longs
typedef struct s_arr
{
	long	*value;
	int		size;
}	t_arr;

//Struct for the array holding the valid sorted numbers as integers
typedef struct s_sorted_arr
{
	int			*value;
	int			size;
}	t_sorted_arr;

// check for the validaty (ft_valid.c)
int				is_valid(t_arr *num);
void			check_all_spaces(char **av, int ac);

//splits the arguments (ft_split.c) 
char			**ft_split(char *str);

// converting the string to number (ft_string_to_num.c)
t_arr			*convert_to_number(char **av, int ac);

//stack initilize(initialize_stack.c)
t_stack			*initialize_stack(t_arr *arr);
int				lst_size(t_stack *stack);
t_sorted_arr	*sort_arr(t_arr *arr);

//push (instructions_push.c)
void			pa(t_stack **stack_a, t_stack **stack_b);
void			pb(t_stack **stack_a, t_stack **stack_b);

//swap (instructions_swap.c)
void			sa(t_stack **stack_a);
void			sb(t_stack **stack_b);
void			ss(t_stack **stack_a, t_stack **stack_b);

//rotate (instructions_rotate.c)
void			ra(t_stack **stack_a);
void			rb(t_stack **stack_b);
void			rr(t_stack **stack_a, t_stack **stack_b);

//reverse rotate (instructions_reverse_rotate.c)
void			rra(t_stack **stack_a);
void			rrb(t_stack **stack_b);
void			rrr(t_stack **stack_a, t_stack **stack_b);

//free and error message and exiting (ft_free.c)
void			free_lst(t_stack **stack);
void			free_arr(t_arr *num);
void			free_arr_sort(t_sorted_arr *num);
void			free_split_of_splits(char ***ptr, int i);
void			error(void);

//sorting stacks functions (sorting.c)
void			sorting(t_stack **stack_a, t_stack **stack_b);

//sorting utils for stacks functions (sorting_utils.c)
void			push_to_stack_b(t_stack **stack_a, t_stack **stack_b, int size);
void			push_to_stack_a(t_stack **stack_a,
					t_stack **stack_b, int size_a, int size_b);

//sorting stacks functions (sorting_helpers.c)
int				is_sorted(t_stack *stack);
int				min_sorted_index_four(t_stack *stack);

#endif