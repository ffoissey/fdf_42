# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ffoissey <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/05 18:25:23 by ffoissey          #+#    #+#              #
#    Updated: 2019/03/19 12:41:15 by ffoissey         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
FILE = fdf wireframes color parse print_line iso plan elevation hud origin	\
	   util util2 key key_2 top_down str pad fill_image para para2
LIBFT = libft/libft.a
SRCS = $(patsubst %,srcs/ft_%.c,$(FILE))
OBJS = $(patsubst %,ft_%.o,$(FILE))
INCLUDES_MLX = -I /usr/local/include
INCLUDES += -I includes/
INCLUDES += -I libft/includes
INCLUDES += -I libft/includes/ft_printf
INCLUDES += -I libft/includes/get_next_line
LIBPATH = /usr/local/lib/
FRAMEWORK = -framework OpenGL -framework AppKit
HEAD = includes/fdf.h includes/define.h includes/struct.h
CFLAGS = -Wall -Werror -Wextra
HARDFLAGS = -Wall -Werror -Wextra -fsanitize=address,undefined -g3 -g
CC = clang

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(INCLUDES_MLX) \
	-L $(LIBPATH) -lmlx $(FRAMEWORK) -o $@

$(LIBFT):
	make -C libft/

%.o: srcs/%.c $(HEAD)
	$(CC) $(CFLAGS) -c $< $(INCLUDES) $(INCLUDES_MLX) 

clean:
	rm -f $(OBJS) && make -C libft clean

fclean: clean
	rm -f $(NAME) && make -C libft fclean

re: fclean all

.PHONY: clean fclean re all
