/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerayyad <rerayyad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 11:40:49 by rerayyad          #+#    #+#             */
/*   Updated: 2022/12/04 14:30:50 by rerayyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_strchr(char *str, int c)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == (char)c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = 0;
	j = 0;
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
	{
		free(s1);
		return (NULL);
	}
	while (s1 && s1[j] != '\0')
		str[i++] = s1[j++];
	j = 0;
	while (s2 && s2[j] != '\0')
		str[i++] = s2[j++];
	str[i] = '\0';
	free(s1);
	return (str);
}

char	*ft_line(char *src)
{
	int		i;
	char	*str;

	i = 0;
	if (!src)
		return (NULL);
	while (src[i] && src[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (src[i] && src[i] != '\n')
	{
		str[i] = src[i];
		i++;
	}
	if (src[i] == '\n')
		str[i++] = '\n';
	str[i] = '\0';
	return (str);
}

char	*ft_saver(char *stock)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (stock[i] && stock[i] != '\n')
		i++;
	if (!stock[i])
	{
		free(stock);
		return (0);
	}
	str = (char *)malloc(sizeof (char) * ft_strlen(stock) - i + 1);
	if (!str)
		return (NULL);
	i++;
	while (stock[i])
		str[j++] = stock[i++];
	str[j] = '\0';
	free(stock);
	return (str);
}
