/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnakasto <mnakasto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 20:02:55 by mnakasto          #+#    #+#             */
/*   Updated: 2025/03/05 15:08:09 by mnakasto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char		*p;
	unsigned int		a;

	p = (unsigned char *)s;
	a = (unsigned char)c;
	while (n--)
	{
		if (*p == a)
			return ((void *)p);
		p++;
	}
	return (NULL);
}
