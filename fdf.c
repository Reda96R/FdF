/* *
 * ************************************************************************ */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerayyad <rerayyad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 23:28:02 by rerayyad          #+#    #+#             */
/*   Updated: 2023/04/25 18:25:48 by rerayyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "get_next_line.h"
#include <mlx.h>
// #include "mlx_linux/mlx.h"
int	main(int ac, char *av[])
{
	t_data	**fdf;
	int		fd;
  // char  *line;
	
  fd = open (av[1], O_RDONLY, 0);
  // if (!get_next_line(fd, &line))
  // {
  //   free(line);
  //   close (fd);
  //   ft_errors_buster(4);
  // }
  // fd = open (av[1], O_RDONLY, 0);
  if (ac != 2 || !ft_extension_check(av[1]) || fd <= 0)
	{
		ft_false_input(ac, fd);
		close (fd);
		exit (1);
	}
  else if (!ft_lenght_check(av[1], ft_width(av[1])))
		  ft_errors_buster(1);
  else
			fdf = ft_maps_reader(av[1], fd);
	ft_cleaner(&fdf, ft_height(av[1]));
  return (0);
}
