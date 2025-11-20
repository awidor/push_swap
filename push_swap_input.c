/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_input.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awidor <awidor@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 05:07:25 by awidor            #+#    #+#             */
/*   Updated: 2025/11/20 23:27:27 by awidor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_valid_number(const char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (ft_isdigit(str[i]) == 0)
		return (0);
	while (ft_isdigit(str[i]))
		i++;
	if (str[i] != '\0')
		return (0);
	return (1);
}

static int	check_duplicates(int *arr, int n)
{
	int	i;
	int	j;

	i = 0;
	while (i < n)
	{
		j = i + 1;
		while (j < n)
		{
			if (arr[i] == arr[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static void	fill_stack(t_state *s, char **argv, int count, char **split_to_free)
{
	int	i;

	s->a = malloc(sizeof(int) * count);
	s->b = malloc(sizeof(int) * count);
	if (s->a == NULL || s->b == NULL)
		error_free(s, split_to_free);
	s->a_size = count;
	s->b_size = 0;
	i = 0;
	while (i < count)
	{
		if (is_valid_number(argv[i]) == 0 || limit_check(argv[i]) != 0)
			error_free(s, split_to_free);
		s->a[i] = ft_atoi(argv[i]);
		i++;
	}
	if (check_duplicates(s->a, count) != 0)
		error_free(s, split_to_free);
}

static void	process_string_arg(char *arg, t_state *s)
{
	char	**split;
	int		count;

	if (arg[0] == '\0')
		error();
	split = ft_split(arg, ' ');
	if (split == NULL)
		error();
	count = 0;
	while (split[count] != NULL)
		count++;
	if (count == 0)
	{
		free_split(split);
		error();
	}
	fill_stack(s, split, count, split);
	free_split(split);
}

void	process_args(int argc, char **argv, t_state *s)
{
	int	count;

	if (argc == 2)
		process_string_arg(argv[1], s);
	else
	{
		count = argc - 1;
		fill_stack(s, argv + 1, count, NULL);
	}
}
