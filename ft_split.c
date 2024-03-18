/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heltayb <heltayb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 18:18:28 by heltayb           #+#    #+#             */
/*   Updated: 2024/02/25 16:47:22 by heltayb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//all split helping functions
char		**ft_split(char *str);
static void	free_split(char **ptr, int i);
static int	is_space(char c);
static int	word_count(char *str);
static char	*word_malloc(char *str, int first, int last);

char	**ft_split(char *str)
{
	char		**split;
	t_split		i;

	i.words = word_count(str);
	split = malloc((i.words + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	i.words = 0;
	i.index = 0;
	while (str[i.index])
	{
		if (str[i.index] && !is_space(str[i.index]))
		{
			i.first = i.index;
			while (str[i.index] && !is_space(str[i.index]))
				i.index++;
			split[i.words] = word_malloc(str, i.first, i.index);
			if (!split[i.words++])
				return (free_split(split, i.index - 2), NULL);
		}
		else
			i.index++;
	}
	return (split[i.words] = NULL, split);
}

static int	is_space(char c)
{
	return (c == ' ');
}

static int	word_count(char *str)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (str[i])
	{
		if (str[i] && !is_space(str[i]))
		{
			words++;
			while (str[i] && !is_space(str[i]))
				i++;
		}
		else
			i++;
	}
	return (words);
}

static char	*word_malloc(char *str, int first, int last)
{
	char	*word;
	int		len;
	int		i;

	len = last - first;
	i = 0;
	word = malloc(len + 1);
	if (!word)
		return (NULL);
	while (str[first] && first < last)
	{
		word[i] = str[first];
		i++;
		first++;
	}
	word[i] = '\0';
	return (word);
}

static void	free_split(char **ptr, int i)
{
	while (i >= 0)
	{
		free(ptr[i]);
		ptr[i] = NULL;
		i--;
	}
	free(ptr);
	ptr = NULL;
}
