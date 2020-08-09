# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: etristan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/07 16:32:13 by etristan          #+#    #+#              #
#    Updated: 2019/12/17 17:39:28 by etristan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_P = push_swap

NAME_C = checker

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRC_W = srcs/bonus.c srcs/command_forchecker.c srcs/dlc_fun_two.c srcs/fill_stac.c \
	srcs/ft_parsing.c srcs/rules_one.c srcs/sort.c srcs/sorting_five.c \
	srcs/sorting_onehundred.c srcs/work_with_fivestac.c srcs/check_max.c \
	srcs/dlc_fun.c srcs/double_rules.c srcs/ft_checker.c srcs/ft_push_swap.c srcs/rules_two.c \
	srcs/sorting.c srcs/sorting_fivehundred.c srcs/work_with_elevenstac.c srcs/bonus_d.c

SRC_NAME = $(notdir $(SRC_W))

#SRC_NAME = $(wildcard *.c)

SRC_PATH = srcs

OBJ_PATH = objs

OBJ_NAME = $(SRC_NAME:.c=.o)

SRCS = $(addprefix $(SRC_PATH)/,$(SRC_NAME))

OBJS = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

CFLAGS += -I ./

CFLAGS += -I ./libft/includes

LIBFT = libft

LDLIBS = -lft

LDFLAGS = -L $(LIBFT)

###############################################################################
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
	NUMPROC := $(shell grep -c ^processor /proc/cpuinfo)
else ifeq ($(UNAME_S),Darwin)
	NUMPROC := $(shell sysctl hw.ncpu | awk '{print $$2}')
endif
################################################################################

all	: $(NAME_P) $(NAME_C)

fast	:
	@$(MAKE) -s -j$(NUMPROC)

libft.a	:
	@printf "$(RED)Making libft...$(EOC)\n"
	@$(MAKE) --no-print-directory -C $(LIBFT) all

$(OBJ_PATH)     : libft.a
	@mkdir -p $(OBJ_PATH) 2> /dev/null
	@printf "$(GRN)Compiling with \"$(CFLAGS)\" :$(EOC)\n"

$(NAME_P)	: $(subst objs/ft_checker.o,,$(OBJS))
	@printf "$(GRN)%-50s$(EOC)\n" "Compilation done"
	$(CC) -o $@ $^ $(LDFLAGS) $(LDLIBS)
	@printf "$(GRN)%-50s$(EOC)\n" "$(NAME_P) done"

$(NAME_C)	: $(subst objs/ft_push_swap.o,,$(OBJS))
	@printf "$(GRN)%-50s$(EOC)\n" "Compilation done"
	$(CC) -o $@ $^ $(LDFLAGS) $(LDLIBS)
	@printf "$(GRN)%-50s$(EOC)\n" "$(NAME_C) done"

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c | $(OBJ_PATH)
	@printf "%-50s\r" "$(CC) $@"
	$(CC) $(CFLAGS) -o $@ -c $<

clean	:
	/bin/rm -rf $(OBJ_PATH)
	@$(MAKE) --no-print-directory -C $(LIBFT) fclean
	@printf "$(RED)./$(OBJ_PATH), libft cleaned$(EOC)\n"

fclean	:	clean
	/bin/rm -f $(NAME_P) $(NAME_C)
	@printf "$(RED)$(NAME_P), $(NAME_C), libft.a removed$(EOC)\n"

ref	:
	/bin/rm -rf $(OBJ_PATH)
	@printf "$(RED)./$(OBJ_PATH), cleaned$(EOC)\n"
	@$(MAKE) --no-print-directory -j$(NUMPROC) $(NAME_P) $(NAME_C)

re	:	fclean
	@$(MAKE) --no-print-directory -j$(NUMPROC) $(NAME_P) $(NAME_C)

.PHONY: all fast clean fclean re ref libft.a $(NAME_P) $(NAME_C)

GRN =	\033[0;32m
RED =	\033[0;31m
EOC =	\033[0m
