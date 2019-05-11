/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 14:05:27 by ffoissey          #+#    #+#             */
/*   Updated: 2019/01/07 16:59:29 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_move_key(int key, t_info *info)
{
	if (key == K_W)
	{
		info->origin.y -= info->pad.pad;
		info->scale.y--;
	}
	else if (key == K_A)
	{
		info->origin.x -= info->pad.pad;
		info->scale.x--;
	}
	else if (key == K_S)
	{
		info->origin.y += info->pad.pad;
		info->scale.y++;
	}
	else if (key == K_D)
	{
		info->origin.x += info->pad.pad;
		info->scale.x++;
	}
}

void	ft_zoom_key(int key, t_info *info, t_pack *pack)
{
	if (key == K_MINUS && info->pad.pad >= 2)
		info->pad.pad -= 2;
	else if (key == K_PLUS)
		info->pad.pad += 2;
	else if (key == K_Z && info->pad.depth >= 2)
		info->pad.depth -= 2;
	else if (key == K_X)
		info->pad.depth += 2;
	ft_set_origin(info, pack);
}

void	ft_escape_key(int key, t_info *info, t_pack *pack)
{
	if (key == K_ESCAPE)
	{
		mlx_clear_window(pack->win->mlx_ptr, pack->win->mlx_win);
		ft_print_center(pack->win, "ARE YOU SURE ?", -50, WHITE);
		mlx_string_put(pack->win->mlx_ptr, pack->win->mlx_win, W / 2 - 200,
				H / 2 - 11 + 50, GREEN, "YES (Y)");
		mlx_string_put(pack->win->mlx_ptr, pack->win->mlx_win, W / 2 + 140,
				H / 2 - 11 + 50, RED, "NO (N)");
		info->escape = 1;
	}
	if (key == K_N && info->escape == 1)
	{
		info->escape = 0;
		return ;
	}
	else if (key == K_Y && info->escape == 1)
	{
		ft_free_mx(pack->mx);
		free(info);
		info = NULL;
		ft_exit(NULL, 0, 0, pack->win);
	}
}

void	ft_angle_key(int key, t_info *info, t_mx *mx)
{
	(void)mx;
	if (key == K_O)
		info->pad.ang -= PAD_ANG;
	else if (key == K_P)
		info->pad.ang += PAD_ANG;
}

void	ft_center_key(int key, t_info *info, t_pack *pack)
{
	info->scale.x = 0;
	info->scale.y = 0;
	if (key == K_R)
	{
		info->pad.pad = info->o_pad.pad;
		info->pad.depth = info->o_pad.depth;
		info->pad.ang = 0;
	}
	ft_set_origin(info, pack);
}
