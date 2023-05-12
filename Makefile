# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebelfkih <ebelfkih@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/29 22:07:59 by ebelfkih          #+#    #+#              #
#    Updated: 2023/05/11 15:11:19 by ebelfkih         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BONUS_NAME = checker
ONAME = utils_functions.a 
MAIN = main/push_swap.c
BONUS_MAIN = main/checker.c
CC = cc -Wall -Werror -Wextra
RM = @rm -f
AR = @ar rc
FILES = utils/push_swap_utils.c utils/libft_utils.c utils/linked_list.c utils/read_check_input.c utils/operations.c utils/libft_utils2.c utils/libft_utils3.c utils/get_next_line.c utils/checker_utils.c sorting_algo/sort.c sorting_algo/chanks.c sorting_algo/chanks1.c
OBJ = $(FILES:.c=.o)

RED = \033[0;31m
GREEN = \033[0;32m
PURPLE = \033[0;35m


%.o : %.c header/push_swap.h main/push_swap.c main/checker.c
	$(CC) -o $@ -c $<

all : $(ONAME) $(BONUS_NAME) $(NAME)
	@echo "${GREEN} archive files are created"
	@echo "${PURPLE} executable files are created"
	@echo "${PURPLE} bonus executable file is created"

$(NAME) : $(ONAME)
	$(CC) $(MAIN) $(ONAME) -o $(NAME)

$(BONUS_NAME) : $(ONAME)
	$(CC) $(BONUS_MAIN) $(ONAME) -o $(BONUS_NAME)

$(ONAME) : $(OBJ)
	@echo "${GREEN} wait ..."
	$(AR) $(ONAME) $^

mandatory : $(NAME)
	@echo "${GREEN} start compiling"
	@echo "${GREEN} archive files are created"
	@echo "${PURPLE} executable files are created"

clean :
	$(RM) $(OBJ) $(ONAME)
	@echo "${RED} archive files are removed"
	
bonus : $(ONAME) $(BONUS_NAME)
	@echo "${GREEN} start compiling"
	@echo "${GREEN} archive files are created"
	@echo "${PURPLE} bonus executable file are created"

fclean: clean
	$(RM) $(NAME) $(ONAME) $(BONUS_NAME) $(IN_OUT)
	@echo "${RED} executable file removed"

re: fclean all 

.PHONY: clean fclean re bonus all mandatory