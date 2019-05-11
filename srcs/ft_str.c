/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 15:52:10 by ffoissey          #+#    #+#             */
/*   Updated: 2019/01/08 16:43:34 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static char	*ft_double_space(char *s, t_win *win)
{
	int		i;
	int		c;
	char	*new;
	int		size;

	i = -1;
	c = 0;
	while (s[++i])
		if (s[i] && ((s[i] == '\n' && s[i + 1] == '\n')
			|| (s[i] == ' ' && s[i + 1] == ' ')))
			c++;
	size = i - c;
	if (size < 0)
		ft_exit("Error malloc or file", 0, 1, win);
	new = (char *)ft_strnew(size);
	i = 0;
	while (*s && size--)
	{
		if (*s && ((*s == '\n' && *(s + 1) == '\n')
			|| (*s == ' ' && *(s + 1) == ' ')))
			s++;
		new[i++] = *s;
		*s ? s++ : s;
	}
	return (new);
}

static char	*ft_clear_str(char *s, int i, t_win *win)
{
	char	*new;

	new = NULL;
	if (!(new = ft_strdup(s + i)) || !*new)
		ft_exit("Bad file format", 0, 2, win);
	ft_strdel(&s);
	if (!(s = ft_double_space(new, win)) || !*s)
		ft_exit("Bad file format", 0, 2, win);
	ft_strdel(&new);
	return (s);
}

char		*ft_transform_str(char *s, t_win *win)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	while (s[i] && s[i] != '-' && (s[i] < '0' || s[i] > '9'))
		i++;
	j = i;
	while (s[j])
	{
		k = j - 1;
		while (s[++k] && ((s[k] != '-' && (s[k] < '0' || s[k] > '9')
				&& s[k] != '\n' && s[k] != ' ') || (s[k] == ' '
				&& s[k + 1] == ' ') || (s[k] == '\n' && s[k + 1] == '\n')))
		{
			if (s[k] == ',')
				while (s[k] && s[k + 1] != ' ' && s[k + 1] != '\n')
					k++;
		}
		if (k - j != 0)
			ft_strcpy(s + j, s + k);
		else
			j++;
	}
	return (ft_clear_str(s, i, win));
}

char		*ft_read_all_str(int fd, t_win *win)
{
	int		ret;
	char	buf[BUFF_SIZE + 1];
	char	*str;
	char	*tmp_str;

	str = NULL;
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		tmp_str = str;
		str = ft_strjoin(str, buf);
		ft_strdel(&tmp_str);
	}
	if (ret == -1)
		ft_exit("read", 1, errno, win);
	if (!str)
		ft_exit("Empty file", 0, 1, win);
	return (ret == -1 ? NULL : str);
}
