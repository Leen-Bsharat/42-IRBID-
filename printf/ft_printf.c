/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbsharat <lbsharat@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 11:19:40 by lbsharat          #+#    #+#             */
/*   Updated: 2026/10/31 11:20:50 by lbsharat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_formats(va_list args, const char format)
{
	int	print_len;

	print_len = 0;
	if (format == 'c')
		print_len += ft_putchar(va_arg(args, int));
	else if (format == 's')
		print_len += ft_print_string(va_arg(args, char *));
	else if (format == 'p')
		print_len += ft_print_ptr(va_arg(args, void *));
	else if (format == 'd' || format == 'i')
		print_len += ft_print_digit(va_arg(args, int));
	else if (format == 'u')
		print_len += ft_print_unsigned_int(va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		print_len += ft_print_hex(va_arg(args, unsigned int), format);
	else if (format == '%')
		print_len += ft_putchar('%');
	return (print_len);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		total_len;

	i = 0;
	total_len = 0;
	if (!format)
		return (-1);
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			total_len += ft_formats(args, format[i + 1]);
			i++;
		}
		else
			total_len += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (total_len);
}
