# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junsyun <junsyun@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/03 06:25:26 by junsyun           #+#    #+#              #
#    Updated: 2022/10/06 18:35:59 by junsyun          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= fractol

RM				= rm -rf

CC				= cc
FLAGS			= -Wextra -Werror -Wall

HEADERS     	= ./includes
LIBFT       	= -L./libft -lft
MLX				= -L./mlx -lmlx -framework OpenGL -framework AppKit

PATH_SRCS 		= src
PATH_OBJS		= obj

C_FILE_NAME		= main.c		\
				fractol.c			

SRCS			= $(addprefix $(PATH_SRCS)/,$(C_FILE_NAME))
OBJS        	= $(addprefix $(PATH_OBJS)/,$(C_FILE_NAME:.c=.o))

all : $(NAME)

$(NAME) : $(OBJS)
	@make -C ./libft
	@make -C mlx
	@$(CC) $(FLAGS) -o $(LIBFT) $@ $^ $(MLX)
		

$(PATH_OBJS)/%.o: $(PATH_SRCS)/%.c $(HEADERS)/$(NAME).h
	@mkdir -p $(PATH_OBJS)
	@$(CC) $(FLAGS) -I $(HEADERS) -c $< -o $@ 

clean : 
	@$(RM) $(PATH_OBJS)
	@make clean -C ./libft
	@make clean -C mlx
	
fclean : clean
	@$(RM) $(NAME)
	@make fclean -C ./libft
re:
	@make fclean
	@make all

.PHONY: all obj clean fclean re