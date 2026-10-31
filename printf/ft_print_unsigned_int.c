/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned_int.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbsharat <lbsharat@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 11:10:34 by lbsharat          #+#    #+#             */
/*   Updated: 2026/10/31 11:10:57 by lbsharat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	len(unsigned int num)
{
	int	i;

	i = 0;
	if (num == 0)
		return (1);
	while (num > 0)
	{
		num /= 10;
		i++;
	}
	return (i);
}

static void	put_unsigned_raw(unsigned int num)
{
	if (num >= 10)
		put_unsigned_raw(num / 10);
	ft_putchar((num % 10) + '0');
}

int	ft_print_unsigned_int(unsigned int num)
{
	put_unsigned_raw(num);
	return (len(num));
}
