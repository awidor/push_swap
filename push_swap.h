/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awidor <awidor@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 20:43:42 by awidor            #+#    #+#             */
/*   Updated: 2025/09/14 18:48:56 by awidor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
# include <limits.h>
typedef struct s_state
{
	int	*a;
	int	*b;
	int	a_size;
	int	b_size;
}		t_state;

void	pb(t_state *s);
void	pa(t_state *s);
void	ra(t_state *s);
void	rra(t_state *s);

void	bubble_sort(int *arr, int n);
void	normalize_array(int *arr, int n);
void	radix_sort(t_state *s);
int		limit_check(const char *nptr);

#endif