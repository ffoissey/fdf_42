/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pad.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 17:06:21 by ffoissey          #+#    #+#             */
/*   Updated: 2018/12/17 14:56:44 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_min_pad_hi(t_info *info, int size, int count)
{
	while ((size /= 2) > PAD_HI)
		count++;
	if (PAD_HI - count > 1)
	{
		info->pad.depth = PAD_HI - count;
		info->o_pad.depth = PAD_HI - count;
	}
	else
	{
		info->pad.depth = 1;
		info->o_pad.depth = 1;
	}
}

static void	ft_min_pad(t_info *info, int size, int count)
{
	while ((size /= 2) > PAD)
		count++;
	if (PAD - count > 1)
	{
		info->pad.pad = PAD - count;
		info->o_pad.pad = PAD - count;
	}
	else
	{
		info->pad.pad = 1;
		info->o_pad.pad = 1;
	}
}

void		ft_find_pad(t_mx *mx, t_info *info)
{
	int		size;
	int		count;

	count = 0;
	if (mx->x > mx->y)
		size = mx->x;
	else
		size = mx->y;
	if (size < PAD)
	{
		while ((size *= 2) < PAD)
			count++;
		info->pad.pad = PAD + count;
		info->o_pad.pad = PAD + count;
	}
	else
		ft_min_pad(info, size, count);
}

void		ft_find_depth(t_mx *mx, t_info *info)
{
	int		size;
	int		count;

	count = 0;
	size = mx->diff;
	if (size < PAD_HI)
	{
		while (size++ < PAD_HI)
			count++;
		info->pad.depth = PAD_HI + count;
		info->o_pad.depth = PAD_HI + count;
	}
	else
		ft_min_pad_hi(info, size, count);
}
