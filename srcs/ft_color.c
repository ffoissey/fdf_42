/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 14:13:32 by ffoissey          #+#    #+#             */
/*   Updated: 2019/01/11 11:12:02 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			ft_init_color(unsigned char red, unsigned char green,
			unsigned char blue)
{
	return (65536 * red + 256 * green + blue);
}

int			ft_set_color(int nb, float pad_color)
{
	(void)pad_color;
	if (nb == BLANK)
		return (BLACK);
	if (nb < 0)
		return (ft_init_color(0, 128, -nb % 256));
	else if (nb > 0)
		return (ft_init_color(nb % 256, 128, 0));
	return (ft_init_color(0, 128, 0));
}

void		ft_prepare_color(t_mx *mx, int i, int j, char i_or_j)
{
	mx->color.step = 0;
	mx->color.s = mx->mx[i][j] == BLANK ? mx->mx[i][j]
				: mx->mx[i][j] * mx->color.p;
	if (i_or_j == 'j')
		mx->color.e = mx->mx[i][j + 1] == BLANK ? mx->mx[i][j + 1]
					: mx->mx[i][j + 1] * mx->color.p;
	else
		mx->color.e = mx->mx[i + 1][j] == BLANK ? mx->mx[i + 1][j]
					: mx->mx[i + 1][j] * mx->color.p;
	if (mx->color.s == BLANK || mx->color.e == BLANK)
		mx->color.e = mx->color.s;
	if (mx->color.s < mx->color.e)
		mx->color.inc = 1;
	else
		mx->color.inc = -1;
	mx->color.scale = fabs(mx->color.e - mx->color.s);
}

void		ft_prepare_color_par(t_mx *mx, int i, int j)
{
	mx->color.step = 0;
	mx->color.s = mx->mx[i][j] == BLANK ? mx->mx[i][j]
				: mx->mx[i][j] * mx->color.p;
	mx->color.e = mx->mx[i][j] == BLANK ? mx->mx[i][j]
				: mx->mx[i][j] * mx->color.p;
	mx->color.inc = 1;
	mx->color.scale = fabs(mx->color.e - mx->color.s);
}
