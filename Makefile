# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: heltayb <heltayb@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/11 11:33:45 by heltayb           #+#    #+#              #
#    Updated: 2024/02/26 07:35:08 by heltayb          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PROG = push_swap
CFLAGS = -Wall -Wextra -Werror

OBJECTS = 	push_swap.o ft_valid.o ft_string_to_num.o \
			ft_split.o instructions_push.o instructions_swap.o \
			instructions_rotate.o instructions_reverse_rotate.o \
			initialize_stack.o ft_free.o sorting.o \
			sorting_helpers.o sorting_utils.o

all: $(PROG)

$(PROG): $(OBJECTS)
	@$(CC) $(CFLAGS) -o $(PROG) $(OBJECTS)

clean:
	@rm -rf $(OBJECTS)

fclean: clean 
	@rm -rf $(PROG)

re: fclean all

.PHONY: all re clean fclean
