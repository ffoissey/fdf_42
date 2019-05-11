/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 13:56:13 by ffoissey          #+#    #+#             */
/*   Updated: 2019/01/08 10:56:38 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_set_color_pad(t_pack *pack)
{
	int			diff_from_zero;

	diff_from_zero = ft_abs(pack->mx->min) > pack->mx->max
					? ft_abs(pack->mx->min) : pack->mx->max;
	pack->mx->color.p = 1;
	if (diff_from_zero > 256)
	{
		while (diff_from_zero > 256)
		{
			pack->mx->color.p /= 2;
			diff_from_zero /= 2;
		}
	}
	else if (diff_from_zero)
	{
		while (diff_from_zero < 128)
		{
			pack->mx->color.p *= 2;
			diff_from_zero *= 2;
		}
	}
	else
		pack->mx->color.p = 1;
}

t_info		*ft_set_info(t_pack *pack)
{
	t_info		*info;

	if (!(info = (t_info *)malloc(sizeof(t_info))))
		return (NULL);
	ft_find_pad(pack->mx, info);
	ft_find_depth(pack->mx, info);
	info->pad.ang = 0;
	ft_set_color_pad(pack);
	info->view = 1;
	info->origin.x = W / 2 - (pack->mx->x * info->pad.pad) / 2;
	info->origin.y = H / 2 - (pack->mx->y * info->pad.pad) / 2;
	info->scale.x = 0;
	info->scale.y = 0;
	info->grid = 0;
	info->escape = 0;
	info->hud = 1;
	return (info);
}

void		ft_free_mx(t_mx *mx)
{
	int		i;

	i = 0;
	while (i < mx->y)
	{
		free(mx->mx[i]);
		mx->mx[i++] = NULL;
	}
	free(mx->mx);
	mx->mx = NULL;
}

void		ft_set_mx(t_mx *mx)
{
	mx->mx = NULL;
	mx->y = 0;
	mx->x = 1;
}

void		ft_debug_print_mx(t_mx *mx)
{
	int		y_tmp;
	int		x_tmp;

	y_tmp = 0;
	while (y_tmp < mx->y)
	{
		x_tmp = 0;
		while (x_tmp < mx->x)
		{
			ft_putnbr(mx->mx[y_tmp][x_tmp++]);
			ft_putstr(" ");
		}
		ft_putchar('\n');
		y_tmp++;
	}
}
