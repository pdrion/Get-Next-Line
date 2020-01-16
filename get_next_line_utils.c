/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdrion <pdrion@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 14:05:32 by pdrion            #+#    #+#             */
/*   Updated: 2020/01/16 19:30:11 by pdrion           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_del(char **str)
{
	if (str != NULL)
	{
		free(*str);
		*str = NULL;
	}
}

char	*ft_strchr(const char *s, int c)
{
	char	ch;
	char	*src;

	ch = (char)c;
	src = (char *)s;
	while (*src != '\0')
	{
		if (*src == ch)
			return (src);
		src++;
	}
	if (ch == '\0')
		return (src);
	return (NULL);
}

char	*ft_strdup(const char *s1)
{
	char	*dst;
	size_t	len;

	len = 0;
	dst = NULL;
	while (s1[len])
		len++;
	if (dst == NULL && s1 == NULL)
		return (NULL);
	if ((dst = (char *)malloc(len + 1)) == NULL)
		return (NULL);
	dst[len] = '\0';
	while (len--)
		dst[len] = s1[len];
	return (dst);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	len_s;
	char	*result;

	len_s = 0;
	result = NULL;
	if (!s)
		return (NULL);
	while (s[len_s])
		len_s++;
	if (len_s < start)
		return (ft_strdup(""));
	len = ((len_s - start) < len) ? (len_s - start) : len;
	if (!(result = (char *)malloc((len + 1) * sizeof(char))))
		return (NULL);
	result[len] = '\0';
	while (len--)
		result[len] = s[start + len];
	return (result);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*result;
	unsigned int	i;
	size_t			len1;
	size_t			len2;

	i = 0;
	len1 = 0;
	len2 = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	while (s1[len1])
		len1++;
	while (s2[len2])
		len2++;
	if (!(result = (char*)malloc(sizeof(*result) * (len1 + len2 + 1))))
		return (NULL);
	while (*s1 != '\0')
		result[i++] = *s1++;
	while (*s2 != '\0')
		result[i++] = *s2++;
	result[i] = '\0';
	return (result);
}
