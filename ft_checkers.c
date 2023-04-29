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
#include "mylib/libft.h"

int	ft_extension_check(char *map)
{
	char	*extension;

	extension = ft_strrchr(map, 'f');
	if (extension == NULL || ft_strncmp(extension - 3, ".fdf", 4))
		return (0);
	return (1);
}

int	ft_lenght_check(char *file, int y)
{
  char *line;
  int   r;
  int fd;

  r = 1;
  fd = open (file, O_RDONLY, 0);
  while (get_next_line(fd, &line))
  {
    if (y != ft_word_counter(line, ' '))
    {
      r = 0;
      free(line);
      break;
    }
    free(line);
  }
  close(fd);
  // free(line);
  return (r);
}
