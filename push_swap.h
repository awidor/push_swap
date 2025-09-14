/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awidor <awidor@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 20:43:42 by awidor            #+#    #+#             */
/*   Updated: 2025/09/14 14:34:40 by awidor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
typedef struct s_state
{
	int	*a;
	int	*b;
	int	a_size;
	int	b_size;
}	t_state;

void	sa(t_state *s);
void	pb(t_state *s);
void	pa(t_state *s);
void	ra(t_state *s);
void	rra(t_state *s);

int		find_min_index(int *arr, int n);
void	selection_sort_with_ops(t_state *s);
void	bubble_sort(int *arr, int n);
void	normalize_array(int *arr, int n);

#endif