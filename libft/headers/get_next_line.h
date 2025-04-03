/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnakasto <mnakasto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 11:53:42 by mnakasto          #+#    #+#             */
/*   Updated: 2025/04/03 19:28:58 by mnakasto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include <fcntl.h>
# include <stdlib.h>

char	*extract_line(const char *stash);
char	*get_next_line(int fd);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s);
<<<<<<< HEAD:libft/headers/get_next_line.h
size_t	ft_strlen(const char *s);
=======
size_t		ft_strlen(const char *s);
>>>>>>> 523210be967e943887faa2e2113bfcdb1fa44047:so_long/libft/headers/get_next_line.h
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif
