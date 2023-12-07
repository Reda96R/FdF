/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_colors_converter.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerayyad <rerayyad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 13:02:37 by rerayyad          #+#    #+#             */
/*   Updated: 2023/05/19 10:34:26 by rerayyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	r(int c)
{
	return (c >> 16);
}

int	g(int c)
{
	return ((c >> 8) & 0xFF);
}

int	b(int c)
{
	return (c & 0xFF);
}

int	rgb_encoder(int a, int b, int c)
{
	return ((a << 16) + (b << 8) + c);
}
