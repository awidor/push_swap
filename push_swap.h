/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awidor <awidor@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 20:43:42 by awidor            #+#    #+#             */
/*   Updated: 2025/11/06 05:16:10 by awidor           ###   ########.fr       */
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
void	sa(t_state *s);

void	bubble_sort(int *arr, int n);
void	normalize_array(int *arr, int n);
void	radix_sort(t_state *s);
int		limit_check(const char *nptr);
int		is_sorted(t_state *s);

void	sort_2(t_state *s);
void	sort_3(t_state *s);
void	sort_4_5(t_state *s);

void	error(void);
int		is_valid_number(const char *str);
int		input_validation(int argc, char **argv);
int		detect_duplicates(int *arr, int n);
int		parse(int argc, char **argv, int **values);

#endif