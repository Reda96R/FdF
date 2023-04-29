/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helpers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerayyad <rerayyad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 17:39:15 by rerayyad          #+#    #+#             */
/*   Updated: 2023/04/25 18:26:29 by rerayyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int	ft_word_counter(char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
		if (str[i++] == c && str[i] != c)
			count++;
  return (count);
}
