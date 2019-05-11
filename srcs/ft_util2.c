/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 14:35:22 by ffoissey          #+#    #+#             */
/*   Updated: 2019/01/07 18:34:59 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_print_center(t_win *win, char *s, int h_origin, int color)
{
	char	*str;
	size_t	len;
	int		h;
	int		w;

	if (!(str = ft_strdup(s)))
		return ;
	len = ft_strlen(str);
	w = W / 2 - (len * 5);
	h = H / 2 - 11 + h_origin;
	mlx_string_put(win->mlx_ptr, win->mlx_win, w, h, color, str);
	ft_strdel(&str);
}

int			ft_center_text(int start_pos, int size_elem, char *s, char w_or_h)
{
	if (w_or_h == 'w')
		return (size_elem / 2 - (ft_strlen(s) * 5) + start_pos);
	else
		return (size_elem / 2 - 11 + start_pos);
}

void		ft_exit(char *s, int p, int err, t_win *win)
{
	if (p)
		perror(s);
	else
		ft_putendl_fd(s, 2);
	exit(err);
	free(win->mlx_ptr);
	free(win->mlx_win);
}

int			ft_abs(int nb)
{
	return ((nb < 0) ? -nb : nb);
}

int			ft_arr(float nb)
{
	return (nb < 0 ? nb - 1 : nb);
}
