/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_to_num.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heltayb <heltayb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 18:13:56 by heltayb           #+#    #+#             */
/*   Updated: 2024/02/25 21:35:14 by heltayb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//convert the arguments to one array of numbers
t_arr			*convert_to_number(char **av, int ac);
static char		***splits(char **av, int ac);
static int		size_of_the_arr(char ***split_of_splits);
static long		*creat_arr(char ***split_of_splits, int size);
static long		ft_atoi(char *str);

t_arr	*convert_to_number(char **av, int ac)
{
	char	***split_of_splits;
	t_arr	*arr;

	check_all_spaces(av, ac);
	split_of_splits = splits(av, ac);
	arr = malloc(sizeof(t_arr));
	if (!arr)
		error();
	arr->size = size_of_the_arr(split_of_splits);
	arr->value = creat_arr(split_of_splits, arr->size);
	if (!arr->value)
	{
		free_split_of_splits(split_of_splits, ac - 1);
		free(arr);
		error();
	}
	free_split_of_splits(split_of_splits, ac - 1);
	return (arr);
}

static char	***splits(char **av, int ac)
{
	char	***split_of_splits;
	int		i;
	int		k;

	split_of_splits = malloc(sizeof(char **) * (ac));
	if (!split_of_splits)
		error();
	k = 0;
	i = 1;
	while (av[i])
	{
		split_of_splits[k] = ft_split(av[i]);
		if (!split_of_splits[k] || av[i][0] == '\0')
		{
			free_split_of_splits(split_of_splits, k);
			error();
		}
		i++;
		k++;
	}
	split_of_splits[k] = NULL;
	return (split_of_splits);
}

static int	size_of_the_arr(char ***split_of_splits)
{
	int	numbers;
	int	j;
	int	i;

	i = 0;
	numbers = 0;
	while (split_of_splits[i])
	{
		j = 0;
		while (split_of_splits[i][j])
			j++;
		numbers = numbers + j;
		i++;
	}
	return (numbers);
}

static long	*creat_arr(char ***split_of_splits, int size)
{
	int		numbers;
	int		i;
	int		j;
	long	*value;

	i = 0;
	numbers = 0;
	value = malloc((size) * (sizeof(long)));
	while (split_of_splits[i])
	{
		j = 0;
		while (split_of_splits[i][j])
		{
			value[numbers] = ft_atoi(split_of_splits[i][j]);
			if (value[numbers] == 12345678912345)
				return (free(value), NULL);
			numbers++;
			j++;
		}
		i++;
	}
	return (value);
}

static long	ft_atoi(char *str)
{
	int		i;
	int		digit;
	long	result;
	long	sign;

	i = 0;
	sign = 1;
	result = 0;
	digit = 0;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			sign = -1;
	if (!(str[i]))
		return (12345678912345);
	while (str[i] && str[i] == '0')
		i++;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9') || digit > 10)
			return (12345678912345);
		result = (result * 10) + (str[i] - '0');
		i++;
		digit++;
	}
	return (result * sign);
}
