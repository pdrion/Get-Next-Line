/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdrion <pdrion@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 18:17:41 by pdrion            #+#    #+#             */
/*   Updated: 2019/12/20 18:18:23 by pdrion           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int get_next_line(int fd, char **line)
{
  char			*data;
  int			buffer;
  int 			cursor;
  static char	*str;
  char			*tmp;
  int i;
  int ret;

  buffer = 10;
  i = 0;
  ret = 0;

  if (str == 0)
	  str = "";
    if(!(str = malloc(buffer * sizeof(char))))
		return(-1);

	if (*line)
		str = *line;
	else
		*line = str;

	
	printf("ptr line %p \n", *line);
	if(!(data = malloc(buffer * sizeof(char) + 1)))
		return(-1);
	if(!(tmp = malloc(buffer * sizeof(char))))
		return(-1);
	while((cursor = read(fd, data, buffer)) > 0)	  
		{
			data[cursor] = '\0';
			i = 0;
			while (i < buffer && ret == 0)
				{
					tmp[i] = data[i];
					
					if(tmp[i] == '\n')
						{
							ret = 1;
							tmp[i + 1] = '\0';
							free(tmp);
						}
					i++;
				}
			str = ft_strjoin(str, tmp);

			*line = str;
			//printf("string : %s\n", str);
					if(ret == 1)
				{
			free(data);
					return (1);
				}
		}
	//	printf("wfffffffffffffff  %s\n", str);
	return (0);
}
