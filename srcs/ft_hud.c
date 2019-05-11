/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hud.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 14:07:44 by ffoissey          #+#    #+#             */
/*   Updated: 2019/01/08 16:28:54 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			ft_set_coor(t_coor *c, int x, int y, char s_or_e)
{
	if (s_or_e == 's')
	{
		c->s.x = x;
		c->s.y = y;
	}
	else
	{
		c->e.x = x;
		c->e.y = y;
	}
}

static void		ft_print_keys(t_win *win)
{
	int		w;

	w = ft_center_text(W - 200, 180, "KEYS", 'w');
	mlx_string_put(win->mlx_ptr, win->mlx_win, w, 25, WHITE, "KEYS");
	mlx_string_put(win->mlx_ptr, win->mlx_win, W - 185, 55, RED, "MOVE");
	mlx_string_put(win->mlx_ptr, win->mlx_win, W - 65, 47, RED, "w");
	mlx_string_put(win->mlx_ptr, win->mlx_win, W - 85, 61, RED, "a s d");
	mlx_string_put(win->mlx_ptr, win->mlx_win, W - 185, 75, RED, ZOOM);
	mlx_string_put(win->mlx_ptr, win->mlx_win, W - 185, 95, RED, DEPTH);
	mlx_string_put(win->mlx_ptr, win->mlx_win, W - 185, 115, RED, ROT);
	mlx_string_put(win->mlx_ptr, win->mlx_win, W - 185, 135, RED, CENTER);
	mlx_string_put(win->mlx_ptr, win->mlx_win, W - 185, 165, MAGENTA, VIEW);
	mlx_string_put(win->mlx_ptr, win->mlx_win, W - 185, 195, GREEN, GRID);
	mlx_string_put(win->mlx_ptr, win->mlx_win, W - 185, 215, GREEN, HUD);
	mlx_string_put(win->mlx_ptr, win->mlx_win, W - 185, 235, GREEN, RESET);
	mlx_string_put(win->mlx_ptr, win->mlx_win, W - 185, 265, CYAN, ESCAPE);
}

static void		ft_square(t_win *win)
{
	t_coor	c;

	ft_set_coor(&c, W - 20, 20, 's');
	ft_set_coor(&c, W - 20, 300, 'e');
	ft_print_line(c, WHITE, win);
	ft_set_coor(&c, W - 200, 20, 'e');
	ft_print_line(c, WHITE, win);
	ft_set_coor(&c, W - 200, 300, 's');
	ft_print_line(c, WHITE, win);
	ft_set_coor(&c, W - 20, 300, 'e');
	ft_print_line(c, WHITE, win);
	ft_set_coor(&c, W / 2 - 480, 0, 's');
	ft_set_coor(&c, W / 2 - 480, 50, 'e');
	ft_print_line(c, WHITE, win);
	ft_set_coor(&c, W / 2 + 480, 50, 's');
	ft_print_line(c, WHITE, win);
	ft_set_coor(&c, W / 2 + 480, 0, 'e');
	ft_print_line(c, WHITE, win);
}

static void		ft_print_view(void *mlx_ptr, void *mlx_win, int view)
{
	int	w;
	int	tab[5];

	w = W / 2;
	tab[0] = RED;
	tab[1] = RED;
	tab[2] = RED;
	tab[3] = RED;
	tab[4] = RED;
	tab[view - 1] = GREEN;
	mlx_string_put(mlx_ptr, mlx_win, w - 450, 20, tab[0], PLAN);
	mlx_string_put(mlx_ptr, mlx_win, w - 300, 20, tab[1], ELEV);
	mlx_string_put(mlx_ptr, mlx_win, w - 100, 20, tab[2], ISO);
	mlx_string_put(mlx_ptr, mlx_win, w + 95, 20, tab[3], TD);
	mlx_string_put(mlx_ptr, mlx_win, w + 280, 20, tab[4], PAR);
}

void			ft_hud(t_win *win, t_info *info)
{
	char	*s;
	t_pad	pad;

	ft_print_view(win->mlx_ptr, win->mlx_win, info->view);
	pad.pad = info->pad.pad / 2 + info->pad.pad % 2;
	pad.depth = info->pad.depth / 2 + info->pad.depth % 2;
	mlx_string_put(win->mlx_ptr, win->mlx_win, 20, 20, WHITE, "Pad =");
	s = ft_itoa(pad.pad);
	mlx_string_put(win->mlx_ptr, win->mlx_win, 78, 20, WHITE, s);
	ft_strdel(&s);
	mlx_string_put(win->mlx_ptr, win->mlx_win, 20, 50, WHITE, "Depth =");
	s = ft_itoa(pad.depth);
	mlx_string_put(win->mlx_ptr, win->mlx_win, 95, 50, WHITE, s);
	ft_strdel(&s);
	ft_square(win);
	ft_print_keys(win);
}
