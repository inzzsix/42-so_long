/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnakasto <mnakasto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 16:07:49 by mnakasto          #+#    #+#             */
/*   Updated: 2025/03/05 14:57:13 by mnakasto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

int	ft_putchar_fd(char c, int fd)
{
	return (write (fd, &c, 1));
}

int	ft_putstr_fd(char *s, int fd)
{
	int	count;

	count = 0;
	if (!s)
		s = "(null)";
	while (*s)
	{
		write (fd, s++, 1);
		count++;
	}
	return (count);
}

int	ft_putnbr_fd(int n, int fd)
{
	int	count;

	count = 0;
	if (n == -2147483648)
	{
		count = ft_putstr_fd("-2147483648", fd);
		return (count);
	}
	else
	{
		if (n < 0)
		{
			count += ft_putchar_fd('-', fd);
			n = -n;
		}
		if (n > 9)
		{
			count += ft_putnbr_fd(n / 10, fd);
		}
		count += ft_putchar_fd((n % 10 + '0'), fd);
	}
	return (count);
}

int	ft_putptr_fd(void *ptr, int fd)
{
	unsigned long long	addr;
	int					count;

	addr = (unsigned long long)ptr;
	count = 0;
	if (!ptr)
	{
		count += ft_putstr_fd("(nil)", fd);
		return (count);
	}
	count += ft_putstr_fd("0x", fd);
	count += ft_puthex_fd(addr, fd, 0);
	return (count);
}
