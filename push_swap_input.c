/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_input.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awidor <awidor@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 05:07:25 by awidor            #+#    #+#             */
/*   Updated: 2025/11/06 05:16:06 by awidor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

int	is_valid_number(const char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!ft_isdigit(str[i]))
		return (0);
	while (ft_isdigit(str[i]))
		i++;
	if (str[i] != '\0')
		return (0);
	return (1);
}

int	input_validation(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc < 2)
		return (1);
	while (i < argc - 1)
	{
		if (!is_valid_number(argv[i + 1]) || limit_check(argv[i + 1]))
			error();
		i++;
	}
	return (0);
}

int	detect_duplicates(int *arr, int n)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < n)
	{
		j = i + 1;
		while (j < n)
		{
			if (arr[i] == arr[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	parse(int argc, char **argv, int **values)
{
	int	i;

	i = 0;
	*values = malloc(sizeof(int) * (argc - 1));
	if (*values == NULL)
		error();
	while (i < argc - 1)
	{
		(*values)[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	return (0);
}
