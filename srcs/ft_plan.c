/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_plan.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 11:49:20 by ffoissey          #+#    #+#             */
/*   Updated: 2019/01/07 15:42:28 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_print_y(t_pad *pad, t_mx *mx, t_point *origin, int *im)
{
	t_coor	c;
	int		i;
	int		j;

	c.s.x = origin->x;
	j = 0;
	while (j < mx->x)
	{
		c.s.y = origin->y;
		c.e.x = c.s.x;
		i = 0;
		while (i < mx->y - 1)
		{
			c.e.y = c.s.y + pad->pad;
			ft_prepare_color(mx, i, j, 'i');
			ft_fill_image(c, mx, im);
			i++;
			c.s.y += pad->pad;
		}
		c.s.x += pad->pad;
		j++;
	}
}

static void	ft_print_x(t_pad *pad, t_mx *mx, t_point *origin, int *im)
{
	t_coor	c;
	int		i;
	int		j;

	c.s.y = origin->y;
	i = 0;
	while (i < mx->y)
	{
		c.s.x = origin->x;
		c.e.y = c.s.y;
		j = 0;
		while (j < mx->x - 1)
		{
			c.e.x = c.s.x + pad->pad;
			ft_prepare_color(mx, i, j, 'j');
			ft_fill_image(c, mx, im);
			j++;
			c.s.x += pad->pad;
		}
		c.s.y += pad->pad;
		i++;
	}
}

void		ft_print_plan(t_win *win, t_pad *pad, t_mx *mx, t_point *origin)
{
	t_image	im;

	im.im_ptr = mlx_new_image(win->mlx_ptr, W, H);
	im.im = (int *)mlx_get_data_addr(im.im_ptr, &im.bpp,
			&im.size_line, &im.endian);
	ft_print_x(pad, mx, origin, im.im);
	ft_print_y(pad, mx, origin, im.im);
	mlx_put_image_to_window(win->mlx_ptr, win->mlx_win, im.im_ptr, 0, 0);
	mlx_destroy_image(win->mlx_ptr, im.im_ptr);
}
