# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junsyun <junsyun@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/03 06:25:26 by junsyun           #+#    #+#              #
#    Updated: 2022/10/27 23:25:47 by junsyun          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME            = fractol

CC              = cc
FLAGS			= -O3 -Wall -Wextra -Werror -Imlx -g -fsanitize=address
RM              = rm -rf

HEADERS         = includes
LIBFT           = -L./libft -lft
MLX				= -lmlx -framework OpenGL -framework AppKit

DIR_S 			= src
DIR_O			= obj

SOURCES         = main.c			\
				  check_input_tools.c		\
				  fractol_init_tools.c 	\
				  fractol_draw.c			\
				  fractol_sets.c			\
				  keyboard_hook.c			\
				  mouse_hook.c

SRCS			= $(addprefix $(DIR_S)/,$(SOURCES))
OBJS            = $(addprefix $(DIR_O)/,$(SOURCES:.c=.o))

all : $(NAME)

$(NAME) : $(OBJS)
	@make -C libft
	# @make -C mlx
	@$(CC) $(FLAGS) -o $@ $^ $(LIBFT) $(MLX)
		

$(DIR_O)/%.o: $(DIR_S)/%.c $(HEADERS)/$(NAME).h
	@mkdir -p $(DIR_O)
	@$(CC) $(FLAGS) -I $(HEADERS) -c $< -o $@ 

clean : 
	@$(RM) $(DIR_O)
	@make clean -C libft
	# @make clean -C mlx
	
fclean : clean
	@$(RM) $(NAME)
	@make fclean -C libft
re:
	@make fclean
	@make all

.PHONY: all obj clean fclean re

# NAME			= fractol

# RM				= rm -rf

# CC				= cc
# FLAGS			= -Wextra -Werror -Wall

# HEADERS     	= ./includes
# LIBFT       	= -L./libft -lft
# MLX				= -L./mlx -lmlx -framework OpenGL -framework AppKit

# PATH_SRCS 		= src
# PATH_OBJS		= obj

# C_FILE_NAME		= main.c				\
# 				check_input_tools.c		\
# 				fractol_init_tools.c 	\
# 				fractol_draw.c			\
# 				fractol_sets.c			\
# 				keyboard_hook.c			\
# 				mouse.hook.c

# SRCS			= $(addprefix $(PATH_SRCS)/,$(C_FILE_NAME))
# OBJS        	= $(addprefix $(PATH_OBJS)/,$(C_FILE_NAME:.c=.o))

# all : $(NAME)

# $(NAME) : $(OBJS)
# 	@make -C ./libft
# 	@make -C mlx
# 	@$(CC) $(FLAGS) -o $(LIBFT) $@ $^ $(MLX)
		

# $(PATH_OBJS)/%.o: $(PATH_SRCS)/%.c $(HEADERS)/$(NAME).h
# 	@mkdir -p $(PATH_OBJS)
# 	@$(CC) $(FLAGS) -I $(HEADERS) -c -o $@ $<

# clean : 
# 	@$(RM) $(PATH_OBJS)
# 	@make clean -C ./libft
# 	@make clean -C mlx
	
# fclean : clean
# 	@$(RM) $(NAME)
# 	@make fclean -C ./libft
# re:
# 	@make fclean
# 	@make all

# .PHONY: all obj clean fclean re