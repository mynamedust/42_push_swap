/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almeliky <almeliky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 17:52:19 by almeliky          #+#    #+#             */
/*   Updated: 2023/05/14 15:21:59 by almeliky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	ft_strlen(const char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *str, int c)
{
	char	i;

	if (!str)
		return (NULL);
	i = (char)c;
	while (*str)
	{
		if (*str == i)
			return ((char *)str);
		str++;
	}
	if (*str == i)
		return ((char *)str);
	return (0);
}

char	*ft_substr(char *s, int start, int len)
{
	char	*str;
	int		c;

	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	c = len;
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	while (*s && start > 0)
	{
		s++;
		start--;
	}
	while (*s && len > 0)
	{
		*str++ = *s++;
		len--;
	}
	*str = '\0';
	str -= c;
	return (str);
}

char	*ft_strdup(char *str)
{
	char	*arr;
	int		j;
	int		i;

	j = ft_strlen(str);
	arr = malloc(j + 1);
	if (!arr)
		return (NULL);
	i = 0;
	while (i < j)
	{
		arr[i] = str[i];
		i++;
	}
	arr[i] = '\0';
	return (arr);
}

char	*ft_join(char *s1, char *s2)
{
	char	*newstr;
	int		i;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	newstr = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!newstr)
		return (newstr);
	while (*s1)
		newstr[i++] = *s1++;
	while (*s2)
		newstr[i++] = *s2++;
	newstr[i] = '\0';
	return (newstr);
}
