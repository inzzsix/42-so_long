/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnakasto <mnakasto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 11:43:31 by mnakasto          #+#    #+#             */
/*   Updated: 2024/12/14 14:33:44 by mnakasto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	little_len;
	size_t	j;

	if (*little == '\0')
		return ((char *)big);
	i = 0;
	little_len = 0;
	while (little[little_len] != '\0')
		little_len++;
	if (little_len > len)
		return (NULL);
	while (big[i] != '\0' && i + little_len <= len)
	{
		j = 0;
		while (big[i + j] == little[j])
		{
			j++;
			if (j == little_len)
				return ((char *)(big + i));
		}
		i++;
	}
	return (NULL);
}
/*
int main()
{
    char big[] = "hello, world!";
    char little[] = "world";
    printf("%s\n", ft_strnstr(big, little, 12));
    return (0);
}
*/
