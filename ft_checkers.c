/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerayyad <rerayyad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 00:06:12 by rerayyad          #+#    #+#             */
/*   Updated: 2023/04/17 00:37:54 by rerayyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_extension_check(char *map)
{
	char	*extension;

	extension = ft_strrchr(map, 'f');
	if (extension == NULL || ft_strncmp(extension - 3, ".fdf", 4))
    return (0);
  return (1);
}
