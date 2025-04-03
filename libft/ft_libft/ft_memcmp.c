/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnakasto <mnakasto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 20:23:26 by mnakasto          #+#    #+#             */
/*   Updated: 2025/03/05 15:08:34 by mnakasto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*src1;
	unsigned char	*src2;
	size_t			i;

	i = 0;
	src1 = (void *)s1;
	src2 = (void *)s2;
	while (i < n)
	{
		if (src1[i] != src2[i])
			return (src1[i] - src2[i]);
		i++;
	}
	return (0);
}
/*
int    main()
{
    char t1[] = "awc";
    char t2[] = "fbc";
    
    printf ("%d\n", ft_memcmp(t1, t2, 3));
    printf ("%d\n", memcmp(t1, t2, 3));
    return (0);
}
*/