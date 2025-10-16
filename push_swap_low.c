/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_low.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awidor <awidor@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 04:19:24 by awidor            #+#    #+#             */
/*   Updated: 2025/10/16 08:16:13 by awidor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2(t_state *s)
{
	if (s->a[0] > s->a[1])
		sa(s);
}

void	sort_3(t_state *s)
{
	if (s->a[0] > s->a[1] && s->a[0] > s->a[2])
	{
		ra(s);
		if (s->a[0] > s->a[1])
			sa(s);
	}
	else if (s->a[1] > s->a[0] && s->a[1] > s->a[2])
	{
		rra(s);
		if (s->a[0] > s->a[1])
			sa(s);
	}
	else
	{
		if (s->a[0] > s->a[1])
			sa(s);
	}
}

void	sort_4_5(t_state *s)
{
	int	min_index;

	while (s->a_size > 3)
	{
		min_index = 0;
		for (int i = 1; i < s->a_size; i++)
			if (s->a[i] < s->a[min_index])
				min_index = i;
		while (min_index > 0)
		{
			ra(s);
			min_index--;
		}
		pb(s);
	}
	sort_3(s);
	while (s->b_size > 0)
		pa(s);
}
