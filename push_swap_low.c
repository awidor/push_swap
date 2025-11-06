/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_low.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awidor <awidor@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 04:19:24 by awidor            #+#    #+#             */
/*   Updated: 2025/11/06 05:42:33 by awidor           ###   ########.fr       */
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

static void	rotate_min_to_top(t_state *s, int min_index)
{
	if (min_index <= s->a_size / 2)
	{
		while (min_index-- > 0)
			ra(s);
	}
	else
	{
		while (min_index++ < s->a_size)
			rra(s);
	}
}

static int	find_min_index(t_state *s)
{
	int	min_index;
	int	i;

	min_index = 0;
	i = 1;
	while (i < s->a_size)
	{
		if (s->a[i] < s->a[min_index])
			min_index = i;
		i++;
	}
	return (min_index);
}

void	sort_4_5(t_state *s)
{
	int	min_index;

	while (s->a_size > 3)
	{
		min_index = find_min_index(s);
		rotate_min_to_top(s, min_index);
		pb(s);
	}
	sort_3(s);
	while (s->b_size > 0)
		pa(s);
}
