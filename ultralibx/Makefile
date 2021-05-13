.PHONY:			all clean fclean re

LIBFT = libft.a

NAME = libftprintf.a

SRCS =  ft_printf.c ft_parser.c ft_parser_utils.c	\
		ft_put_c.c ft_put_d.c ft_put_d_utilc.c		\
		ft_put_p.c ft_put_s.c ft_put_u.c ft_put_x.c \
		ft_put_u_included.c ft_put_u_utilc.c					\
		ft_put_x_included.c ft_put_x_utilc.c					\
		ft_put_p_included.c ft_put_p_utilc.c					\
		putmaket_utils.c ft_put_d_undersize.c

OBJ_DIR = ./obj/

CC = gcc

CFLAGS = -Wall -Wextra -Werror

OBJS = $(SRCS:%.c=%.o)

OBJS_FILES = $(addprefix $(OBJ_DIR), $(OBJS))

PATH_PUT_UTILS = put_d put_p put_u put_x

PATH_MAKER = $(addprefix srcs/putchar_maker/, $(PATH_PUT_UTILS))

vpath %.c srcs srcs/parser srcs/putchar_maker $(PATH_MAKER)

vpath %.a ./libft

all : $(OBJ_DIR) $(NAME)


$(OBJ_DIR):
	mkdir -p obj

$(NAME): $(LIBFT) $(OBJS_FILES)
	ar -rcs $(NAME) $(filter %.o, $^)

$(LIBFT): ./libft/src/*.c
	$(MAKE) all -C ./libft
	cp libft/libft.a $(NAME)

$(OBJ_DIR)%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -I. -MMD -c $< -o $@

-include $(OBJS:.o=.d)

norme:
	norminetteV2 $(SRCS)

clean :
	@$(MAKE) clean -C ./libft
	rm -rf $(OBJS_FILES)
	rm -rf obj

fclean : clean
	make fclean -C ./libft
	rm -rf $(NAME)

re : fclean all
