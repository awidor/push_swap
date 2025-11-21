/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_input.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awidor <awidor@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 05:07:25 by awidor            #+#    #+#             */
/*   Updated: 2025/11/21 23:37:59 by awidor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_split(char **split)
{
	int	count;

	if (split == NULL)
		return (0);
	count = 0;
	while (split[count] != NULL)
		count++;
	return (count);
}

static int	count_numbers(int argc, char **argv)
{
	int		total;
	int		i;
	char	**split;

	if (argv == NULL)
		error();
	total = 0;
	i = 1;
	while (i < argc)
	{
		if (argv[i] == NULL || argv[i][0] == '\0')
			error();
		split = ft_split(argv[i], ' ');
		if (split == NULL)
			error();
		if (split[0] == NULL)
		{
			free_split(split);
			error();
		}
		total += count_split(split);
		free_split(split);
		i++;
	}
	return (total);
}

static void	assign_numbers(t_state *s, char *arg, int *idx)
{
	char	**split;
	int		i;

	if (s == NULL || arg == NULL || idx == NULL)
		error();
	split = ft_split(arg, ' ');
	if (split == NULL)
		error_free(s, NULL);
	if (split[0] == NULL)
		error_free(s, split);
	i = 0;
	while (split[i] != NULL)
	{
		if (is_valid_number(split[i]) == 0 || limit_check(split[i]) != 0)
			error_free(s, split);
		s->a[*idx] = ft_atoi(split[i]);
		*idx += 1;
		i++;
	}
	free_split(split);
}

static void	fill_stack(t_state *s, int argc, char **argv, int count)
{
	int	i;
	int	idx;

	s->a = malloc(sizeof(int) * count);
	s->b = malloc(sizeof(int) * count);
	if (s->a == NULL || s->b == NULL)
	{
		if (s->a != NULL)
			free(s->a);
		if (s->b != NULL)
			free(s->b);
		error();
	}
	s->a_size = count;
	s->b_size = 0;
	i = 1;
	idx = 0;
	while (i < argc)
		assign_numbers(s, argv[i++], &idx);
	if (check_duplicates(s->a, count) != 0)
		error_free(s, NULL);
}

void	process_args(int argc, char **argv, t_state *s)
{
	int	count;

	if (argv == NULL || s == NULL)
		error();
	count = count_numbers(argc, argv);
	fill_stack(s, argc, argv, count);
}
