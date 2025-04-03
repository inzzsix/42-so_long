/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnakasto <mnakasto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 10:02:36 by mnakasto          #+#    #+#             */
/*   Updated: 2025/03/05 14:57:38 by mnakasto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

int	ft_puthex_fd(unsigned long long n, int fd, int uppercase)
{
	char	*base;
	int		count;

	count = 0;
	if (uppercase)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (n >= 16)
		count += ft_puthex_fd(n / 16, fd, uppercase);
	count += ft_putchar_fd(base[n % 16], fd);
	return (count);
}

int	ft_uputnbr_fd(unsigned int n, int fd)
{
	int	count;

	count = 0;
	if (n > 9)
	{
		count += ft_uputnbr_fd(n / 10, fd);
	}
	count += ft_putchar_fd((n % 10 + '0'), fd);
	return (count);
}
