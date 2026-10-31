/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_digit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbsharat <lbsharat@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 11:37:18 by lbsharat          #+#    #+#             */
/*   Updated: 2026/10/31 11:38:56 by lbsharat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	len(long num)
{
	int	i;

	i = 0;
	if (num == 0)
		return (1);
	if (num < 0)
	{
		i++;
		num = -num;
	}
	while (num != 0)
	{
		i++;
		num /= 10;
	}
	return (i);
}

int	ft_print_digit(int num)
{
	ft_putnbr_fd(num, 1);
	return (len(num));
}
