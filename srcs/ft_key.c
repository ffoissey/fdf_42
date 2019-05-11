/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 13:58:05 by ffoissey          #+#    #+#             */
/*   Updated: 2019/01/08 11:04:09 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		ft_view_key(int key, t_info *info, t_pack *pack)
{
	if (key == K_1)
		info->view = 1;
	else if (key == K_2)
		info->view = 2;
	else if (key == K_3)
		info->view = 3;
	else if (key == K_4)
		info->view = 4;
	else if (key == K_5)
		info->view = 5;
	ft_set_origin(info, pack);
}

static void		ft_other_keys(int key, t_info *info, t_pack *pack)
{
	if (key == K_G)
	{
		if (info->hud & 1)
			info->grid++;
	}
	else if (key == K_1 || key == K_2 || key == K_3 || key == K_4 || key == K_5)
		ft_view_key(key, info, pack);
	else if (key == K_H)
	{
		if ((info->hud & 1) && (info->grid & 1))
			info->grid--;
		info->hud++;
	}
}

static void		ft_red_keys(int key, t_info *info, t_pack *pack)
{
	if (key == K_W || key == K_A || key == K_S || key == K_D)
		ft_move_key(key, info);
	else if (key == K_MINUS || key == K_PLUS || key == K_X || key == K_Z)
		ft_zoom_key(key, info, pack);
	else if ((key == K_O || key == K_P) && info->view == 3)
	{
		ft_set_origin(info, pack);
		ft_angle_key(key, info, pack->mx);
	}
	else if (key == K_C || key == K_R)
		ft_center_key(key, info, pack);
}

int				ft_key_hook(int key, void *param)
{
	t_pack			*pack;
	static t_info	*info;

	pack = (t_pack *)param;
	if (!info && key != K_ENTER)
		return (0);
	if (!info)
		info = ft_set_info(pack);
	if (info->escape == 1 || key == K_ESCAPE || key == K_N || key == K_Y)
	{
		ft_escape_key(key, info, pack);
		if (info->escape == 1)
			return (2);
	}
	ft_red_keys(key, info, pack);
	ft_other_keys(key, info, pack);
	mlx_clear_window(pack->win->mlx_ptr, pack->win->mlx_win);
	ft_print_wireframes(pack->win, pack->mx, info);
	if (info->grid & 1)
		ft_grid_debug(pack->win);
	return (0);
}
