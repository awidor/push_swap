/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_cleanup.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awidor <awidor@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 13:30:00 by awidor            #+#    #+#             */
/*   Updated: 2025/11/20 13:15:07 by awidor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_split(char **split)
{
	int	i;

	i = 0;
	if (!split)
		return ;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

void	error_free(t_state *s, char **split)
{
	if (split)
		free_split(split);
	if (s->a)
		free(s->a);
	if (s->b)
		free(s->b);
	error();
}
