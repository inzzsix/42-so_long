/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnakasto <mnakasto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 14:02:49 by mnakasto          #+#    #+#             */
/*   Updated: 2025/08/14 18:31:49 by mnakasto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

static int	ft_count_word(char const *s, char sep)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == sep && s[i])
			i++;
		if (s[i])
			j++;
		while (s[i] != sep && s[i])
			i++;
	}
	return (j);
}

void	free_words(char **res, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		free(res[i]);
		i++;
	}
	free(res);
}

int	ft_cpy(char **res, const char *s, char sep)
{
	int			i;
	size_t		len;
	const char	*start;

	i = 0;
	while (*s)
	{
		while (*s == sep && *s)
			s++;
		if (!*s)
			break ;
		start = s;
		while (*s && *s != sep)
			s++;
		len = (size_t)(s - start);
		res[i] = malloc(len + 1);
		if (!res[i])
		{
			free_words(res, i);
			return (0);
		}
		ft_strlcpy(res[i++], start, len + 1);
	}
	res[i] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	int		mots;
	char	**res;

	if (!s)
		return (NULL);
	mots = ft_count_word(s, c);
	res = (char **)malloc(sizeof(char *) * (mots + 1));
	if (!res)
		return (NULL);
	if (!ft_cpy(res, s, c))
		return (NULL);
	return (res);
}

// int main (void)
// {
// 	char *s = "salut comment ca va        ";
// 	char **res = ft_split(s, ' ');
// 	while (*res)
// 	{
// 		printf("%s\n", *res);
// 		res++;
// 	}
// }