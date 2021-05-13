.PHONY:			all clean fclean re

SRCS			=	ft_isalnum.c ft_isprint.c ft_memcmp.c  ft_putchar_fd.c ft_split.c \
					ft_strlcat.c ft_strncmp.c ft_substr.c ft_atoi.c ft_isalpha.c \
					ft_itoa.c ft_memcpy.c  ft_putendl_fd.c ft_strchr.c  ft_strlcpy.c \
					ft_strnstr.c ft_tolower.c ft_bzero.c   ft_isascii.c ft_memccpy.c \
					ft_memmove.c ft_putnbr_fd.c  ft_strdup.c  ft_strlen.c  ft_strrchr.c \
					ft_toupper.c ft_calloc.c  ft_isdigit.c ft_memchr.c  ft_memset.c  \
					ft_putstr_fd.c  ft_strjoin.c ft_strmapi.c ft_strtrim.c ft_putchar.c\
					ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c \
					ft_lstdelone.c ft_lstiter.c ft_lstlast.c \
					ft_lstmap.c ft_lstnew.c ft_lstsize.c\
					get_next_line.c get_next_line_utils.c

SRC_DIR = ./src/
OBJ_DIR = ./obj/

OBJS			= $(SRCS:%.c=%.o)

OBJS_FILES = $(addprefix $(OBJ_DIR), $(OBJS))

HEADER = libft.h

vpath %.h includes
vpath %.o $(OBJ_DIR)
vpath %.c $(SRC_DIR)

CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -I ./includes/

NAME			= libft.a

all:	$(OBJ_DIR) $(NAME)

norme :
	norminette  $(addprefix $(SRC_DIR), $(SRCS))

$(OBJ_DIR):
	mkdir -p obj

$(NAME):		$(OBJS_FILES)
				ar rcs $@ $?

clean:
				$(RM) $(OBJS_FILES)

$(OBJ_DIR)%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)
