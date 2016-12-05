# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afourcad <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/07 20:03:40 by afourcad          #+#    #+#              #
#    Updated: 2016/12/05 17:01:36 by jebossue         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= gnl

SRCDIR	= .
OBJDIR	= objs
INCDIR	= includes

SRCNAM	= main.c get_next_line.c

SRC		= $(SRCNAM:%=$(SRCDIR)/%)
OBJ		= $(SRC:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

CC		= clang
CFLAGS	= -Wall -Wextra -Werror -I$(INCDIR) -I$(LIBFTDIR)
LDFLAGS	= -L $(LIBFTDIR) -lft

LIBFTNAM	= libft.a
LIBFTDIR	= ./libft/
LIBFT		= $(LIBFTNAM:%=$(LIBFTDIR)/%)

INCNAM = get_next_line.h 
INC = $(INCNAM:%=$(INCDIR)/%)

GIT	= README.md

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

$(LIBFT):
	$(MAKE) -C $(LIBFTDIR)

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(INC) $(LIBFT)
	mkdir -p $(OBJDIR)
	$(CC) -o $@ -c $< $(CFLAGS)

.PHONY: all git no printf check clean fclean re $(LIBFT)

git:
	git add $(SRC) $(INC) $(GIT)

no:
	@echo "Passage de la norminette :"
	@norminette $(SRC) $(INC)

printf:
	@echo "Detection des printf :\033[1;31m"
	@grep printf -r $(SRCDIR) $(INCDIR) | cat
	@printf "\033[0m"

check: no printf

clean:
	rm -rf $(OBJDIR)
	$(MAKE) -C $(LIBFTDIR) clean

fclean: clean
	rm -rf $(NAME)
	$(MAKE) -C $(LIBFTDIR) fclean

# $(MAKE) needed so that the cleaning is done before starting to create again \
	# 	# cf make -j 
re: fclean
	$(MAKE) all
