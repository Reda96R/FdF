/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_janitor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerayyad <rerayyad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 23:38:44 by rerayyad          #+#    #+#             */
/*   Updated: 2023/04/25 17:17:30 by rerayyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_false_input(int ac, int fd)
{
	if (ac != 2)
		ft_putstr_fd("Usage: ./fdf <filename> [ case_size z_size ]\n", 2);

	else if (fd <= 0)
		ft_putstr_fd("file does not exist\n", 2);

	else
		ft_putstr_fd("invalide file type!\n", 2);
}

void	ft_errors_buster(int id)
{
	if (id == 1)
		ft_putstr_fd("invlide line lenght\n", 2);
	else if (id == 2)
		write(2, "invalide map file !\n", 20);
	else if (id == 3)
		write(2, "invalide map file !\n", 20);
	exit (1);
}


void	ft_cleaner(t_data ***fdf, int rows)
{
	int	y;
	int	x;

	y = 0;
	while (y < rows)
	{
		x = 0;
		while ((*fdf)[y][x].z)
			free(&((*fdf)[y][x++].z));
		free((*fdf)[y++]);
	}
	free(*fdf);
	*fdf = NULL;
}

