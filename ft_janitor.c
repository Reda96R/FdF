/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_janitor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerayyad <rerayyad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 23:38:44 by rerayyad          #+#    #+#             */
/*   Updated: 2023/05/19 09:18:43 by rerayyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_false_input(int ac, int fd, char *line)
{
	if (ac != 2)
		ft_putstr_fd("Usage: ./fdf <filename> [ case_size z_size ]\n", 2);
	else if (fd <= 0)
		ft_putstr_fd("Error: file does not exist\n", 2);
	else if (!line || line[0] == '\n')
		ft_putstr_fd("Error: No data found\n", 2);
	else
		ft_putstr_fd("Error: invalide file type!\n", 2);
	free(line);
	close (fd);
	exit (1);
}

void	ft_errors_buster(int id)
{
	if (id == 1)
		ft_putstr_fd("invlide line lenght\n", 2);
	else if (id == 2)
		write(2, "invalide map file !\n", 2);
	else if (id == 3)
		write(2, "invalide map file !\n", 2);
	exit (1);
}

void	ft_cleaner(t_data ***fdf, int rows)
{
	int	y;

	y = 0;
	while (y < rows)
		free((*fdf)[y++]);
	free(*fdf);
	*fdf = NULL;
}
