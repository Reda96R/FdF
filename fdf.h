/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerayyad <rerayyad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 23:28:35 by rerayyad          #+#    #+#             */
/*   Updated: 2023/04/25 16:53:20 by rerayyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "includes/get_next_line.h"
# include "mylib/libft.h"
# include "mylib/ft_printf/ft_printf.h"
typedef struct s_data
{
	int		x;
	int		y;
	int		z;
}	t_data;


/* ::: maps reader :::*/
t_data	**ft_maps_reader(char *file, int fd);
void  ft_parser(t_data **fdf, int fd, int y);
int	  ft_filler(t_data **fdf, int fd, int width);
/* ::: reader tools ::: */
int		ft_width(char *file);
int		ft_height(char *file);

/* ::: checkers ::: */
int		ft_extension_check(char *map);
int		ft_lenght_check(int fd, int y);

/* ::: janitor ::: */
void	ft_errors_buster(int id);
void	ft_false_input(int ac, int fd);
void	ft_cleaner(t_data ***fdf, int rows);

/* ::: helpers ::: */
int		ft_space_counter(char *str, char c);
//char	**ft_split(char const *s, char c);
//int		ft_atoi(const char *str);
//char	*ft_strrchr(char *s, int c);
//int		ft_strncmp(const char *s1, const char *s2, size_t n);
#endif
