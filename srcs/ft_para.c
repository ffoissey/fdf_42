/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_para.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 15:51:33 by ffoissey          #+#    #+#             */
/*   Updated: 2019/01/08 16:44:01 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_print_y(t_pad *pad, t_mx *mx, t_point origin, int *im)
{
	t_coor	c;
	t_ref	r;
	int		j;

	r.pad = pad;
	r.mx = mx;
	r.im = im;
	c.s.x = origin.x;
	j = -1;
	while (++j < mx->x)
	{
		c.s.x = origin.x;
		c.s.y = mx->mx[0][j] != BLANK
			? origin.y - mx->mx[0][j] * pad->depth : origin.y;
		c.e.y = c.s.y;
		c.e.x = c.s.x;
		ft_print_y_par(&r, j, &c);
		origin.x += pad->pad;
	}
}

static void	ft_print_x(t_pad *pad, t_mx *mx, t_point origin, int *im)
{
	t_coor	c;
	t_ref	r;
	int		i;

	i = 0;
	r.pad = pad;
	r.mx = mx;
	r.im = im;
	c.s.y = origin.y;
	c.s.x = origin.x;
	while (i < mx->y)
	{
		c.s.y = origin.y;
		c.s.x = origin.x;
		if (mx->mx[i][0] != BLANK)
			c.s.y -= mx->mx[i][0] * pad->depth;
		c.e.x = c.s.x;
		c.e.y = c.s.y;
		ft_print_x_par(&r, i, &c);
		origin.y = ft_arr(origin.y + pad->pad * sin(ANGLE_ISO));
		origin.x = ft_arr(origin.x - pad->pad * cos(ANGLE_ISO));
		i++;
	}
}

void		ft_print_par(t_win *win, t_pad *pad, t_mx *mx, t_point *origin)
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
