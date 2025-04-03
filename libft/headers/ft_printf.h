/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnakasto <mnakasto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 15:24:19 by mnakasto          #+#    #+#             */
/*   Updated: 2025/04/03 19:32:42 by mnakasto         ###   ########.fr       */
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

void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_uputnbr_fd(unsigned int n, int fd);
void	ft_puthex_fd(unsigned long long nm, int fd, int uppercase);
void	ft_putptr_fd(void *ptr, int fd);

#endif
