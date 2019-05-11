/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 14:15:51 by ffoissey          #+#    #+#             */
/*   Updated: 2019/01/07 15:05:32 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			main(int ac, char **av)
{
	t_win	win;
	int		fd;
	t_mx	mx;
	t_pack	pack;

	if (ac != 2)
		return (1);
	fd = open(av[1], O_RDONLY);
	win.mlx_ptr = mlx_init();
	win.mlx_win = mlx_new_window(win.mlx_ptr, W, H, NAME);
	ft_parse_map(fd, &mx, &win);
	close(fd);
	ft_print_center(&win, "PRESS ENTER TO START", 0, WHITE);
	pack.win = &win;
	pack.mx = &mx;
	mlx_key_hook(win.mlx_win, ft_key_hook, &pack);
	mlx_loop(win.mlx_ptr);
	ft_free_mx(&mx);
	free(win.mlx_ptr);
	free(win.mlx_win);
	return (0);
}
