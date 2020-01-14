/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdrion <pdrion@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 14:38:25 by pdrion            #+#    #+#             */
/*   Updated: 2019/12/20 18:19:23 by pdrion           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int   main(int argc, char **argv)
{

	   char		*line; 
	   int		fd1; 
	   //	   int   	fd2;
	   line = NULL;
	   if(argc > 1)
	   {
   fd1 = open(argv[1], O_RDONLY);
   //  fd2 = open(av[2], O_RDONLY); 
   get_next_line(fd1, &line);
   printf("1 er appel : %s\n", line);
   get_next_line(fd1, &line);
   printf("2eme appel : %s\n", line);
   get_next_line(fd1, &line);
   printf("3eme appel : %s\n", line);
   get_next_line(fd1, &line);
   printf("4eme appel :%s\n", line);
   get_next_line(fd1, &line);
   printf("5eme appel : %s\n", line);
   get_next_line(fd1, &line);
   printf("6eme appel : %s\n", line);
	   }
	   return (0);
}
