/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerayyad <rerayyad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 23:28:35 by rerayyad          #+#    #+#             */
/*   Updated: 2023/04/17 01:10:31 by rerayyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "get_next_line.h"

typedef struct s_data
{
	int		x;
	int		y;
	int		z;
}	t_data;

/* ::: maps reader :::*/
t_data	**ft_maps_reader(char *file);
void	ft_filler(t_data **fdf, int fd);

/* ::: reader tools ::: */
int		ft_width(char *file);
int		ft_height(char *file);

/* ::: checkers ::: */
int		ft_extension_check(char *map);

/* ::: janitor ::: */
void	ft_errors_buster(int id);
void	ft_false_input(int ac, int fd);
void	ft_cleaner(t_data ***fdf, int rows);

/* ::: helpers ::: */
int		ft_word_counter(char *str, char c);
char	**ft_split(char const *s, char c);
int		ft_atoi(const char *str);
char	*ft_strrchr(char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
#endif
