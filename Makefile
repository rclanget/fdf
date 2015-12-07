# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rclanget <rclanget@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/18 13:32:25 by rclanget          #+#    #+#              #
#    Updated: 2015/06/13 21:16:40 by rclanget         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME	= fdf

SRC		= $(shell find "sources" -type f -print | grep "\.c")

OBJ		= $(SRC:.c=.o)
LIBFT	= libft/
LIBX	= libx/
CC		= /usr/bin/gcc
CFLAGS	= -Wall -Wextra -Werror -g -I ./includes/ -I ./$(LIBFT)includes/ -I ./$(LIBX)
FMLX	= -framework OpenGL -framework AppKit -lmlx
RM		= /bin/rm -f
ECHO	= /bin/echo -e

ARGS	= none

$(NAME):	$(OBJ)
		@make -C $(LIBFT)
		@make -C $(LIBX)
		@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -L $(LIBFT) -lft -L $(LIBX) -lft $(FMLX)  && \
		printf " -->> \033[32mCompilation Success: %s\033[0m             \n" "$@"|| \
		printf " -->> \033[31mCompilation Failed: %s\033[0m              \n" "$@";

clean:
		@make -C $(LIBFT) clean
		@make -C $(LIBX) clean
		@$(RM) $(OBJ)

fclean:		clean
		@make -C $(LIBFT) fclean
		@make -C $(LIBX) fclean
		@$(RM) $(NAME)

all:		$(NAME)

re:		fclean all

.PHONY:		re all clean fclean

.c.o:
	@$(CC) $(CFLAGS) -o $@ -c $< && \
		printf " -->> \033[32mOk\033[0m: %s                       \r" "$@" || \
		printf " -->> \033[31mKo\033[0m: %s                       \r" "$@";
