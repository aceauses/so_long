# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aceauses <aceauses@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/10 14:31:13 by aceauses          #+#    #+#              #
#    Updated: 2023/08/09 22:17:11 by aceauses         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CFLAGS = -Wall -Werror -Wextra -g
USER = $(shell brew --prefix glfw)/lib/
MLX = -Iinclude -lglfw -L "$(USER)"
CC = gcc
RM = rm -f

##################################
##				libft			##
##################################
LIBFT_PATH = libft/
LIBFT_LIB = $(LIBFT_PATH)libft.a

##################################
##				GNL			##
##################################
GNL_PATH = GNL/
GNL_LIB = $(GNL_PATH)gnl

##################################
##				MLX				##
##################################
MLX_CLONE = https://github.com/codam-coding-college/MLX42
MLX_PATH = MLX42/build/
MLX_CHECK = MLX42/
MLX_LIB = $(MLX_PATH)libmlx42.a

##################################
##				PRINTF			##
##################################
PRINTF_CLONE = https://github.com/aceauses/42Printf
PRINTF_PATH = printf/
PRINTF_LIB = $(PRINTF_PATH)libftprintf.a


##################################
##			MANDATORY_SRCS		##
##################################
SRCS_DIR = src/
SRCS = $(SRCS_DIR)so_long.c \
		$(SRCS_DIR)init_struct.c \
		$(SRCS_DIR)ft_error.c \
		$(SRCS_DIR)init_map.c \
		$(SRCS_DIR)map_validation.c \
		$(SRCS_DIR)mlx_init.c \
		$(SRCS_DIR)mlx_control.c \
		$(SRCS_DIR)moves.c

##################################
##			BONUS_SRCS			##
##################################
SRCS_BONUS_DIR = src_bonus/
SRCS_BONUS = $(SRCS_BONUS_DIR)bonus_so_long.c \
		$(SRCS_BONUS_DIR)bonus_init_struct.c \
		$(SRCS_BONUS_DIR)bonus_ft_error.c \
		$(SRCS_BONUS_DIR)bonus_init_map.c \
		$(SRCS_BONUS_DIR)bonus_enemy.c \
		$(SRCS_BONUS_DIR)bonus_map_validation.c \
		$(SRCS_BONUS_DIR)bonus_mlx_init.c \
		$(SRCS_BONUS_DIR)bonus_mlx_control.c \
		$(SRCS_BONUS_DIR)bonus_moves.c \
		$(SRCS_BONUS_DIR)bonus_movement.c \
		$(SRCS_BONUS_DIR)bonus_init_images.c \
		$(SRCS_BONUS_DIR)bonus_mlx_moves.c

OBJS_DIR = obj/
OBJS = $(addprefix $(OBJS_DIR), $(notdir $(SRCS:.c=.o)))

OBJS_DIR_BONUS = obj_bonus/
OBJS_BONUS = $(addprefix $(OBJS_DIR_BONUS), $(notdir $(SRCS_BONUS:.c=.o)))

BOLD    := \033[1m./SRC/
RED     := \033[31;1m
GREEN   := \033[32;1m
YELLOW  := \033[33;1m
BLUE    := \033[34;1m
MAGENTA := \033[35;1m
CYAN    := \033[36;1m
WHITE   := \033[37;1m
RESET	= \x1b[0m

all: $(NAME)

$(LIBFT_LIB):
	@make -C $(LIBFT_PATH) all bonus

$(GNL_LIB):
	@make -C $(GNL_PATH)

$(PRINTF_PATH):
	@git clone $(PRINTF_CLONE) printf

$(PRINTF_LIB): $(PRINTF_PATH)
	@make -C $(PRINTF_PATH) all

$(MLX_CHECK):
	@git clone $(MLX_CLONE)

$(MLX_PATH): $(MLX_CHECK)
	@cd MLX42 && cmake -B build 

$(MLX_LIB): $(MLX_PATH)
	@cd $(MLX_PATH) && make all -s

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
	@echo "$(YELLOW)Compiling:$(RESET) $(BLUE)$<$(RESET)"
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(CFLAGS) -c -o $@ $<

$(OBJS_DIR_BONUS)%.o: $(SRCS_BONUS_DIR)%.c
	@echo "$(YELLOW)Compiling:$(RESET) $(BLUE)$<$(RESET)"
	@mkdir -p $(OBJS_DIR_BONUS)
	@$(CC) $(CFLAGS) -c -o $@ $<


$(NAME): $(MLX_LIB) $(PRINTF_LIB) $(LIBFT_LIB) $(GNL_LIB) $(OBJS)
	@echo "$(GREEN)Compiled with $(CYAN)$(CFLAGS)$(RESET)"
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT_LIB) $(GNL_LIB) $(MLX_LIB) $(MLX) $(PRINTF_LIB)
	@echo "$(CYAN)-------------------------------------------"
	@echo "	$(NAME) = NOW READY FOR USE!"
	@echo "-------------------------------------------$(RESET)"

bonus: $(MLX_LIB) $(PRINTF_LIB) $(LIBFT_LIB) $(GNL_LIB) $(OBJS_BONUS)
	@echo "$(GREEN)Compiled with $(CYAN)$(CFLAGS)$(RESET)"
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS_BONUS) $(LIBFT_LIB) $(GNL_LIB) $(MLX_LIB) $(MLX) $(PRINTF_LIB)
	@echo "$(CYAN)-------------------------------------------"
	@echo "	$(NAME) BONUS ready to use"
	@echo "-------------------------------------------$(RESET)"

clean:
	@$(RM) $(OBJS) $(OBJS_BONUS)
	@echo "$(CYAN)[so_long] $(RED)Objects Cleaned$(RESET)"
	@make -C $(LIBFT_PATH) clean
	@make -C $(GNL_PATH) clean
	@make -C $(PRINTF_PATH) clean

fclean:
	@$(RM) $(NAME) $(OBJS) $(OBJS_BONUS)
	@$(RM) -rf $(OBJS_DIR) $(OBJS_DIR_BONUS)
	@echo "$(CYAN)[so_long] $(RED)Executable, Objects Cleaned$(RESET)"
	@cd $(MLX_PATH) && make clean
	@echo "$(CYAN)[MLX42] $(RED)Library Cleaned$(RESET)"
	@make -C $(LIBFT_PATH) fclean
	@make -C $(GNL_PATH) fclean
	@make -C $(PRINTF_PATH) fclean

re: fclean all

.PHONY: all clean fclean