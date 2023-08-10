# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aceauses <aceauses@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/14 11:58:15 by aceauses          #+#    #+#              #
#    Updated: 2023/06/11 15:34:42 by aceauses         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SILENT:
NAME = libft.a
CC = cc
FLAGS = -Wall -Werror -Wextra

SRC = ft_atoi.c ft_tolower.c ft_strtrim.c ft_striteri.c ft_split.c ft_strjoin.c ft_strnstr.c  ft_itoa.c ft_toupper.c ft_putchar_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_strlcat.c ft_strlen.c ft_strmapi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_calloc.c ft_strlcpy.c ft_strchr.c ft_memset.c ft_memcpy.c ft_memmove.c ft_substr.c ft_strdup.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strrchr.c

OBJS = $(SRC:.c=.o)

BONUS = ft_lstnew.c \
		ft_lstadd_front.c \
		ft_lstsize.c \
		ft_lstlast.c \
		ft_lstadd_back.c \
		ft_lstdelone.c \
		ft_lstclear.c \
		ft_lstiter.c \
		ft_lstmap.c 

BONUS_OBJS = $(BONUS:.c=.o)

BOLD    := \033[1m./SRC/
RED     := \033[31;1m
GREEN   := \033[32;1m
YELLOW  := \033[33;1m
BLUE    := \033[34;1m
MAGENTA := \033[35;1m
CYAN    := \033[36;1m
WHITE   := \033[37;1m
RESET	= \x1b[0m

$(OBJS):
	$(CC) -c $(FLAGS) $(SRC)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

$(BONUS_OBJS):
	$(CC) -c $(FLAGS) $(BONUS)

all: $(NAME)
	@echo "$(CYAN)[Libft] $(GREEN)Library Compiled$(RESET)"

bonus: $(BONUS_OBJS)
	ar rcs $(NAME) $(BONUS_OBJS)
	@echo "$(CYAN)[Libft] $(GREEN)Bonus Compiled$(RESET)"

clean:
	rm -f $(OBJS)
	rm -f $(BONUS_OBJS)
	@echo "$(CYAN)[Libft] $(RED)Objects Cleaned$(RESET)"

fclean:
	rm -f $(NAME) $(OBJS) $(BONUS_OBJS)
	@echo "$(CYAN)[Libft] $(RED)Library, Objects Cleaned$(RESET)"


re: fclean all

.PHONY: all clean fclean bonus re