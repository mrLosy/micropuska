# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: haristot <haristot@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/13 16:45:09 by haristot          #+#    #+#              #
#    Updated: 2021/04/29 05:10:09 by haristot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

BIN = $(shell mkdir -p bin)

SRCS_DIR = srcs/

BIN_DIR = bin/

DSRCS = bin/*.d

SRCS =  minishell.c\
		main_part.c\
		minishell_utilc.c\
		parser.c\
		minishelldenis.c\
		utils.c\
		parser_echo.c \
		parser_cd.c\
		parser_env.c\
		parser_export.c\
		parser_unset.c\
		parser_pwd.c\
		parser_another_com.c\
		setedit.c\
		pipes.c\
		minishell_utils_2.c\
		minishell_utilc3.c\
		minishell_utilc4.c\
		minishell_utilc5.c\
		minishell_utilc6.c\
		minishelldenis2.c\
		minishelldenis3.c\
		parser_exit.c\
		parser_slash.c\
		parser_dollar.c\
		dollar_utils.c\
		utils_parser.c\
		echo_utils.c\
		echo_utils_sec.c\
		free_null.c\
		finish_free.c\
		utils_project.c\
		utils_project_sec.c\
		utilc2.c\
		utilc3.c



OBJSRCS = $(addprefix $(BIN_DIR), $(SRCS:.c=.o))

DSRCS = $(addprefix $(BIN_DIR), SRCS:.c=.d)

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g

INCLUDES = ./includes/minishell.h ./includes/minishelldenis.h ./ultralibx/ft_printf.h

all :
	$(MAKE) $(NAME) $(BIN) -j 12

$(BIN_DIR)%.o: $(SRCS_DIR)%.c $(INCLUDES)
	$(CC) $(CFLAGS) -MMD -c $< -o $@

-include $(OBJSRCS:.o=.d)

$(NAME) : $(OBJSRCS)
	@echo "\033[0;36m[Deleting the previous minishell...]"
	@rm -rf minishell
	@echo "\033[0;36m[Ultralibx compilation...]"
	@$(MAKE) -C ./ultralibx
	@echo "\033[0;36m[Minishell compilation...]"
	# -fsanitize=address
	$(CC) $(CFLAGS) $(OBJSRCS) -I./include ./ultralibx/libftprintf.a -ltermcap -o $(NAME)
	# @echo "													 Made by : \033[1;91mharistot && mdenys\033[m"
	# @echo "      ___                       ___                       ___           ___           ___                                     "
	# @echo "     /__/\        ___          /__/\        ___          /  /\         /__/\         /  /\     ___             ___            "
	# @echo "    |  |::\      /  /\         \  \:\      /  /\        /  /:/_        \  \:\       /  /:/_   /__/\           /__/\           "
	# @echo "    |  |:|:\    /  /:/          \  \:\    /  /:/       /  /:/ /\        \__\:\     /  /:/ /\  \  \:\     ___  \  \:\     ___  "
	# @echo "  __|__|:|\:\  /__/::\      _____\__\:\  /__/::\      /  /:/ /::\   ___ /  /::\   /  /:/ /:/_  \  \:\   /  /\  \  \:\   /  /\ "
	# @echo " /__/::::| \:\ \__\/\:\__  /__/::::::::\ \__\/\:\__  /__/:/ /:/\:\ /__/\  /:/\:\ /__/:/ /:/ /\  \  \:\ /  /:/   \  \:\ /  /:/ "
	# @echo " \  \:\~~\__\/    \  \:\/\ \  \:\~~\~~\/    \  \:\/\ \  \:\/:/~/:/ \  \:\/:/__\/ \  \:\/:/ /:/   \  \:\  /:/     \  \:\  /:/  "
	# @echo "  \  \:\           \__\::/  \  \:\  ~~~      \__\::/  \  \::/ /:/   \  \::/       \  \::/ /:/     \  \:\/:/       \  \:\/:/   "
	# @echo "   \  \:\          /__/:/    \  \:\          /__/:/    \__\/ /:/     \  \:\        \  \:\/:/       \  \::/         \  \::/    "
	# @echo "    \  \:\         \__\/      \  \:\         \__\/       /__/:/       \  \:\        \  \::/         \__\/           \__\/     "
	# @echo "     \__\/                     \__\/                     \__\/         \__\/         \__\/                                    "
	# @echo "						Compilation of $(NAME):  \033[1;32mOK\033[m"

test :
	$(MAKE) all
	@./minishell

clean :
	@echo "\033[0;31m[Deleting *.0 files...]"
	rm -rf $(BIN_DIR)
	$(MAKE) clean -C ./ultralibx

fclean : clean
	@echo "\033[0;31m[Deleting all files...]"
	$(MAKE) fclean -C ./ultralibx
	rm -rf $(NAME)

re : fclean
	$(MAKE) all

pull : fclean
	@echo "\033[0;34m[git pull]"
	@git pull

push : pull fclean
	@echo "\033[0;34m[git push]"
	@git add .
	@git commit -m "fix"
	@git push

.SILENT:

.PHONY: clean fclean re all test chill push pull
