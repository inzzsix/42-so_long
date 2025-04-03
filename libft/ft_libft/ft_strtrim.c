/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnakasto <mnakasto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 14:00:20 by mnakasto          #+#    #+#             */
/*   Updated: 2025/03/05 15:09:51 by mnakasto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*res;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	start = 0;
	end = ft_strlen(s1) - 1;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	if (s1[start])
	{
		while (s1[end] && ft_strchr(set, s1[end]))
			end--;
	}
	res = ft_substr(s1, start, end - start + 1);
	return (res);
}

// int main(void)
// {
// 	char *s1 = " aaaaaihebaaaa   ";
// 	char *set = " ";
// 	char *res = ft_strtrim(s1, set);
// 	printf("%s", res);
// 	free(res);
// }