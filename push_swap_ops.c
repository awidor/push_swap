/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_ops.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awidor <awidor@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 17:26:36 by awidor            #+#    #+#             */
/*   Updated: 2025/10/16 04:43:22 by awidor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_state *s)
{
	int	i;

	if (s->a_size == 0)
		return ;
	i = s->b_size;
	while (i > 0)
	{
		s->b[i] = s->b[i - 1];
		i--;
	}
	s->b[0] = s->a[0];
	i = 0;
	while (i < s->a_size - 1)
	{
		s->a[i] = s->a[i + 1];
		i++;
	}
	s->b_size++;
	s->a_size--;
	ft_putstr_fd("pb\n", 1);
}

void	pa(t_state *s)
{
	int	i;

	if (s->b_size == 0)
		return ;
	i = s->a_size;
	while (i > 0)
	{
		s->a[i] = s->a[i - 1];
		i--;
	}
	s->a[0] = s->b[0];
	i = 0;
	while (i < s->b_size - 1)
	{
		s->b[i] = s->b[i + 1];
		i++;
	}
	s->a_size++;
	s->b_size--;
	ft_putstr_fd("pa\n", 1);
}

void	ra(t_state *s)
{
	int	i;
	int	first;

	if (s->a_size < 2)
		return ;
	first = s->a[0];
	i = 0;
	while (i < s->a_size - 1)
	{
		s->a[i] = s->a[i + 1];
		i++;
	}
	s->a[s->a_size - 1] = first;
	ft_putstr_fd("ra\n", 1);
}

void	rra(t_state *s)
{
	int	i;
	int	last;

	if (s->a_size < 2)
		return ;
	last = s->a[s->a_size - 1];
	i = s->a_size - 1;
	while (i > 0)
	{
		s->a[i] = s->a[i - 1];
		i--;
	}
	s->a[0] = last;
	ft_putstr_fd("rra\n", 1);
}

void	sa(t_state *s)
{
	int tmp;

	if (s->a_size < 2)
		return ;
	tmp = s->a[0];
	s->a[0] = s->a[1];
	s->a[1] = tmp;
	ft_putstr_fd("sa\n", 1);
}