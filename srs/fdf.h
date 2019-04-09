/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btorp <btorp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 20:33:24 by btorp             #+#    #+#             */
/*   Updated: 2019/04/09 20:53:30 by btorp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define SIGN -1
# define ISO_ANGLE 0.46373398
# define ISO_ANGLE_TRUE 0.523599 
# define SPEED 1.5
# define DISTANCE 15
# define DEFAULT_COLOR 0xF32CEF
# define WINDOW_HEIGHT  1600
# define WINDOW_WIDTH  1600
# define PLUS_ANGLE 0.25
# define START_K  5
# include "mlx.h"
# include "../libft/libft.h"
# include <stdlib.h>
# include <math.h>

typedef struct s_point
{
	int			x;
	int			y;
	int			z;
	int			color;
}				t_point;

typedef struct s_map
{
	int			size_v;
	int			size_h;
	t_point		**points;
}				t_map;

typedef struct s_point_r
{
	double			x;
	double			y;
	double			z;
	int				color;
}				t_point_r;

typedef struct s_map_r
{
	int			size_v;
	int			size_h;
	t_point_r	**points;
	double		angle_z;
	double		angle_x;
	double		angle_y;
}				t_map_r;

typedef struct s_line
{
	double			x0;
	double			x1;
	double			y1;
	double			y0;
	int				start;
	int				end;
	int				x;
	int				y;
}				t_line;

typedef	struct s_move
{
	double		x;
	double		y;
	float		k;
}				t_move;

typedef	struct s_mlx
{
	void		*i;
	void		*w;
}				t_mlx;

typedef	struct s_gradient
{
	double	startx;
	double	endx;
	double	starty;
	double	endy;
	double	dy;
	double	dx;
	double	cur_x;
	double	cur_y;
	int		color_1;
	int		color_2;
	int		color_cur;
}				t_gradient;

typedef	struct s_draw
{
	int		iX1;
	int		iY1;
	int		iX2;
	int		iY2;
	int		deltaX;
	int		deltaY;
	int		length;
	double	dX;
	double	dY;
	double	x;
	double	y;
}				t_draw;

typedef	struct s_fuck_norme
{
	int			i;
	int			j;
	double		s;
	float		k;
}				t_fuck_norme;


t_map		*validate_main(int fd);
int			validate_point(char *str, t_point *point);
int			totally_nessasary(char	***str, int a);
void		tpointcpy(t_point *dst, t_point *srs);
int			doesitint(char *str);
int			does_it_16int(char *str);
int			free_strstr(char ***str);
int			array_len(char **a);
t_point		**ft_realloc(t_point ***a, int new_size, int h_size);
t_map		*exiter_validate(t_map	**map, char **str, char ***str2);
int			ft_atoi16(char *str);
void		tpoint_cpy(t_point **dst, t_point *srs, int n);
void		rotate_point(t_point_r *t, double angle);
t_map_r		*make_map_r(t_map *map, double angle);
void		displayer(t_mlx t, t_map_r *map, t_move u);
void		draw_line(t_line *line, void *init, void *window);
void		x_os(t_map_r *map, double angle, t_map a);
int			ft_atoi16(char *str);
void		z_os(t_map_r *map, double angle, t_map a);
void		y_os(t_map_r *map, double angle, t_map a);
void		iso(t_map_r *map, t_map a);
void		goiso(double *x, double *y, int z, double angle);
void		change_color(t_map_r *map, t_map a);
int 		get_color(t_gradient *t);	
int			ft_max (int a, int b);
void		fill_color(void *init, void *w, int i);
void		go_black(t_map_r *map, t_map a);
#endif