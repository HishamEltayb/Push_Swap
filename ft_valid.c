/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heltayb <heltayb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 17:48:41 by heltayb           #+#    #+#             */
/*   Updated: 2024/02/25 16:28:26 by heltayb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//function to check the validatiy of the numbers
int			is_valid(t_arr *num);
static int	is_duplicat(long *num, long n, int size, int pos);
static int	is_space(char c);
void		check_all_spaces(char **av, int ac);

int	is_valid(t_arr *num)
{
	int	i;

	if (!num->value)
		return (0);
	i = 0;
	while (i < num->size)
	{
		if (!is_duplicat(num->value, num->value[i], num->size, i + 1))
			return (0);
		i++;
	}
	return (1);
}

static int	is_duplicat(long *num, long n, int size, int pos)
{
	if (!num || n > INT_MAX || n < INT_MIN)
		return (0);
	while (pos < size)
	{
		if (num[pos] == n)
			return (0);
		pos++;
	}
	return (1);
}

static int	is_space(char c)
{
	return (c == ' ');
}

void	check_all_spaces(char **av, int ac)
{
	int	word;
	int	letter;
	int	space_counter;

	word = 1;
	while (av[word] && word < ac)
	{
		letter = 0;
		space_counter = 0;
		while (av[word][letter])
		{
			if (is_space(av[word][letter]))
				space_counter++;
			letter++;
		}
		if (space_counter == letter)
			error();
		word++;
	}
}
