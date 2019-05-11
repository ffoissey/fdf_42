/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_top_down.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 18:25:59 by ffoissey          #+#    #+#             */
/*   Updated: 2018/12/17 14:53:11 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_scale_y(t_mx *mx, int i, int j, t_pad *pad)
{
	if (mx->mx[i - 1][j] == BLANK || (i < mx->y && mx->mx[i][j] == BLANK))
		return (0);
	if (i == mx->y)
		return ((mx->mx[i - 1][j]) * pad->depth);
	return ((mx->mx[i][j] - mx->mx[i - 1][j]) * pad->depth);
}

static int	ft_scale_x(t_mx *mx, int i, int j, t_pad *pad)
{
	if (mx->mx[i][j - 1] == BLANK || (j < mx->x && mx->mx[i][j] == BLANK))
		return (0);
	if (j == mx->x)
		return (mx->mx[i][j - 1] * pad->depth);
	return ((mx->mx[i][j] - mx->mx[i][j - 1]) * pad->depth);
}

static void	ft_print_y(t_pad *pad, t_mx *mx, t_point origin, int *im)
{
	t_coor	c;
	int		i;
	int		j;

	j = 0;
	origin.y -= mx->mx[0][0] * pad->depth;
	while (j < mx->x)
	{
		i = 0;
		c.s.x = origin.x;
		c.s.y = origin.y;
		c.e.x = origin.x;
		while (i < mx->y - 1)
		{
			c.e.y = c.s.y + pad->pad - ft_scale_y(mx, i + 1, j, pad);
			ft_prepare_color(mx, i++, j, 'i');
			ft_fill_image(c, mx, im);
			c.s.y = c.e.y;
		}
		origin.x += pad->pad;
		j++;
		origin.y = origin.y - ft_scale_x(mx, 0, j, pad);
	}
}

static void	ft_print_x(t_pad *pad, t_mx *mx, t_point origin, int *im)
{
	t_coor	c;
	int		i;
	int		j;

	i = -1;
	while (++i < mx->y)
	{
		j = 0;
		c.s.x = origin.x;
		c.s.y = origin.y;
		if (mx->mx[i][0] != BLANK)
			c.s.y -= mx->mx[i][0] * pad->depth;
		while (j < mx->x - 1)
		{
			c.e.x = c.s.x + pad->pad;
			c.e.y = c.s.y;
			if (mx->mx[i][j + 1] != BLANK)
				c.e.y -= (mx->mx[i][j + 1] - mx->mx[i][j]) * pad->depth;
			ft_prepare_color(mx, i, j++, 'j');
			ft_fill_image(c, mx, im);
			c.s.y = c.e.y;
			c.s.x = c.e.x;
		}
		origin.y += pad->pad;
	}
}

void		ft_print_top_down(t_win *win, t_pad *pad, t_mx *mx, t_point *origin)
{
	t_image	im;

	im.im_ptr = mlx_new_image(win->mlx_ptr, W, H);
	im.im = (int *)mlx_get_data_addr(im.im_ptr, &im.bpp,
			&im.size_line, &im.endian);
	ft_print_x(pad, mx, *origin, im.im);
	ft_print_y(pad, mx, *origin, im.im);
	mlx_put_image_to_window(win->mlx_ptr, win->mlx_win, im.im_ptr, 0, 0);
	mlx_destroy_image(win->mlx_ptr, im.im_ptr);
}
