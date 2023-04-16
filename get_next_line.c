/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerayyad <rerayyad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 10:55:19 by rerayyad          #+#    #+#             */
/*   Updated: 2023/04/15 02:52:00 by rerayyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_fill(char *stock, int fd)
{
	int		i;
	char	*str;

	str = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!str)
	{
		free(str);
		return (NULL);
	}
	i = 1;
	while (i && !ft_strchr(stock, '\n'))
	{
		i = read(fd, str, BUFFER_SIZE);
		if (i < 0)
		{
			free (str);
			free(stock);
			return (NULL);
		}
		str[i] = '\0';
		stock = ft_strjoin(stock, str);
	}
	free(str);
	return (stock);
}

int	get_next_line(int fd, char **line)
{
	char		*str;
	static char	*stock;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	stock = ft_fill(stock, fd);
	if (!stock)
		return (0);
	str = ft_line(stock);
	stock = ft_saver(stock);
	if (!str[0])
	{
		free(str);
		free (stock);
		return (0);
	}
	*line = str;
	return (1);
}
