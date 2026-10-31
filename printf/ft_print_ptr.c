/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbsharat <lbsharat@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 11:18:59 by lbsharat          #+#    #+#             */
/*   Updated: 2026/10/31 11:19:30 by lbsharat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	len(unsigned long num)
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

static void	put_ptr_raw(unsigned long num)
{
	char	*base;

	base = "0123456789abcdef";
	if (num >= 16)
		put_ptr_raw(num / 16);
	ft_putchar(base[num % 16]);
}

int	ft_print_ptr(void *ptr)
{
	unsigned long	p;

	if (!ptr)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	p = (unsigned long)ptr;
	write(1, "0x", 2);
	put_ptr_raw(p);
	return (len(p) + 2);
}
