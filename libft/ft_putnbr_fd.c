/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awidor <awidor@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 20:24:57 by awidor            #+#    #+#             */
/*   Updated: 2025/03/24 13:18:35 by awidor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	size_t	i;
	long	nbr;
	char	result[12];

	i = 0;
	nbr = n;
	if (nbr == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	if (nbr < 0)
	{
		write(fd, "-", 1);
		nbr = nbr * -1;
	}
	while (nbr > 0)
	{
		result[i] = nbr % 10 + '0';
		nbr = nbr / 10;
		i++;
	}
	while (i > 0)
		write(fd, &result[--i], 1);
}

// int	main(void)
// {
// 	int num = -32;
// 	ft_putnbr_fd(num, 1);
// }