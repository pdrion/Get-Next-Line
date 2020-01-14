/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdrion <pdrion@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 14:38:25 by pdrion            #+#    #+#             */
/*   Updated: 2020/01/14 20:40:00 by pdrion           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int   main(int argc, char **argv)
{

	   char		*line; 
	   int		fd1; 
	   //	   int   	fd2;
	   int i;
	   
	   line = NULL;
	   if(argc > 1)
	   {
   fd1 = open(argv[1], O_RDONLY);
   //  fd2 = open(av[2], O_RDONLY); 
   while (i < 4)
   {
	   if (get_next_line(fd1, &line) != -1)
	   {
		   printf("%d er appel : %s\n",i, line);
		   if (line != NULL)
			   free(line);
	   }
	   i++;
   }
	   }
   return (0);
}
