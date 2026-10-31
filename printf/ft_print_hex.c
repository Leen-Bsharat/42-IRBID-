/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbsharat <lbsharat@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 11:10:11 by lbsharat          #+#    #+#             */
/*   Updated: 2026/10/31 11:10:24 by lbsharat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	hex_len(unsigned int num)
{
	int	i;

	i = 0;
	if (num == 0)
		return (1);
	while (num > 0)
	{
		num /= 16;
		i++;
	}
	return (i);
}

static void	put_hex_raw(unsigned int num, char hex)
{
	char	*base;

	if (hex == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (num >= 16)
		put_hex_raw(num / 16, hex);
	ft_putchar(base[num % 16]);
}

int	ft_print_hex(unsigned int num, char hex)
{
	put_hex_raw(num, hex);
	return (hex_len(num));
}
