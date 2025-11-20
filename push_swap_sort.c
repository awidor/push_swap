/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awidor <awidor@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 12:38:00 by awidor            #+#    #+#             */
/*   Updated: 2025/11/20 23:12:54 by awidor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_max_pos(t_state *s)
{
	int	i;
	int	max;
	int	max_pos;

	i = 0;
	max = INT_MIN;
	max_pos = 0;
	while (i < s->b_size)
	{
		if (s->b[i] > max)
		{
			max = s->b[i];
			max_pos = i;
		}
		i++;
	}
	return (max_pos);
}

static void	push_back_to_a(t_state *s)
{
	int	max_pos;

	while (s->b_size > 0)
	{
		max_pos = find_max_pos(s);
		if (max_pos <= s->b_size / 2)
		{
			while (max_pos > 0)
			{
				rb(s);
				max_pos--;
			}
		}
		else
		{
			while (max_pos < s->b_size)
			{
				rrb(s);
				max_pos++;
			}
		}
		pa(s);
	}
}

void	sort_chunks(t_state *s)
{
	int	chunk_size;
	int	counter;

	if (s->a_size <= 100)
		chunk_size = 20;
	else
		chunk_size = 45;
	counter = 0;
	while (s->a_size > 0)
	{
		if (s->a[0] < counter)
		{
			pb(s);
			rb(s);
			counter++;
		}
		else if (s->a[0] < counter + chunk_size)
		{
			pb(s);
			counter++;
		}
		else
			ra(s);
	}
	push_back_to_a(s);
}
