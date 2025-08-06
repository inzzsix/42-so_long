/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnakasto <mnakasto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 20:52:23 by mnakasto          #+#    #+#             */
/*   Updated: 2025/08/04 19:36:38 by mnakasto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	parse_args(int ac, char **av)
{
	if (ac != 2)
	{
		ft_printf("Error\nUsage: %s <map.ber>\n", av[0]);
		return (0);
	}
	if (!check_extension(av[1]))
	{
		ft_printf("Error\nInvalid file extension. Expected .ber\n");
		return (0);
	}
	return (1);
}
