/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpoungla <tpoungla@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-04-27 08:50:50 by tpoungla          #+#    #+#             */
/*   Updated: 2024-04-27 08:50:50 by tpoungla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

// int try_read(char *file_name)
// {
//     int     fd;
//     int     n;
//     char	**map;

// 	fd = open(file_name, O_RDONLY | O_CLOEXEC);
//     if (fd < 0)
// 	    return (perror("PARSER ERROR : "), 0);
//     n = count_line(fd);//open read
//     //malloc
//     //open read
//     //return map
// }

char    **word_cut(char *data)
{
    int     i;
    int     k;
    char    **res;
    // int     n;

    i = 0;
    // n = 0;
    k = 0;
    while (data[i])
    {
        if (data[i] == '\n')
            k++;
        i++; 
    }

    // printf("k = %d\n", k);
    return (res);
}