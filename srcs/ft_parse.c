/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 18:07:33 by ffoissey          #+#    #+#             */
/*   Updated: 2019/01/07 19:16:03 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_max_min_value(t_mx *mx)
{
	int		y_tmp;
	int		x_tmp;

	mx->max = mx->mx[0][0];
	mx->min = mx->mx[0][0];
	y_tmp = -1;
	while (++y_tmp < mx->y)
	{
		x_tmp = -1;
		while (++x_tmp < mx->x)
		{
			if (mx->mx[y_tmp][x_tmp] != BLANK)
			{
				if (mx->min > mx->mx[y_tmp][x_tmp])
					mx->min = mx->mx[y_tmp][x_tmp];
				if (mx->max < mx->mx[y_tmp][x_tmp])
					mx->max = mx->mx[y_tmp][x_tmp];
			}
		}
	}
	if ((mx->max >= 0 && mx->min >= 0) || (mx->max <= 0 && mx->min <= 0))
		mx->diff = abs(mx->max - mx->min);
	else
		mx->diff = abs(mx->max) + abs(mx->min);
}

static void	ft_free_tabstr(char **tab)
{
	int		i;

	i = 0;
	if (!tab)
		return ;
	while (tab[i])
	{
		free(tab[i]);
		tab[i] = NULL;
		i++;
	}
	free(tab);
	tab = NULL;
}

static void	ft_fill_mx(t_mx *mx, char *s, t_win *win)
{
	int		i;
	int		j;
	char	**tab_line;
	char	**tab_space;

	i = 0;
	if (!(tab_line = ft_strsplit(s, '\n')) || !(tab_line[0]))
		ft_exit("Error malloc", 0, 1, win);
	while (i < mx->y && tab_line && tab_line[i])
	{
		j = 0;
		if (!(tab_space = ft_strsplit(tab_line[i], ' ')))
			ft_exit("Error malloc", 0, 1, win);
		while (tab_space && tab_space[j] && j < mx->x)
		{
			mx->mx[i][j] = ft_atoi(tab_space[j]);
			j++;
		}
		while (j < mx->x)
			mx->mx[i][j++] = BLANK;
		ft_free_tabstr(tab_space);
		i++;
	}
	ft_free_tabstr(tab_line);
}

static void	ft_size_mx(char *s, t_mx *mx)
{
	int		i;
	int		tmp_x;

	i = 0;
	while (s[i])
	{
		tmp_x = 1;
		mx->y++;
		while (s[i] == ' ')
			i++;
		while (s[i] != '\n' && s[i] != '\0')
		{
			if (s[i] == ' ' && (s[i + 1] != '\0' && s[i + 1] != '\n'))
			{
				tmp_x++;
				while (s[i] == ' ')
					i++;
			}
			else
				i++;
		}
		if (tmp_x > mx->x)
			mx->x = tmp_x;
		s[i] ? i++ : i;
	}
}

void		ft_parse_map(const int fd, t_mx *mx, t_win *win)
{
	char		*str_all;
	int			i;

	str_all = ft_transform_str(ft_read_all_str(fd, win), win);
	ft_set_mx(mx);
	ft_size_mx(str_all, mx);
	if (mx->y <= 0 || mx->x <= 0
		|| !(mx->mx = (int **)malloc(sizeof(int *) * mx->y)))
		ft_exit("malloc", 1, errno, win);
	i = -1;
	while (++i < mx->y)
	{
		if (mx->mx && !(mx->mx[i] = (int *)malloc(sizeof(int) * mx->x)))
		{
			mx->x = i;
			if (mx->x != 0)
				mx->x = i - 1;
			ft_free_mx(mx);
			ft_exit("malloc", 1, errno, win);
		}
	}
	ft_fill_mx(mx, str_all, win);
	ft_max_min_value(mx);
	ft_strdel(&str_all);
}
