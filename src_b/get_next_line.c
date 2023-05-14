/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almeliky <almeliky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 17:54:31 by almeliky          #+#    #+#             */
/*   Updated: 2023/05/14 15:21:55 by almeliky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

char	*get_next_line(int fd)
{
	char		*line;
	static char	*stc;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0))
		return (NULL);
	stc = ft_read(fd, stc);
	if (!stc)
		return (NULL);
	line = ft_newline(stc);
	stc = ft_ncut(stc);
	return (line);
}

char	*ft_read(int fd, char *stc)
{
	char	*buff;
	int		n;

	n = 1;
	buff = malloc(BUFFER_SIZE + 1);
	while (!ft_strchr(stc, '\n') && n != 0)
	{
		n = read(fd, buff, BUFFER_SIZE);
		if ((ft_strlen(stc) == 0 && n == 0) || n < 0)
		{
			free(buff);
			free(stc);
			return (NULL);
		}
		buff[n] = '\0';
		stc = ft_stcjoin(stc, buff);
	}
	free(buff);
	return (stc);
}

char	*ft_stcjoin(char *stc, char *buff)
{
	char	*str;

	if (!stc)
	{
		stc = malloc(1);
		stc[0] = '\0';
	}
	str = stc;
	stc = ft_join(stc, buff);
	free(str);
	return (stc);
}

char	*ft_newline(char *stc)
{
	char	*newline;
	int		i;

	i = 0;
	while (stc[i] && stc[i] != '\n')
		i++;
	if (stc[i] == '\n')
		i++;
	newline = malloc(i + 1);
	if (!newline)
		return (NULL);
	newline[i] = '\0';
	i--;
	while (i >= 0)
	{
		newline[i] = stc[i];
		i--;
	}
	return (newline);
}

char	*ft_ncut(char *stc)
{
	char	*temp;
	int		len;

	if (ft_strchr(stc, '\n'))
	{
		temp = stc;
		len = ft_strlen(ft_strchr(stc, '\n') + 1);
		stc = ft_substr(stc, ft_strlen(stc) - len, len);
		free (temp);
	}
	else
	{
		free(stc);
		return (NULL);
	}
	return (stc);
}
