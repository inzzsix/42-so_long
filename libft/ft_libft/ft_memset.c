/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnakasto <mnakasto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 20:05:26 by mnakasto          #+#    #+#             */
/*   Updated: 2025/03/05 15:08:46 by mnakasto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*p;
	unsigned char	val;

	p = s;
	val = (unsigned char)c;
	while (n --)
	{
		*p = val;
		p++;
	}
	return (s);
}
/*
int	main()
{
	unsigned char str[10] = "Hello";
	printf("Avant: %s\n", str);
	ft_memset(str, 'Q', 4);
	printf("Apres: %s\n", str);
}	
*/	
