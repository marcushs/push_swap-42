# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hleung <hleung@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/23 11:38:57 by hleung            #+#    #+#              #
#    Updated: 2023/05/10 15:55:49 by hleung           ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

GREEN = \033[0;32m
YELLOW = \033[0;33m
NC = \033[0m

NAME				=	push_swap

BONUS				=	checker

CC					=	gcc

CFLAGS				=	-Wall -Wextra -Werror #-fsanitize=address

LIBFT_FLAGS			=	-L libft -lft

LIBS_FILES			=	${shell find libft -type f}
HEADER_FILES		=	${shell find includes -type f}

DIR_PS_SRCS			=	./srcs/push_swap/
LIST_PS_SRCS		=	best_rotate_combo.c cases_a_to_b.c cases_b_to_a.c check_1_arg.c check_args.c \
						DCLL.c error.c free.c operation_utils.c parse.c push.c \
						rotate.c rrotate.c run_combo.c solve_5_or_under.c solve_large_list.c \
						solve_utils.c solve_utils2.c swap.c
PS_SRCS_1			=	${addprefix ${DIR_PS_SRCS}, ${LIST_PS_SRCS}}
PS_SRCS_2			=	./srcs/push_swap/push_swap.c

DIR_CHECKER_SRCS	=	./srcs/checker/
LIST_CHECKER_SRCS	=	checker.c gnl_utils.c gnl.c
CHECKER_SRCS		=	${addprefix ${DIR_CHECKER_SRCS}, ${LIST_CHECKER_SRCS}}

DIR_OBJS			=	.objs/
LIST_PS_OBJS		=	${LIST_PS_SRCS:.c=.o}
OBJS_1				=	${addprefix ${DIR_OBJS}, ${LIST_PS_OBJS}}
OBJS_2				=	${PS_SRCS_2:.c=.o}

DIR_CHECKER_OBJS	=	.bonus_objs/
LIST_CHECKER_OBJS	=	${LIST_CHECKER_SRCS:.c=.o}
CHECKER_OBJS		=	${addprefix ${DIR_CHECKER_OBJS}, ${LIST_CHECKER_OBJS}}

HEADERS				=	includes

RM					=	rm -rf

all:		${NAME}

${DIR_OBJS}%.o:	${DIR_PS_SRCS}%.c Makefile 
				@${CC} ${CFLAGS} -c $< -o $@ -I ${HEADERS}

${DIR_CHECKER_OBJS}%.o:	${DIR_CHECKER_SRCS}%.c
						@${CC} ${CFLAGS} -c $< -o $@ -I ${HEADERS}

${OBJS_2}:	${PS_SRCS_2}
			@${CC} ${CFLAGS} -c $< -o $@ -I ${HEADERS}

${NAME}:	${DIR_OBJS} ${OBJS_1} ${OBJS_2} ${LIBS_FILES} ${HEADER_FILES}
			@${MAKE} -sC ./libft
			@${CC} ${CFLAGS} ${OBJS_1} ${OBJS_2} ${LIBFT_FLAGS} -o ${NAME}
			@echo "${GREEN}Compiled push_swap! ${NC}"

bonus:		${BONUS}

${BONUS}:	${NAME} ${DIR_CHECKER_OBJS} ${CHECKER_OBJS} ${LIBS_FILES} ${HEADER_FILES}
			@${CC} ${CFLAGS} ${CHECKER_OBJS} ${OBJS_1} ${LIBFT_FLAGS} -o ${BONUS}
			@echo "${GREEN}Compiled checker! ${NC}"

${DIR_OBJS}:
			@mkdir -p ${DIR_OBJS}

${DIR_CHECKER_OBJS}:
			@mkdir -p ${DIR_CHECKER_OBJS}

clean:
			@${RM} ${DIR_OBJS} ${DIR_CHECKER_OBJS} ./srcs/push_swap/push_swap.o
			@${MAKE} clean -sC ./libft
			@echo "${YELLOW}Object files and libraries cleared!${NC}"

fclean:		clean
			@${MAKE} fclean -sC ./libft
			@${RM} ${NAME} ${BONUS}
			@echo "${YELLOW}Executable cleared!${NC}"

re:			fclean
			${MAKE} all

.PHONY:		all re clean fclean .c.o
