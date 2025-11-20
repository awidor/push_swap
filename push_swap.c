/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awidor <awidor@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 17:41:52 by awidor            #+#    #+#             */
/*   Updated: 2025/11/20 23:13:12 by awidor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_stack(t_state *s, int count)
{
	if (is_sorted(s))
		return (0);
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
		sort_chunks(s);
	}
	return (0);
}

void	free_stack(t_state *s)
{
	if (s->a)
		free(s->a);
	if (s->b)
		free(s->b);
}

int	main(int argc, char **argv)
{
	t_state	s;

	if (argc < 2)
		return (0);
	s.a = NULL;
	s.b = NULL;
	process_args(argc, argv, &s);
	if (sort_stack(&s, s.a_size))
	{
		free_stack(&s);
		return (1);
	}
	free_stack(&s);
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
