/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnakasto <mnakasto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 18:43:42 by mnakasto          #+#    #+#             */
/*   Updated: 2025/03/05 15:07:50 by mnakasto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}
/*
int	main()
{
	unsigned char c = 'é';
	if (ft_isascii(c))
		printf("'%c' est un caractère ASCII.\n", c);
	else
		printf("'%c' n'est pas un caractère ASCII.\n", c);
	return (0);
}
*/
