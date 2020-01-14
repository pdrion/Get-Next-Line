/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdrion <pdrion@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 18:17:41 by pdrion            #+#    #+#             */
/*   Updated: 2020/01/14 21:52:05 by pdrion           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//fonction pour une ligne 
static int	newline(char *str, char **line)
{
	int		len;
	char	*tmp;

	len = 0;
	while (str[len] != '\n' && str[len] != '\0')
		len++;
	if (str[len] == '\n')
	{
		*line = ft_substr(str, 0, len);
		tmp = ft_strdup(&str[len + 1]);
		free(str);
		str = tmp;
		if (str[0] == '\0')
		{
			//	del(&str);
			free(str);
			str = NULL;
		}
	}
	else
	{
		*line = ft_strdup(str);
		//del(&str);
		free(str);
		str = NULL;
	}
	return (1);
}

// fonction pour le retour

static int	retour(char *str, char **line, int cursor)
{
	if (cursor < 0)
		return (-1);
	else if (cursor == 0 && str == NULL)
		return (0);
	else
		return (newline(str, line));
}


// fonction principale
int get_next_line(int fd, char **line)
{
	char		data[BUFFER_SIZE + 1];
	int 		cursor;
	static char	*str;
//	char		*tmp;

	if (fd < 0 || line == NULL)
		return (-1);

	while ((cursor = read(fd, data, BUFFER_SIZE)) > 0)
	{
		data[cursor] = '\0';
		if (str == NULL)
			str = ft_strdup(data);
		else
		{
			str = ft_strjoin(str, data);
			//		free(str);
			//str = tmp;
		}
		if (ft_strchr(str, '\n'))
			break ;
	}
	return (retour(str, line, cursor));
}

/* ret = 0; */
/* 	str = !(str) ? ft_strdup("") : str; */

/* 	printf("ptr line %p \n", *line); */
/* 	printf("ptr line %p \n", *line); */

/* 	if(!(tmp = malloc(BUFFER_SIZE * sizeof(char)))) */
/* 		return(-1); */
/* 	while((cursor = read(fd, data, BUFFER_SIZE)) > 0 && ret == 0)	   */
/* 		{ */
/* 			printf("%d et buffer = %d\n", cursor, BUFFER_SIZE); */
/* 			data[cursor] = '\0'; */
/* 			str = ft_strjoin(str, data); */
/* 			printf("string : %s \n\n",str); */
/* 			if ((tmp = ft_strchr(str, '\n'))) */
/* 				{ */
/* 					printf("len str1 = %zu\n", ft_strlen(str)); */
/* 					ret = 1; */
/* 					*tmp = '\0'; */
/* 					printf("len str2 = %zu\n", ft_strlen(str)); */
/* 					*line = str; */
/* 						free(str); */
/* 					str = tmp + 1; */
/* 				} */
/* 		} */
/* //	str = ft_substr(str, 0, ft_strlen(str)); */
/* //	free(data); */
/* 	//printf("string : %s\n", str); */
/* 	if(ret == 1) */
/* 	{ */
/* 		return (1); */
/* 	} */
/* 	//	printf("wfffffffffffffff  %s\n", str); */
/* 	return (0); */
/* } */
