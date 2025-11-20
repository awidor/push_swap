/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_ops_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awidor <awidor@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 13:55:00 by awidor            #+#    #+#             */
/*   Updated: 2025/11/20 23:12:40 by awidor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rb(t_state *s)
{
	int	i;
	int	first;

	if (s->b_size < 2)
		return ;
	first = s->b[0];
	i = 0;
	while (i < s->b_size - 1)
	{
		s->b[i] = s->b[i + 1];
		i++;
	}
	s->b[s->b_size - 1] = first;
	ft_putstr_fd("rb\n", 1);
}

void	rrb(t_state *s)
{
	int	i;
	int	last;

	if (s->b_size < 2)
		return ;
	last = s->b[s->b_size - 1];
	i = s->b_size - 1;
	while (i > 0)
	{
		s->b[i] = s->b[i - 1];
		i--;
	}
	s->b[0] = last;
	ft_putstr_fd("rrb\n", 1);
}
