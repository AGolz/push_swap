# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cfiora <cfiora@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/18 04:50:46 by cfiora            #+#    #+#              #
#    Updated: 2021/10/24 06:55:51 by cfiora           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BONUS_NAME = checker

LIBFTD = libft/
INCD = includ/
SRSD = srcs/
OBJD = objects/
BONUSD = bonus/
BONUSSD = ${BONUSD}srcs/
BONUSOD = ${BONUSD}objects/

LIBFT := ${addprefix ${LIBFTD},libft.a}
SOURCES = push_swap.c comm_utils.c command.c push.c sort_utils.c sort_utl.c \
sort.c stack_pp.c stack.c utils.c valid.c
BONUS = checker.c gnl_ps.c

OBJECTS := ${addprefix ${OBJD},${SOURCES:.c=.o}}
SOURCES := ${addprefix ${SRCD},${SOURCES:.c=.o}}
BONUSO	:= ${addprefix ${BONUSOD},${BONUS:.c=.o}}
BONUS := ${addprefix ${BONUSSD},${BONUS}}


CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBFTMK = make -C $(LIBFTD)

BLUE = \033[1;36m 
PINK = \033[1;35m
RESET = \033[0m

WHALE	=	"\n$(BLUE)       ::: \n     ___:____     |^\/^| \n   ,'        '.    \  / \n   |  O        \___/  | \n ~^~^~^~^~^~^~^~^~^~^~^~^~\n \n Compilation Successful!	${NC}\n"
NUKE	=	"\n$(PINK)    _.-^^---....,,--       \n _--                  --_  \n<                        >)\n|                         | \n \._                   _./  \n    '''--. . , ; .--'''       \n          | |   |             \n       .-=||  | |=-.   \n       '-=£€%&%€£=-'   \n          | ;  :|     \n _____.,-£%&€@%£&£~,._____${NC}\n\n"


.PHONY: all clean fclean re bonus


all: $(NAME)
	@echo $?

$(NAME): $(LIBFT) $(OBJECTS) $(INCD)push_swap.h
	$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT) -I$(INCD) -o $(NAME) 
	@echo "\n$(NAME): $(BLUE) Making Libft... $(RESET)"
	@echo "\n$(NAME): $(BLUE) Making push_swap... $(RESET)"
	@echo $(WHALE)
	

$(OBJD)%.o: $(SRSD)%.c
	mkdir -p $(OBJD)
	$(CC) -c -o $@ $(CFLAGS) -I$(INCD) -I$(LIBFTD) $?



$(LIBFT):
	$(LIBFTMK)

bonus: $(LIBFT) $(BONUSO) $(INCD)push_swap.h $(INCD)checker.h $(INCD)get_next_line_ps.h 
	$(CC) $(CFLAGS) $(BONUSO) ${filter-out ${OBJD}push_swap.o,${OBJECTS}} $(LIBFT) -o $(BONUS_NAME) 
	@echo "\n$(NAME_2): $(BLUE) Making checker... $(RESET)"
	@echo $(WHALE)

$(BONUSOD)%.o: $(BONUSSD)%.c
	mkdir -p $(BONUSOD)
	$(CC) -c -o $@ $(CFLAGS) -I$(INCD) -I$(LIBFTD) $?


clean:  
	-rm -rf $(OBJD) $(BONUSOD)
	$(LIBFTMK) clean
	@echo "$(PINK) clean libft  $(RESET)"
	@echo "$(PINK) clean checker $(RESET)"
	@echo "$(PINK) clean push_swap $(RESET)"

fclean: clean
	-rm $(NAME) $(BONUS_NAME)
	$(LIBFTMK) fclean
	@echo "$(PINK) fclean libft $(RESET)"
	@echo "$(PINK) fclean checker $(RESET)"
	@echo "$(PINK) fclean push_swap $(RESET)"
	@echo "$(PINK) ...3 2 1 $(RESET)"
	@echo $(NUKE)

re: fclean all