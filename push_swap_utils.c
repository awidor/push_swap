/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awidor <awidor@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 17:27:41 by awidor            #+#    #+#             */
/*   Updated: 2025/11/20 23:13:01 by awidor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	limit_check(const char *nptr)
{
	size_t	i;
	int		sign;
	long	res;
	int		digit;

	i = 0;
	sign = 1;
	res = 0;
	while (nptr[i] == ' ' || (nptr[i] >= '\t' && nptr[i] <= '\r'))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		sign = 1 - 2 * (nptr[i] == '-');
		i++;
	}
	while (ft_isdigit(nptr[i]))
	{
		digit = nptr[i++] - '0';
		if ((sign > 0 && res > (INT_MAX - digit) / 10) || (sign < 0
				&& res > (INT_MIN + digit) / -10))
			return (1);
		res = res * 10 + digit;
	}
	return (0);
}

static void	bubble_sort(int *arr, int n)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < n - 1)
	{
		j = 0;
		while (j < n - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

static void	do_normalize(int *arr, int *sorted, int *normalized, int n)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < n)
	{
		j = 0;
		while (j < n)
		{
			if (arr[i] == sorted[j])
			{
				normalized[i] = j;
				break ;
			}
			j++;
		}
		i++;
	}
}

int	normalize_array(int *arr, int n)
{
	int	*sorted;
	int	*normalized;

	sorted = malloc(sizeof(int) * n);
	if (sorted == NULL)
		return (1);
	normalized = malloc(sizeof(int) * n);
	if (normalized == NULL)
	{
		free(sorted);
		return (1);
	}
	ft_memcpy(sorted, arr, sizeof(int) * n);
	bubble_sort(sorted, n);
	do_normalize(arr, sorted, normalized, n);
	ft_memcpy(arr, normalized, sizeof(int) * n);
	free(sorted);
	free(normalized);
	return (0);
}

int	is_sorted(t_state *s)
{
	int	i;

	i = 0;
	while (i < s->a_size - 1)
	{
		if (s->a[i] > s->a[i + 1])
			return (0);
		i++;
	}
	return (1);
}
