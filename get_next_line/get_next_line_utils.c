/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboubaza <mboubaza@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 14:24:04 by mboubaza          #+#    #+#             */
/*   Updated: 2025/12/21 16:09:39 by mboubaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (s == NULL)
		return (0);
	while (*s)
	{
		s++;
		i++;
	}
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned char	*str;
	int				i;

	i = 0;
	if (!s)
		return (NULL);
	str = (unsigned char *)s;
	while (str[i])
	{
		if (str[i] == (unsigned char)c)
			return ((char *)(s + i));
		i ++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)&str[i]);
	return (NULL);
}

void	*ft_calloc(size_t nelem, size_t elsize)
{
	void	*cal;
	size_t	i;

	if (elsize != 0 && nelem > __SIZE_MAX__ / elsize)
		return (NULL);
	if (nelem == 0 || elsize == 0)
	{
		cal = malloc(1);
		if (!cal)
			return (NULL);
		return (cal);
	}
	cal = malloc(nelem * elsize);
	if (!cal)
		return (NULL);
	i = 0;
	while (i < nelem * elsize)
		((unsigned char *)cal)[i ++] = 0;
	return (cal);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		len;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	str = malloc(sizeof(char) * len);
	if (!str)
		return (NULL);
	i = 0;
	while (*s1 && i < len)
	{
		str[i] = *s1;
		s1++;
		i ++;
	}
	while (*s2 && i < len)
	{
		str[i] = *s2;
		s2++;
		i ++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*subs;
	size_t	i;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_calloc(1, sizeof(char)));
	subs = malloc((len + 1) * sizeof(char));
	if (!subs)
		return (NULL);
	i = 0;
	while (i < len)
	{
		subs[i] = s[start + i];
		i++;
	}
	subs[i] = '\0';
	return (subs);
}
