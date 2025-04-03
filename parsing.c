/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnakasto <mnakasto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 20:52:23 by mnakasto          #+#    #+#             */
/*   Updated: 2025/04/03 20:52:27 by mnakasto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int check_extension(char *s)
{
   int  i;

   i = 0;
   if (strlen(s) < 4)
    return (0);
   while (s[i] != '\0')
    i++;
   if (s[i - 1] == 'r' && s[i - 2] == 'e' && s[i - 3] == 'b' && s[i - 4] == '.')
    return (1);
   return (0);  
}

int check_rectangular(char **map)
{
    int i;
    long unsigned int expected_len;

    i = 0;
    if (!map || !map[0])
        return (0);
    expected_len = strlen(map[0]);
    while (map[i])
    {
        if (strlen(map[i]) != expected_len)
        {
            printf("Error\nLa carte n'est pas rectangulaire\n");
            return (0);
        }
        i++;
    }
    return (1);
}

int check_map_elements(char **map)
{
    int i = 0;
    int j;
    int count_p = 0;
    int count_e = 0;
    int count_c = 0;

    while (map[i] != NULL)
    {
        j = 0;
        while (map[i][j] != '\0')
        {
            if (map[i][j] == 'P') count_p++;
            else if (map[i][j] == 'E') count_e++;
            else if (map[i][j] == 'C') count_c++;
            j++; 
        }
        i++;
    }
    if (count_p != 1 || count_e < 1 || count_c < 1)
        return (0);
    return (1); 
}
int check_walls(char **map, int height, int width)
{
    int i;
    int j;;

    j = 0;
    while (j < width)
    {
        if (map[0][j] != '1' || map[height - 1][j] != '1')
        {
            printf("Error\nMur ouvert à la ligne %d colonne %d\n", (map[0][j] != '1' ? 0 : height - 1), j);
            return (0);
        }
        j++;
    }
    i = 0;
    while (i < height)
    {
        if (map[i][0] != '1' || map[width - 1][j] != '1')
        {
            printf("Error\nMur ouvert à la ligne %d colonne %d\n", (map[i][0] != '1' ? 0 : width - 1), i);

        }
            return (0);
        i++;
    }
    return (1);
}
int	is_path_valid(map, height, width)
{

}