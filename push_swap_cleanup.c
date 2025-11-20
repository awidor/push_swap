/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_cleanup.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awidor <awidor@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 13:30:00 by awidor            #+#    #+#             */
/*   Updated: 2025/11/20 23:27:53 by awidor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_split(char **split)
{
	int	i;

	i = 0;
	if (split == NULL)
		return ;
	while (split[i] != NULL)
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
	if (split != NULL)
		free_split(split);
	if (s->a != NULL)
		free(s->a);
	if (s->b != NULL)
		free(s->b);
	error();
}
