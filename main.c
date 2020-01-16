/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdrion <pdrion@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 14:38:25 by pdrion            #+#    #+#             */
/*   Updated: 2020/01/16 12:00:40 by pdrion           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


int		main(int argc, char **argv)
{
	char	*line;
	int		fd;
	int		ret;

	if (argc == 2)
		fd = open(argv[1], O_RDONLY);
	else
		fd = 0;
	line = NULL;
	ret = 1;
	while (ret)
	{
		ret = get_next_line(fd, &line);
		printf("%s\treturn value - %d\n", line, ret);
		//ft_del(&line);
	}
	close(fd);
}
/*
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
*/
