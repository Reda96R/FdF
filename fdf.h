/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerayyad <rerayyad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 23:28:35 by rerayyad          #+#    #+#             */
/*   Updated: 2023/04/16 01:00:51 by rerayyad         ###   ########.fr       */
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

/* ::: parsing :::*/
t_data	**ft_maps_reader(char *file);
void	ft_filler(t_data **fdf, int fd);

/* ::: calculators ::: */
int		ft_width(char *file);
int		ft_height(char *file);

/* ::: cleaner ::: */
void	ft_cleaner(t_data ***fdf, int rows);

/* ::: helpers ::: */
int		ft_word_counter(char *str, char c);
char	**ft_split(char const *s, char c);
int		ft_atoi(const char *str);
#endif

