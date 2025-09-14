/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awidor <awidor@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 17:27:41 by awidor            #+#    #+#             */
/*   Updated: 2025/09/14 16:26:11 by awidor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min_index(int *arr, int n)
{
	int	i;
	int	min_i;

	min_i = 0;
	i = 1;
	while (i < n)
	{
		if (arr[i] < arr[min_i])
			min_i = i;
		i++;
	}
	return (min_i);
}
void bubble_sort(int *arr, int n)
{
    int i;
    int j;
    int tmp;
    
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

void do_normalize(int *arr, int *sorted, int *normalized, int n)
{
	int i;
	int j;
	i = 0;
	j = 0;

	while(i < n)
	{
		j = 0;
		while (j < n)
		{
			if(arr[i] == sorted[j])
			{
				normalized[i] = j;
				break;
			}
			j++;
		}
		i++;
	}
	
}

void normalize_array(int *arr, int n)
{
	int i;
	int *sorted;
	int *normalized;
	sorted = malloc(sizeof(int) * n);
	normalized = malloc(sizeof(int) * n);
	if (sorted == NULL || normalized == NULL)
		return;

	i = 0;
	while (i < n)
	{
		sorted[i] = arr[i];
		i++;
	}
	bubble_sort(sorted, n);
	do_normalize(arr, sorted, normalized, n);
	i = 0;
	while (i < n)
	{
		arr[i] = normalized[i];
		i++;
	}
	free(sorted);
	free(normalized);
}

