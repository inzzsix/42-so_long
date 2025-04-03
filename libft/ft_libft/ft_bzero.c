/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnakasto <mnakasto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 10:26:02 by mnakasto          #+#    #+#             */
/*   Updated: 2025/03/05 14:59:44 by mnakasto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*i;

	i = s;
	while (n--)
		*i++ = 0;
}
/*
int	main()
{
	unsigned char str[6] = "hello";
	printf("Avant: ");
	ft_bzero(str, 2);
	for (int i = 0; i < 5; i++)
	{
		if(str[i] == '\0')
			printf("\\0");
		else
			printf("%c", str[i]);
	}
	printf("\n");
}
*/
