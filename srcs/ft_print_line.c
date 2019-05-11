/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 11:11:04 by ffoissey          #+#    #+#             */
/*   Updated: 2018/12/17 14:58:06 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			ft_set_value(t_coor *c, t_line *l)
{
	l->i = -1;
	l->plus.x = 1;
	l->plus.y = 1;
	if (c->s.x > c->e.x)
		l->plus.x = -1;
	if (c->s.y > c->e.y)
		l->plus.y = -1;
	l->err.x = ft_abs(c->s.x - c->e.x);
	l->err.y = ft_abs(c->s.y - c->e.y);
	l->d.x = l->err.x * 2;
	l->d.y = l->err.y * 2;
	l->base.x = l->err.x;
	l->base.y = l->err.y;
}

static void		ft_swap_line(t_coor c, t_line l, int color, t_win *win)
{
	while (++l.i <= l.base.y)
	{
		if (c.s.x < W && c.s.y < H && c.s.x >= 0 && c.s.y >= 0)
			mlx_pixel_put(win->mlx_ptr, win->mlx_win, c.s.x, c.s.y, color);
		l.err.y -= l.d.x;
		if (l.err.y < 0)
		{
			c.s.x += l.plus.x;
			l.err.y += l.d.y;
		}
		c.s.y += l.plus.y;
	}
}

void			ft_print_line(t_coor c, int color, t_win *win)
{
	t_line	l;

	ft_set_value(&c, &l);
	if (l.base.y <= l.base.x)
	{
		while (++l.i <= l.base.x)
		{
			if (c.s.x < W && c.s.y < H && c.s.x >= 0 && c.s.y >= 0)
				mlx_pixel_put(win->mlx_ptr, win->mlx_win, c.s.x, c.s.y, color);
			l.err.x -= l.d.y;
			if (l.err.x < 0)
			{
				c.s.y += l.plus.y;
				l.err.x += l.d.x;
			}
			c.s.x += l.plus.x;
		}
	}
	else
		ft_swap_line(c, l, color, win);
}
