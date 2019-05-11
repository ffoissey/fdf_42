/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wireframes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 14:14:57 by ffoissey          #+#    #+#             */
/*   Updated: 2019/01/08 11:05:30 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_grid_debug(t_win *win)
{
	int		i;

	mlx_string_put(win->mlx_ptr, win->mlx_win, W - 12, (H / 2) - 20, RED, "x");
	mlx_string_put(win->mlx_ptr, win->mlx_win, (W / 2) + 5, H - 25, RED, "y");
	i = W;
	while (i)
		mlx_pixel_put(win->mlx_ptr, win->mlx_win, i--, H / 2, WHITE);
	i = H;
	while (i > 50)
		mlx_pixel_put(win->mlx_ptr, win->mlx_win, W / 2, i--, WHITE);
}

void		ft_print_wireframes(t_win *win, t_mx *mx, t_info *info)
{
	if (info->view == 1)
		ft_print_plan(win, &info->pad, mx, &info->origin);
	else if (info->view == 2)
		ft_print_elevation(win, &info->pad, mx, info->origin);
	else if (info->view == 3)
		ft_print_iso(win, &info->pad, mx, &info->origin);
	else if (info->view == 4)
		ft_print_top_down(win, &info->pad, mx, &info->origin);
	else
		ft_print_par(win, &info->pad, mx, &info->origin);
	if (info->hud & 1)
		ft_hud(win, info);
}
