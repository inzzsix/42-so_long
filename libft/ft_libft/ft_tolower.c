/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnakasto <mnakasto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 17:30:21 by mnakasto          #+#    #+#             */
/*   Updated: 2025/03/05 15:09:56 by mnakasto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

char	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c = c + 32;
	else
		return (c);
	return (c);
}
/*
int	main()
{
	char c = 'g';
	printf("%c\n", ft_tolower(c));
	return (0);
}
*/
