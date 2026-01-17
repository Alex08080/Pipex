# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alex <alex@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/17 17:27:38 by alex              #+#    #+#              #
#    Updated: 2026/01/17 17:31:33 by alex             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

CC = cc

CFLAGS = -g -Wall -Wextra -Werror -Ilibft/ -I./include

INCDIR = include

SRC_MAIN = pipex.c

SRCS = $(addprefix $(SRCDIR)/,$(SRC) $(SRC_MAIN))
SRCS_BONUS = $(addprefix $(SRCDIR)/, $(SRC_BONUS) $(SRC))
SRCDIR = src
OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

VAL = valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes

LIBFT_DIR = ./libft/
LIBFT = $(LIBFT_DIR)libft.a

RESET = \033[0m
GREEN = \033[32;01m
BLUE = \033[34;01m
RED = \033[31;01m
YELLOW = \033[0;93m
CYAN = \033[0;96m

all: $(NAME)
$(NAME): $(OBJS) $(LIBFT)
	@echo "$(BLUE)Linking $(NAME)..."
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -L$(LIBFT_DIR) -lft > /dev/null 2>&1
	@echo "$(GREEN)$(NAME) created successfully!$(RESET)"

$(LIBFT):
	@echo "$(BLUE)Compiling libft...$(RESET)"
	@make -C $(LIBFT_DIR) all
	@echo "$(GREEN)libft ready!$(RESET)"

bonus: $(BONUS)

$(BONUS): $(OBJS_BONUS) $(LIBFT)
	@echo "$(GREEN)Compiling $(BONUS)...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJS_BONUS) -o $(BONUS) -L$(LIBFT_DIR) -lft
	@echo "$(GREEN)$(BONUS) created successfully!$(RESET)"

$(SRCDIR)/%.o : $(SRCDIR)/%.c $(INCDIR)/push_swap.h
	@echo "$(YELLOW)Compiling $<...$(RESET)"
	@$(CC) $(CFLAGS) -I./$(INCDIR) -c $< -o $@

clean:
	@make -C $(LIBFT_DIR) clean > /dev/null 2>&1
	@rm -f $(OBJS) $(OBJS_BONUS)
	@echo "$(CYAN)Cleaned all .o files.$(RESET)"

fclean: clean
	@make -C $(LIBFT_DIR) fclean > /dev/null 2>&1
	@rm -f $(NAME) $(BONUS)
	@echo "$(CYAN)Cleaned $(NAME) and Libft.$(RESET)"

re: fclean all

.PHONY: all clean fclean re