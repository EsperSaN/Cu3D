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

int scanner(char *data)
{
    int i;

    i = 0;
    while (data[i])
    {
        
        i++;
    }
    return (1);
}
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

// int    find_height(char *data)
// {
//     int     i;
//     int     k;

//     i = 0;
//     k = 0;
//     while (data[i])
//     {
//         if (data[i] == '\n')
//             k++;
//         i++; 
//     }

//     printf("height = %d\n", k);
//     return (k);
// }

// int    find_width(char *data, int h)
// {
//     int i;
//     int k;

//     k = 0;
//     i = 0;
//     while (i < h)
//     {

//     }
// }