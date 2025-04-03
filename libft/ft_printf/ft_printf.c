/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnakasto <mnakasto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 15:16:45 by mnakasto          #+#    #+#             */
/*   Updated: 2025/03/05 15:15:29 by mnakasto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

static int	handle_format(va_list args, const char *format, int *i)
{
	int	count;

	count = 0;
	if (format[*i] == 'd' || format[*i] == 'i')
		count += ft_putnbr_fd(va_arg(args, int), 1);
	else if (format[*i] == 's')
		count += ft_putstr_fd(va_arg(args, char *), 1);
	else if (format[*i] == 'c')
		count += ft_putchar_fd((char)va_arg(args, int), 1);
	else if (format[*i] == 'u')
		count += ft_uputnbr_fd(va_arg(args, unsigned int), 1);
	else if (format[*i] == 'x' || format[*i] == 'X')
		count += ft_puthex_fd(va_arg(args, unsigned int), 1, format[*i] == 'X');
	else if (format[*i] == 'p')
		count += ft_putptr_fd(va_arg(args, void *), 1);
	else if (format[*i] == '%')
		count += ft_putchar_fd('%', 1);
	return (count);
}

static int	print_format(va_list args, const char *format)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			count += handle_format(args, format, &i);
		}
		else
			count += ft_putchar_fd(format[i], 1);
		i++;
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list		args;
	int			count;

	if (format == NULL)
		return (-1);
	va_start(args, format);
	count = print_format(args, format);
	va_end(args);
	return (count);
}
/*
int	main()
{
	ft_printf("La lettre %c est correcte\n", 'a');
	printf("La lettre %c est correcte", 'a');
	return (0);
}
*/
