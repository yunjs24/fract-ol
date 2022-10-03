# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junsyun <junsyun@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/03 06:25:26 by junsyun           #+#    #+#              #
#    Updated: 2022/10/03 06:29:51 by junsyun          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fractol

CC		= gcc
CFLAGS	= -Wextra -Werror -Wall

MLX_NAME	= libmlx.a
MLX_PATH	= minilibx-linux/
MLX			= $(MLX_PATH) $(MLX_NAME)

LIBFT_PATH	= ./libft/
LIBFT_NAME	= libft.a
LIBFT		= $(LIBFT_PATH) $(LIBFTNAME)

INC			=	-I ./includes/\
			=	-I ./libft/\
			=	-I ./minilibx-linux/

SRCS_PATH = ./src/
SRCS	  = fractol.c
