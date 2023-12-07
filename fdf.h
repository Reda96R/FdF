/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerayyad <rerayyad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 10:43:31 by rerayyad          #+#    #+#             */
/*   Updated: 2023/05/19 18:40:56 by rerayyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdint.h>
# include <math.h>
// # include <mlx.h>
# include "mlx_linux/mlx.h"
# include "includes/styling.h"
# include "includes/get_next_line.h"
# include "mylib/libft.h"
# include "mylib/ft_printf/ft_printf.h"

# define MLX_ERROR 0

typedef struct s_img
{
	void	*img;
	char	*id;
	int		bpp;
	int		len;
	int		endian;
	float	alpha;
	float	beta;
	float	gamma;
}	t_img;

typedef struct s_data
{
	float		x;
	float		y;
	float		z;
	int			color;
	int			end;
}	t_data;

typedef struct s_canvas
{
	int			win_x;
	int			win_y;
	int			isometric;
	int			scale;
	int			z_scale;
	int			height;
	int			width;
	double		angle;
	int			rot;
	void		*mlx_ptr;
	void		*win_ptr;
	int			offset_x_iso;
	int			offset_y_iso;
	int			offset_x;
	int			offset_y;
	t_data		**fdf;
	t_img		img;
	int			n;
}	t_canvas;

/* ::: maps reader ::: */
t_data	**ft_maps_reader(char *file, int fd);
void	ft_filler(t_data **fdf, int fd);

/* ::: maps drawer ::: */
void	ft_drawzilla(t_data **fdf, t_canvas *mlx, int height);
void	ft_drawzilla_b(t_data **fdf, t_canvas *mlx, int height);
void	ft_line_drawer(t_data a, t_data b, t_canvas *mlx);
void	ft_menu(t_canvas *mlx);
void	ft_menu_instructions(t_canvas *mlx);
void	ft_switch_to_iso(float *x, float *y, float *z, double n);

/* ::: reader tools ::: */
int		ft_width(char *file);
int		ft_height(char *file);

/* ::: Keys handler ::: */
void	ft_keylogger(t_canvas *mlx, int y, int n);
int		ft_cross(int key, t_canvas *mlx);
void	ft_move(t_canvas *mlx, int key);
void	ft_zoom(t_canvas *mlx, int key);
void	ft_z_scaler(t_canvas *mlx, int key);
void	ft_quit(t_canvas *mlx);
void	ft_rotation(t_canvas *mlx, int key);
int		ft_keys_log_b(int key, t_canvas *mlx);
void	ft_switch_proj(t_canvas *mlx, int key);

/* ::: checkers ::: */
int		ft_extension_check(char *map);
int		ft_key_check(int key);

/* ::: janitor ::: */
void	ft_errors_buster(int id);
void	ft_false_input(int ac, int fd, char *line);
void	ft_cleaner(t_data ***fdf, int rows);

/* ::: helpers ::: */
int		ft_space_counter(char *str, char c);
float	ft_absolute_value(float n);
int		ft_colors(char *str, int z);
int		ft_default_colors(int z);
void	ft_pixel_put(t_canvas *mlx, int x, int y, int color);

#endif
