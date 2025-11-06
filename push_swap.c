/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awidor <awidor@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 17:41:52 by awidor            #+#    #+#             */
/*   Updated: 2025/11/06 05:00:49 by awidor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

int	detect_duplicates(int *arr, int n)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
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

static int	is_valid_number(const char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!ft_isdigit(str[i]))
		return (0);
	while (ft_isdigit(str[i]))
		i++;
	if (str[i] != '\0')
		return (0);
	return (1);
}

int	input_validation(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc < 2)
		return (1);
	while (i < argc - 1)
	{
		if (!is_valid_number(argv[i + 1]) || limit_check(argv[i + 1]))
			error();
		i++;
	}
	return (0);
}

int	parse(int argc, char **argv, int **values)
{
	int	i;

	i = 0;
	*values = malloc(sizeof(int) * (argc - 1));
	if (*values == NULL)
		error();
	while (i < argc - 1)
	{
		(*values)[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	return (0);
}

int	init(t_state *s, int argc, char **argv, int *count)
{
	int	i;

	i = 0;
	*count = argc - 1;
	s->a = malloc(sizeof(int) * *count);
	s->b = malloc(sizeof(int) * *count);
	if (!s->a || !s->b)
		error();
	s->a_size = *count;
	s->b_size = 0;
	i = 0;
	while (i < *count)
	{
		s->a[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	return (0);
}

int	sort_stack(t_state *s, int count)
{
	if (count <= 5)
	{
		if (count == 1)
			return (0);
		else if (count == 2)
			sort_2(s);
		else if (count == 3)
			sort_3(s);
		else
			sort_4_5(s);
	}
	else
	{
		normalize_array(s->a, count);
		radix_sort(s);
	}
	return (0);
}

void	free_stack(t_state *s, int *values)
{
	free(s->a);
	free(s->b);
	free(values);
}

int	main(int argc, char **argv)
{
	t_state	s;
	int		*values;
	int		count;

	if (input_validation(argc, argv))
		return (1);
	if (parse(argc, argv, &values))
		return (1);
	if (init(&s, argc, argv, &count))
	{
		free(values);
		return (1);
	}
	if (detect_duplicates(s.a, count))
	{
		free_stack(&s, values);
		error();
	}
	if (sort_stack(&s, count))
	{
		free_stack(&s, values);
		return (1);
	}
	free_stack(&s, values);
	return (0);
}

/*
sa (swap a): Swap the first 2 elements at the top of stacka.
Do nothing if there is only one element or none.
sb (swap b): Swap the first 2 elements at the top of stackb.
Do nothing if there is only one element or none.
ss :saandsbat the same time.
pa (push a): Take the first element at the top ofband put it at the top ofa.
Do nothing ifbis empty.
pb (push b): Take the first element at the top ofaand put it at the top ofb.
Do nothing ifais empty.
ra (rotate a): Shift up all elements of stackaby 1.
The first element becomes the last one.
rb (rotate b): Shift up all elements of stackbby 1.
The first element becomes the last one.
rr : raandrbat the same time.
rra (reverse rotate a): Shift down all elements of stackaby 1.
The last element becomes the first one.
rrb (reverse rotate b): Shift down all elements of stackbby 1.
The last element becomes the first one.
rrr :rraandrrbat the same time.
*/
