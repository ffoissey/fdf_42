/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_para2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 15:51:38 by ffoissey          #+#    #+#             */
/*   Updated: 2019/01/08 16:44:35 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_print_y_par2(t_ref *r, int i, int j, t_coor *c)
{
	if (r->mx->mx[i + 1][j] < r->mx->mx[i][j])
	{
		c->e.y -= (r->mx->mx[i + 1][j] - r->mx->mx[i][j]) * r->pad->depth;
		ft_prepare_color(r->mx, i, j, 'i');
		ft_fill_image(*c, r->mx, r->im);
		c->s.y = c->e.y;
		c->e.y = ft_arr(c->s.y + r->pad->pad * sin(ANGLE_ISO));
		c->e.x = ft_arr(c->s.x - r->pad->pad * cos(ANGLE_ISO));
		ft_prepare_color_par(r->mx, i + 1, j);
		ft_fill_image(*c, r->mx, r->im);
	}
	else
	{
		c->e.y = ft_arr(c->s.y + r->pad->pad * sin(ANGLE_ISO));
		c->e.x = ft_arr(c->s.x - r->pad->pad * cos(ANGLE_ISO));
		ft_prepare_color_par(r->mx, i, j);
		ft_fill_image(*c, r->mx, r->im);
		c->s.y = c->e.y;
		c->s.x = c->e.x;
		c->e.y -= (r->mx->mx[i + 1][j] - r->mx->mx[i][j]) * r->pad->depth;
		ft_prepare_color(r->mx, i, j, 'i');
		ft_fill_image(*c, r->mx, r->im);
	}
}

void		ft_print_y_par(t_ref *r, int j, t_coor *c)
{
	int		i;

	i = 0;
	while (i < r->mx->y - 1)
	{
		if (r->mx->mx[i + 1][j] != BLANK && r->mx->mx[i][j] != BLANK)
			ft_print_y_par2(r, i++, j, c);
		else
		{
			c->e.y = ft_arr(c->s.y + r->pad->pad * sin(ANGLE_ISO));
			c->e.x = ft_arr(c->s.x - r->pad->pad * cos(ANGLE_ISO));
			ft_prepare_color(r->mx, i++, j, 'i');
			ft_fill_image(*c, r->mx, r->im);
		}
		c->s.y = c->e.y;
		c->s.x = c->e.x;
	}
}

static void	ft_print_x_par2(t_ref *r, int i, int j, t_coor *c)
{
	if (r->mx->mx[i][j + 1] < r->mx->mx[i][j])
	{
		c->e.y -= (r->mx->mx[i][j + 1] - r->mx->mx[i][j]) * r->pad->depth;
		ft_prepare_color(r->mx, i, j, 'j');
		ft_fill_image(*c, r->mx, r->im);
		c->s.y = c->e.y;
		c->e.x = c->s.x + r->pad->pad;
		ft_prepare_color_par(r->mx, i, j + 1);
		ft_fill_image(*c, r->mx, r->im);
	}
	else
	{
		c->e.x = c->s.x + r->pad->pad;
		ft_prepare_color_par(r->mx, i, j);
		ft_fill_image(*c, r->mx, r->im);
		c->s.x = c->e.x;
		c->e.y -= (r->mx->mx[i][j + 1] - r->mx->mx[i][j]) * r->pad->depth;
		ft_prepare_color(r->mx, i, j, 'j');
		ft_fill_image(*c, r->mx, r->im);
	}
}

void		ft_print_x_par(t_ref *r, int i, t_coor *c)
{
	int		j;

	j = 0;
	while (j < r->mx->x - 1)
	{
		if (r->mx->mx[i][j + 1] != BLANK && r->mx->mx[i][j] != BLANK)
			ft_print_x_par2(r, i, j++, c);
		else
		{
			c->s.y = c->e.y;
			c->e.x = c->s.x + r->pad->pad;
			ft_prepare_color(r->mx, i, j++, 'j');
			ft_fill_image(*c, r->mx, r->im);
		}
		c->s.y = c->e.y;
		c->s.x = c->e.x;
	}
}
