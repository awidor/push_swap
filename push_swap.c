/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awidor <awidor@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 17:41:52 by awidor            #+#    #+#             */
/*   Updated: 2025/09/14 18:44:26 by awidor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>

int	DEBUG = 1;
#define YEL "\x1B[33m"
#define RESET "\x1B[0m"

int	error(void)
{
	ft_putstr_fd("Error\n", 2);
	return (1);
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

int	main(int argc, char **argv)
{
	int		i;
	int		*values;
	t_state	s;
	int		count;

	i = 0;
	if (argc < 2)
		return (error());
	if (DEBUG)
	{
		ft_printf(YEL "Warning: DEBUG mode is enabled!\n" RESET);
		ft_printf("DEBUG: argc: %d\n", argc);
	}
	while (i < argc - 1)
	{
		if (limit_check(argv[i + 1]))
		{
			if (DEBUG)
			{
				ft_printf("DEBUG: Limit check failed\n");
				return (error());
			}
		}
		i++;
	}
	values = malloc((argc) * sizeof(int));
	if (values == NULL)
		return (error());
	while (i < argc - 1)
	{
		values[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	values[i] = '\0';
	i = 0;
	count = argc - 1;
	s.a = malloc(sizeof(int) * count);
	s.b = malloc(sizeof(int) * count);
	if (!s.a || !s.b)
		return (error());
	s.a_size = count;
	s.b_size = 0;
	i = 0;
	while (i < count)
	{
		s.a[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	if (detect_duplicates(s.a, count))
	{
		if (DEBUG)
			ft_printf("DEBUG: Duplicates detected\n");
		return (error());
	}
	normalize_array(s.a, count);
	i = 0;
	while (i < count)
	{
		if (DEBUG)
		{
			ft_printf("DEBUG: s.a[%d] = %d\n", i, s.a[i]);
			i++;
		}
	}
	radix_sort(&s);
	free(s.a);
	free(s.b);
	free(values);
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