/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerayyad <rerayyad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 00:06:12 by rerayyad          #+#    #+#             */
/*   Updated: 2023/04/25 18:48:16 by rerayyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "includes/get_next_line.h"
#include "mylib/libft.h"

int	ft_extension_check(char *map)
{
	char	*extension;

	extension = ft_strrchr(map, 'f');
	if (extension == NULL || ft_strncmp(extension - 3, ".fdf", 4))
		return (0);
	return (1);
}

// int ft_lenght_check(int fd, int y)
// {
//   char *line;
//   int   r;
//
//   while (get_next_line(fd, &line))
//   {
//     if (y != ft_space_counter(line, ' '))
//     {
//       r = 0;
//       break;
//     }
//     free(line);
//   }
//   free(line);
//   close (fd);
//   return (r);
// }

int ft_lenght_check(int fd, int width)
{
  char    **str;
  char    *line;
  int             x;
  int             y;
  int             r;

  y = 0;
  r = 1;
  width = 1;
  while (get_next_line(fd, &line))
  {
    if (y == 0)
      width += ft_space_counter(line, ' ');
    str = ft_split(line, ' ');
    x = 0;
    while (str[x])
    {
      free(str[x]);
      x++;
    }
    if (x != width)
      r = 0;
    free(str);
    free(line);
    y++;
  }
  printf("test%d\n", r);
  return (r);
}
