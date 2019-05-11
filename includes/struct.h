/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 14:12:50 by ffoissey          #+#    #+#             */
/*   Updated: 2019/01/08 15:57:04 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef	struct	s_point
{
	int			x;
	int			y;
}				t_point;

typedef	struct	s_pad
{
	int			pad;
	int			depth;
	float		ang;
}				t_pad;

typedef	struct	s_info
{
	t_point		origin;
	t_point		scale;
	t_pad		pad;
	t_pad		o_pad;
	int			view;
	int			grid;
	int			escape;
	int			hud;
}				t_info;

typedef struct	s_image
{
	int			*im;
	int			bpp;
	int			size_line;
	int			endian;
	void		*im_ptr;
}				t_image;

typedef	struct	s_coor
{
	t_point		s;
	t_point		e;
}				t_coor;

typedef struct	s_win
{
	void		*mlx_ptr;
	void		*mlx_win;
}				t_win;

typedef struct	s_color
{
	float	s;
	float	step;
	float	e;
	float	scale;
	int		inc;
	float	p;
}				t_color;

typedef struct	s_mx
{
	int			**mx;
	int			x;
	int			y;
	int			min;
	int			max;
	int			diff;
	t_color		color;
}				t_mx;

typedef	struct	s_pack
{
	t_mx		*mx;
	t_win		*win;
}				t_pack;

typedef struct	s_line
{
	t_point		d;
	t_point		plus;
	t_point		base;
	t_point		err;
	int			i;
}				t_line;

typedef struct	s_ref
{
	t_pad		*pad;
	t_mx		*mx;
	int			*im;
}				t_ref;

#endif
