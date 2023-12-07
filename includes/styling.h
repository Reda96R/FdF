/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   styling.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerayyad <rerayyad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 07:35:32 by rerayyad          #+#    #+#             */
/*   Updated: 2023/05/19 12:06:42 by rerayyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STYLING_H
# define STYLING_H

typedef struct s_colors
{
	int	s_r;
	int	s_g;
	int	s_b;
	int	e_r;
	int	e_g;
	int	e_b;
}	t_colors;

/* ::: Colors converter ::: */
int	r(int c);
int	g(int c);
int	b(int c);
int	rgb_encoder(int a, int b, int c);

/* ::: Colors ::: */
# define BLACK 0x191919
# define BLUE 0x2D4263
# define ORANGE 0xC84B31
# define WHITE 0xECDBBA
# define M_TEXT 0x950740

/* ::: Dimensions ::: */
# define X 1337
# define Y 800

/* ::: Keys ::: */
# define ESC 53
# define PL 24
# define PL_2 69
# define MI 27
# define MI_2 78
# define U 13
# define D 1
# define R 2
# define L 0
# define I 34
# define T 17
# define Z_U 30
# define Z_D 33
# define ROT 49
# define NUM_4 86
# define NUM_6 88
# define NUM_8 91
# define NUM_2 84

#endif
