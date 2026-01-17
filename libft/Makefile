# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alex <alex@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/07 19:09:41 by amoderan          #+#    #+#              #
#    Updated: 2026/01/15 17:20:51 by alex             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
FLAGS = -Wall -Werror -Wextra 
RM = rm -rf
AR = ar rcs
SRC =	ft_isalpha ft_isdigit ft_isalnum ft_isascii ft_isprint \
    	ft_toupper ft_tolower \
    	ft_memcpy ft_memset ft_memcmp ft_memchr ft_memmove \
    	ft_strncmp ft_strlen ft_strlcpy ft_strlcat ft_strchr \
    	ft_strrchr ft_strnstr ft_strdup \
    	ft_atoi ft_bzero ft_calloc \
    	ft_substr ft_strjoin ft_strtrim ft_itoa ft_strmapi \
    	ft_split ft_striteri ft_putchar_fd ft_putstr_fd \
    	ft_putendl_fd ft_putnbr_fd ft_lstnew_bonus ft_lstadd_front_bonus \
		ft_lstsize_bonus ft_lstlast_bonus \
		ft_lstadd_back_bonus ft_lstdelone_bonus ft_lstclear_bonus \
		ft_lstiter_bonus ft_lstmap_bonus \
		ft_printf parser flags conversion data \
		manag_precision manag_prefix manag_width \
		conversion_hex conversion_int conversion_percent \
		conversion_point conversion_s ft_utoa ft_htoa \
		ft_ptoa

OBJ = $(SRC:=.o)
SRCS = $(SRC:=.c)
NAME = libft.a

GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m
RESET = \033[0;39m

all: $(NAME)

$(NAME): $(OBJ)
	@$(AR) $(NAME) $(OBJ)
	@echo "$(GREEN)$(NAME) created successfully!$(RESET)"


%.o: %.c
	@echo "$(YELLOW)Compiling $<...$(RESET)"
	@$(CC) $(FLAGS) -c $< -o $@

clean :
	@$(RM) $(OBJ)  > /dev/null 2>&1

fclean : clean
	@$(RM) $(NAME)  > /dev/null 2>&1

re: fclean all

.PHONY : all clean fclean re

