/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbsharat <lbsharat@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 12:23:12 by lbsharat          #+#    #+#             */
/*   Updated: 2026/10/12 12:40:18 by lbsharat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static void	ft_putchar(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	long int	num;

	num = n;
	if (num < 0)
	{
		ft_putchar('-', fd);
		num *= -1;
	}
	if (num >= 0 && num <= 9)
		ft_putchar(num + '0', fd);
	if (num > 9)
	{
		ft_putnbr_fd(num / 10, fd);
		ft_putchar((num % 10) + '0', fd);
	}
}
