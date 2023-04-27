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
<<<<<<< HEAD
<<<<<<< HEAD
=======
/*   Updated: 2023/04/25 16:52:15 by rerayyad         ###   ########.fr       */
>>>>>>> e52361800a21680e477dca61270e1946cbd2bfa5
=======
/*   Updated: 2023/04/25 16:52:15 by rerayyad         ###   ########.fr       */
>>>>>>> a64d857e688b6663dfcf49b0f2c9e509629c1855
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
<<<<<<< HEAD
<<<<<<< HEAD
#include "get_next_line.h"
=======
>>>>>>> e52361800a21680e477dca61270e1946cbd2bfa5
=======
>>>>>>> a64d857e688b6663dfcf49b0f2c9e509629c1855
#include "mlx_linux/mlx.h"

int	main(int ac, char *av[])
{
	t_data	**fdf;
	int		fd;
  char  *line;
	
  fd = open (av[1], O_RDONLY, 0);
  if (!get_next_line(fd, &line))
  {
    free(line);
    close (fd);
    ft_errors_buster(4);
  }
  fd = open (av[1], O_RDONLY, 0);
  if (ac != 2 || !ft_extension_check(av[1]) || fd <= 0)
	{
		ft_false_input(ac, fd);
		close (fd);
		exit (1);
	}
<<<<<<< HEAD
<<<<<<< HEAD
  else if (!ft_lenght_check(av[1], ft_width(av[1])))
		  ft_errors_buster(1);
  else
=======
	else if (!ft_lenght_check(av[1], ft_width(av[1])))
		ft_errors_buster(1);
=======
	else if (!ft_lenght_check(av[1], ft_width(av[1])))
		ft_errors_buster(3);
>>>>>>> a64d857e688b6663dfcf49b0f2c9e509629c1855
	else
>>>>>>> e52361800a21680e477dca61270e1946cbd2bfa5
			fdf = ft_maps_reader(av[1], fd);
	ft_cleaner(&fdf, ft_height(av[1]));
  return (0);
}
