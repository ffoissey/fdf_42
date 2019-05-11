/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_origin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 16:27:11 by ffoissey          #+#    #+#             */
/*   Updated: 2019/01/08 16:43:33 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_set_origin(t_info *info, t_pack *pack)
{
	if (info->view == 1 || info->view == 4)
	{
		info->origin.x = W / 2 - (pack->mx->x * info->pad.pad) / 2;
		info->origin.y = H / 2 - (pack->mx->y * info->pad.pad) / 2;
	}
	else if (info->view == 2)
	{
		info->origin.y = H / 2 + (pack->mx->diff * info->pad.depth) / 4;
		info->origin.x = W / 2 - (pack->mx->x * info->pad.pad) / 2;
	}
	else if (info->view == 3)
	{
		info->origin.y = H / 2 - (info->pad.pad * pack->mx->y) / 2;
		info->origin.x = W / 2 + (pack->mx->x * cos(ANGLE_ISO)) / 2;
	}
	else if (info->view == 5)
	{
		info->origin.y = H / 2
						- (info->pad.pad * pack->mx->y * sin(ANGLE_ISO) / 2);
		info->origin.x = W / 2;
	}
	info->origin.x += info->scale.x * info->pad.pad;
	info->origin.y += info->scale.y * info->pad.pad;
}
