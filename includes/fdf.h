/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 14:12:05 by ffoissey          #+#    #+#             */
/*   Updated: 2019/01/08 16:16:47 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include <math.h>
# include <errno.h>
# include <stdio.h>
# include "mlx.h"
# include "libft.h"
# include "define.h"
# include "struct.h"

void			ft_set_mx(t_mx *mx);
void			ft_set_origin(t_info *info, t_pack *pack);
void			ft_print_line(t_coor c, int color, t_win *win);
int				ft_abs(int nb);
t_info			*ft_set_info(t_pack *pack);
int				ft_set_color(int nb, float pad_color);
int				ft_init_color(unsigned char red, unsigned char green,
				unsigned char blue);
void			ft_print_wireframes(t_win *win, t_mx *mx, t_info *info);
void			ft_grid_debug(t_win *win);
void			ft_print_iso(t_win *win, t_pad *pad, t_mx *mx, t_point *origin);
void			ft_print_par(t_win *win, t_pad *pad, t_mx *mx, t_point *origin);
void			ft_print_top_down(t_win *win, t_pad *pad,
				t_mx *mx, t_point *origin);
void			ft_print_plan(t_win *win, t_pad *pad, t_mx *mx,
				t_point *origin);
void			ft_print_elevation(t_win *win, t_pad *pad, t_mx *mx,
				t_point origin);
void			ft_parse_map(const int fd, t_mx *mx, t_win *win);
void			ft_free_mx(t_mx *mx);
void			ft_hud(t_win *win, t_info *info);
void			ft_debug_print_mx(t_mx *mx);
int				ft_key_hook(int key, void *param);
void			ft_print_center(t_win *win, char *s, int h_origin, int color);
void			ft_move_key(int key, t_info *info);
void			ft_zoom_key(int key, t_info *info, t_pack *pack);
void			ft_center_key(int key, t_info *info, t_pack *pack);
void			ft_escape_key(int key, t_info *info, t_pack *pack);
void			ft_angle_key(int key, t_info *info, t_mx *mx);
void			ft_free_mx(t_mx *mx);
int				ft_center_text(int start_pos, int size_elem, char *s,
				char w_or_h);
char			*ft_transform_str(char *src, t_win *win);
void			ft_find_pad(t_mx *mx, t_info *info);
void			ft_find_depth(t_mx *mx, t_info *info);
void			ft_fill_image(t_coor c, t_mx *mx, int *im);
void			ft_prepare_color(t_mx *mx, int i, int j, char i_or_j);
void			ft_debug_print_mx(t_mx *mx);
void			ft_set_value(t_coor *c, t_line *l);
char			*ft_read_all_str(int fd, t_win *win);
void			ft_exit(char *s, int p, int err, t_win *win);
int				ft_arr(float nb);
void			ft_prepare_color_par(t_mx *mx, int i, int j);
void			ft_print_y_par(t_ref *r, int j, t_coor *c);
void			ft_print_x_par(t_ref *r, int i, t_coor *c);

#endif
