/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 21:25:08 by pruenrua          #+#    #+#             */
/*   Updated: 2024/04/11 15:59:50 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./cube.h"


int	main(int ac, char **av)
{
	t_data	d;

	if (ac != 2)
		return (puts(WRG_ARG_NO), 1);

	(void)av;
	d.parser_data = main_parser(av[1]);
	
	//parser
	//check_and_assign_data
	puts("done");
	// d = init();
	// d->parser_data = data_parser(av); // do the read file
	// assign_data(d);

}
