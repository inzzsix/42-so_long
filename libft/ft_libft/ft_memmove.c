/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnakasto <mnakasto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:51:40 by mnakasto          #+#    #+#             */
/*   Updated: 2025/03/05 15:08:39 by mnakasto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*dst;
	const unsigned char	*from;

	if (!dest && !src)
		return (NULL);
	dst = dest;
	from = src;
	if (dst < from)
	{
		while (n--)
			*dst++ = *from++;
	}
	else
	{
		while (n--)
			dst[n] = from[n];
	}
	return (dest);
}
/*
int main(void)
// {
// 	char dest[] = "iheb";
// 	char src[] = "crack";

// 	printf ("%s", (char *)ft_memmove(dest, src, 10));
// 	return 0;
// }
*/