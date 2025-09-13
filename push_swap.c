/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awidor <awidor@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 17:41:52 by awidor            #+#    #+#             */
/*   Updated: 2025/09/13 20:07:09 by awidor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include "push_swap.h"

int error(void)
{
    ft_putstr_fd("Error\n", 2);
    return (0);
}

void	selection_sort_with_ops(t_state *s)
{
	int	min_i;
	int	k;

	while (s->a_size > 0)
	{
		min_i = find_min_index(s->a, s->a_size);
		if (min_i <= s->a_size / 2)
		{
			k = 0;
			while (k++ < min_i)
				ra(s);
		}
		else
		{
			k = 0;
			while (k++ < (s->a_size - min_i))
				rra(s);
		}
		pb(s);
	}
	while (s->b_size > 0)
		pa(s);
}

int main(int argc, char **argv)
{
    int *values;
    if(argc < 2)
        return(error());

    values = malloc((argc) * sizeof(int));
    if(values == NULL)
        return (error());

    int i = 0;
    while(i < argc - 1)
    {
        values[i] = ft_atoi(argv[i + 1]);
        i++;
    }
    values[i] = '\0';

    t_state	s;
    int		count;
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
    selection_sort_with_ops(&s);
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