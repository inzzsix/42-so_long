/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnakasto <mnakasto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 15:24:19 by mnakasto          #+#    #+#             */
/*   Updated: 2025/04/06 22:30:28 by mnakasto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>

	// ft_printf

int	ft_printf(const char *format, ...);

	// utils

int	ft_putchar_fd(char c, int fd);
int	ft_putstr_fd(char *s, int fd);
int	ft_putnbr_fd(int n, int fd);
int	ft_uputnbr_fd(unsigned int n, int fd);
int	ft_puthex_fd(unsigned long long nm, int fd, int uppercase);
int	ft_putptr_fd(void *ptr, int fd);

#endif
