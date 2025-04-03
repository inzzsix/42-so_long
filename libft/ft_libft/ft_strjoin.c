/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnakasto <mnakasto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 13:50:27 by mnakasto          #+#    #+#             */
/*   Updated: 2025/03/05 15:09:15 by mnakasto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*final;
	size_t	len1;
	size_t	len2;

	if (!s1)
		len1 = 0;
	else
		len1 = ft_strlen(s1);
	if (!s2)
		len2 = 0;
	else
		len2 = ft_strlen(s2);
	final = malloc(len1 + len2 + 1);
	if (final == NULL)
		return (NULL);
	if (s1)
		ft_strlcpy(final, s1, len1 + 1);
	if (s2)
		ft_strlcat(final + len1, s2, len2 + 1);
	return (final);
}

// int main(void)
// {
// 	char *s1 = NULL;
// 	char s2[] = "un join simple";
// 	char *res = ft_strjoin(s1, s2);
// 	printf("%s", res);
// 	free (res);
// 	return 0;
// }
