/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 14:41:53 by ffoissey          #+#    #+#             */
/*   Updated: 2019/01/07 18:10:07 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		ft_step(t_mx *mx, t_line *l, char x_or_y)
{
	if (x_or_y == 'x' && l->base.x)
		mx->color.step = (float)mx->color.scale / (float)l->base.x;
	else if (x_or_y == 'y' && l->base.y)
		mx->color.step = (float)mx->color.scale / (float)l->base.y;
}

static void		ft_swap_fill_image(t_coor c, t_line l, t_mx *mx, int *im)
{
	ft_step(mx, &l, 'y');
	while (++l.i <= l.base.y)
	{
		if (mx->color.e != BLANK && c.s.x < W && c.s.y < H
			&& c.s.x >= 0 && c.s.y >= 0)
		{
			im[c.s.x + W * c.s.y] = ft_set_color(mx->color.s, mx->color.p);
			mx->color.s += mx->color.inc * mx->color.step;
		}
		l.err.y -= l.d.x;
		if (l.err.y < 0)
		{
			c.s.x += l.plus.x;
			l.err.y += l.d.y;
		}
		c.s.y += l.plus.y;
	}
}

void			ft_fill_image(t_coor c, t_mx *mx, int *im)
{
	t_line	l;

	ft_set_value(&c, &l);
	if (l.base.y <= l.base.x)
	{
		ft_step(mx, &l, 'x');
		while (++l.i <= l.base.x)
		{
			if (mx->color.e != BLANK && c.s.x < W && c.s.y < H
				&& c.s.x >= 0 && c.s.y >= 0)
			{
				im[c.s.x + W * c.s.y] = ft_set_color(mx->color.s, mx->color.p);
				mx->color.s += mx->color.inc * mx->color.step;
			}
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
		ft_swap_fill_image(c, l, mx, im);
}
