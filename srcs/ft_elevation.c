/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_elevation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 12:25:08 by ffoissey          #+#    #+#             */
/*   Updated: 2019/01/08 12:16:42 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_print_y(t_pad *pad, t_mx *mx, t_point *origin, int *im)
{
	t_coor	c;
	int		i;
	int		j;

	c.s.x = origin->x;
	j = -1;
	while (++j < mx->x)
	{
		i = -1;
		c.s.y = mx->mx[0][j] != BLANK
				? origin->y - mx->mx[0][j] * pad->depth : origin->y;
		while (++i < mx->y - 1)
		{
			c.e.x = c.s.x;
			c.e.y = origin->y;
			if (mx->mx[i + 1][j] != BLANK)
				c.e.y -= mx->mx[i + 1][j] * pad->depth;
			ft_prepare_color(mx, i, j, 'i');
			ft_fill_image(c, mx, im);
			if (mx->mx[i][j] != BLANK)
				c.s.y = origin->y - mx->mx[i][j] * pad->depth;
		}
		c.s.x += pad->pad;
	}
}

static void	ft_print_x(t_pad *pad, t_mx *mx, t_point *origin, int *im)
{
	t_coor	c;
	int		i;
	int		j;

	i = 0;
	while (i < mx->y)
	{
		j = 0;
		c.s.x = origin->x;
		c.s.y = origin->y;
		if (mx->mx[i][j] != BLANK)
			c.s.y -= mx->mx[i][j] * pad->depth;
		while (j < mx->x - 1)
		{
			c.e.x = c.s.x + pad->pad;
			c.e.y = origin->y;
			if (mx->mx[i][j + 1] != BLANK)
				c.e.y -= mx->mx[i][j + 1] * pad->depth;
			ft_prepare_color(mx, i, j++, 'j');
			ft_fill_image(c, mx, im);
			c.s.y = c.e.y;
			c.s.x = c.e.x;
		}
		i++;
	}
}

void		ft_print_elevation(t_win *win, t_pad *pad, t_mx *mx, t_point origin)
{
	t_image	im;

	im.im_ptr = mlx_new_image(win->mlx_ptr, W, H);
	im.im = (int *)mlx_get_data_addr(im.im_ptr, &im.bpp,
			&im.size_line, &im.endian);
	ft_print_x(pad, mx, &origin, im.im);
	ft_print_y(pad, mx, &origin, im.im);
	mlx_put_image_to_window(win->mlx_ptr, win->mlx_win, im.im_ptr, 0, 0);
	mlx_destroy_image(win->mlx_ptr, im.im_ptr);
}
