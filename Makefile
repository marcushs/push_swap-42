# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hleung <hleung@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/23 11:38:57 by hleung            #+#    #+#              #
#    Updated: 2023/01/26 16:21:02 by hleung           ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME			=	push_swap

CC				=	gcc

CFLAGS			=	-Wall -Wextra -Werror -fsanitize=address

LIBFT_FLAGS		=	-L libft -lft

LIBS_FILES		=	${shell find libft -type f}
HEADER_FILES	=	${shell find includes -type f}

DIR_SRCS		=	./srcs/
LIST_SRCS		=	push_swap.c error.c free.c DCLL.c check_1_arg.c check_args.c parse.c
SRCS			=	${addprefix ${DIR_SRCS}, ${LIST_SRCS}}

DIR_OBJS		=	.objs/
LIST_OBJS		=	${LIST_SRCS:.c=.o}
OBJS			=	${addprefix ${DIR_OBJS}, ${LIST_OBJS}}

HEADERS			=	includes

RM				=	rm -rf

all:		${NAME}

${DIR_OBJS}%.o:	${DIR_SRCS}%.c Makefile 
				${CC} ${CFLAGS} -c $< -o $@ -I ${HEADERS}

${NAME}:	${DIR_OBJS} ${OBJS} ${LIBS_FILES} ${HEADER_FILES}
			${MAKE} -C ./libft
			${CC} ${CFLAGS} ${OBJS} ${LIBFT_FLAGS} -o ${NAME}

${DIR_OBJS}:
			mkdir -p ${DIR_OBJS}

clean:
			${RM} ${DIR_OBJS}
			${MAKE} clean -C ./libft

fclean:		clean
			${MAKE} fclean -C ./libft
			${RM} ${NAME}

re:			fclean
			${MAKE} all

.PHONY:		all re clean fclean .c.o
