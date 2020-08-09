NAME_P = push_swap

NAME_C = checker

ADDAR = ar rc

RLIB = ranlib

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRC_W = srcs/bonus.c srcs/command_forchecker.c srcs/dlc_fun_two.c srcs/fill_stac.c \
        srcs/ft_parsing.c srcs/rules_one.c srcs/sort.c srcs/sorting_five.c \
        srcs/sorting_onehundred.c srcs/work_with_fivestac.c srcs/check_max.c \
        srcs/dlc_fun.c srcs/double_rules.c srcs/ft_checker.c srcs/ft_push_swap.c srcs/rules_two.c \
        srcs/sorting.c srcs/sorting_fivehundred.c srcs/work_with_elevenstac.c

SRC_NAME = $(notdir $(SRC_W))

SRC_PATH = srcs

OBJ_PATH = objs

OBJ_NAME = $(SRC_NAME:.c=.o)

SRCS = $(addprefix $(SRC_PATH)/,$(SRC_NAME))

OBJS = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

CFLAGS += -I includes

CFLAGS += -I libft/includes

LIBFT = libft

LDLIBS = -lft

LDFLAGS = -L $(LIBFT)

###############################################################################
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
#	CFLAGS += -Wno-unused-but-set-variable
	NUMPROC := $(shell grep -c ^processor /proc/cpuinfo)
else ifeq ($(UNAME_S),Darwin)
	NUMPROC := $(shell sysctl hw.ncpu | awk '{print $$2}')
endif
################################################################################

all	: $(NAME_P) $(NAME_C)

fast	:
	@$(MAKE) -s -j$(NUMPROC)

libft.a	:
	@echo "$(RED)Making libft...$(EOC)\n"
	@$(MAKE) --no-print-directory -C $(LIBFT) all

$(OBJ_PATH) : libft.a
	@mkdir -p $(OBJ_PATH) 2> /dev/null
	@echo "$(GRN)Compiling with \"$(CFLAGS)\" :$(EOC)\n"

$(NAME_P)	: $(OBJS)
	@echo "$(GRN)%-50s$(EOC)\n" "Compilation done"
#	$(CC) -o $@ $^ $(LDFLAGS) $(LDLIBS)
	@cp libft/libft.a $(NAME_P)
	$(ADDAR) $@ $^
	$(RLIB) $@
	@echo "$(GRN)%-50s$(EOC)\n" "$(NAME_P) done"

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c | $(OBJ_PATH)
	@echo "%-50s\r" "$(CC) $@"
	$(CC) $(CFLAGS) -o $@ -c $<

#so	: all
#	@echo "$(CC) (...) -shared -o $(NAME:.a=.so)\n"
#	@$(CC) $(OBJS) -shared -o $(NAME:.a=.so)

clean	:
	/bin/rm -rf $(OBJ_PATH)
	@$(MAKE) --no-print-directory -C $(LIBFT) fclean
	@echo "$(RED)./$(OBJ_PATH), libft cleaned$(EOC)\n"

fclean	:	clean
	/bin/rm -f $(NAME)
	@echo "$(RED)$(NAME), libft.a removed$(EOC)\n"

ref	:
	/bin/rm -rf $(OBJ_PATH)
	@echo "$(RED)./$(OBJ_PATH), cleaned$(EOC)\n"
	@$(MAKE) --no-print-directory -j$(NUMPROC) $(NAME)

re	:	fclean
	@$(MAKE) --no-print-directory -j$(NUMPROC) $(NAME)

.PHONY: all fast libft.a ref clean fclean re

GRN =	\033[0;32m
RED =	\033[0;31m
EOC =	\033[0m