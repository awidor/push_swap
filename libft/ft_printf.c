/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awidor <awidor@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 11:32:49 by awidor            #+#    #+#             */
/*   Updated: 2025/07/23 14:09:50 by awidor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	counted_ft_putchar_fd(char c, int fd)
{
	if (write(fd, &c, 1) == -1)
		return (-1);
	return (1);
}

int	handle_conversions(char convc, va_list args)
{
	int	char_count;

	char_count = 0;
	if (convc == 'c')
		char_count = counted_ft_putchar_fd(va_arg(args, int), 1);
	else if (convc == 's')
		char_count = counted_ft_putstr_fd(va_arg(args, char *), 1);
	else if (convc == 'p')
		char_count = print_pointer(va_arg(args, void *));
	else if (convc == 'd')
		char_count = counted_ft_putnbr_fd(va_arg(args, int), 1);
	else if (convc == 'i')
		char_count = counted_ft_putnbr_fd(va_arg(args, int), 1);
	else if (convc == 'u')
		char_count = print_unsigned_int(va_arg(args, unsigned int), 1);
	else if (convc == 'x')
		char_count = handle_hex((unsigned int)va_arg(args, int), 0);
	else if (convc == 'X')
		char_count = handle_hex((unsigned int)va_arg(args, int), 1);
	else if (convc == '%')
		char_count = counted_ft_putchar_fd('%', 1);
	return (char_count);
}

int	ft_printf(const char *input, ...)
{
	va_list	args;
	int		count;
	int		res;
	int		i;

	va_start(args, input);
	count = 0;
	i = 0;
	while (input[i])
	{
		if (input[i] == '%' && input[i + 1])
			res = handle_conversions(input[++i], args);
		else
			res = write(1, &input[i], 1);
		if (res == -1)
		{
			count = -1;
			break ;
		}
		count += res;
		i++;
	}
	va_end(args);
	return (count);
}
