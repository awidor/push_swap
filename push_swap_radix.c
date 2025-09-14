/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_radix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awidor <awidor@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 17:38:36 by awidor            #+#    #+#             */
/*   Updated: 2025/09/14 18:46:52 by awidor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	max_bits_needed(int n)
{
	int	bits;

	bits = 0;
	while ((n - 1) >> bits)
		bits++;
	return (bits);
}

void	radix_sort(t_state *s)
{
	int	n;
	int	max_bits;
	int	i;
	int	bit;

	n = s->a_size;
	max_bits = max_bits_needed(n);
	bit = 0;
	while (bit < max_bits)
	{
		i = 0;
		while (i < n)
		{
			if (((s->a[0] >> bit) & 1) == 0)
				pb(s);
			else
				ra(s);
			i++;
		}
		while (s->b_size)
			pa(s);
		bit++;
	}
}
