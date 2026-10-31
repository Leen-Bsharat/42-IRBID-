/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbsharat <lbsharat@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 11:42:29 by lbsharat          #+#    #+#             */
/*   Updated: 2026/10/31 11:47:16 by lbsharat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);
int		ft_putchar(int c);
int		ft_print_string(char *str);
int		ft_print_digit(int num);
int		ft_print_unsigned_int(unsigned int num);
int		ft_print_hex(unsigned int num, char hex);
int		ft_print_ptr(void *ptr);
int		ft_strlen(const char *str);
void	ft_putnbr_fd(int n, int fd);

#endif
