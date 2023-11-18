# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/04 19:10:12 by mcatalan@st       #+#    #+#              #
#    Updated: 2023/11/18 11:40:41 by mcatalan@st      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT_D = libft/
LIBFT = libft.a

FT_PRINTF_D = ft_printf/
FT_PRINTF = libftprintf.a

NSERVER = push_swap

SRCS =	src/push_swap.c						\
		src/push_start.c					\
		src/push_moves.c					\
		src/utils.c							\
		src/utils2.c						\
		src/sort.c							\
		src/operations/push.c				\
		src/operations/reverse_rotation.c	\
		src/operations/rotate.c				\
		src/operations/swap.c				\
		

OBJS = $(SRCS:.c=.o)

DEPS = $(SRCS:.c=.d)

INCLUDE = -I./
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

all: makelibft $(NSERVER)

makelibft:
	@make --no-print-directory -C $(LIBFT_D)

makeftprintf:
	@make --no-print-directory -C $(FT_PRINTF_D)

%.o: %.c
	${CC} ${CFLAGS} -MMD $(INCLUDE) -c $< -o $@

$(NSERVER): $(OBJS) $(LIBFT_D)$(LIBFT) $(FT_PRINTF_D)$(FT_PRINTF)
	$(CC) $(CFLAGS) $(OBJS) -o $@ $(LIBFT_D)$(LIBFT) $(FT_PRINTF_D)$(FT_PRINTF)
-include $(DEPS)

clean:
	@make clean --no-print-directory -C $(LIBFT_D)
	@make clean --no-print-directory -C $(FT_PRINTF_D)
	$(RM) $(OBJS) $(DEPS)

fclean: clean
	$(RM) $(NSERVER) $(DEPS)

re: fclean all

.PHONY: all clean fclean re makelibft makeftprintf