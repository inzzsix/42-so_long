/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnakasto <mnakasto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 13:49:34 by mnakasto          #+#    #+#             */
/*   Updated: 2025/03/05 15:09:53 by mnakasto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*z;
	size_t	s_len;
	size_t	i;
	size_t	j;

	if (!s)
		return (0);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	if (start + len > s_len)
		len = s_len - start;
	z = malloc(sizeof(char) * (len + 1));
	i = start;
	j = 0;
	while (j < len && i < ft_strlen(s))
	{
		z[j] = s[i];
		j++;
		i++;
	}
	z[j] = '\0';
	return (z);
}

// int main(void)
// {
//     char s[] = "ashdphrasesjsj";
//     char *sub = ft_substr(s, 4, 6);
//     if(sub != NULL)
//     {
//         printf("%s", sub);
//     }
//     free(sub);
//     return 0;
// }