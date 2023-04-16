/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerayyad <rerayyad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 23:28:02 by rerayyad          #+#    #+#             */
/*   Updated: 2023/04/16 01:00:16 by rerayyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <mlx.h>

int	main(int ac, char *av[])
{
	t_data	**fdf;

	if (ac == 2)
		fdf = ft_maps_reader(av[1]);
	ft_cleaner(&fdf, ft_height(av[1]));
	return (0);
}
