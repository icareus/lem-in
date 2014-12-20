# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abarbaro <abarbaro@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/30 05:29:40 by abarbaro          #+#    #+#              #
#    Updated: 2014/09/17 02:40:28 by abarbaro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Werror -Wextra
NAME = libft.a
SRCDIR = ./includes/
SRCFIL = $(shell ls includes | grep "\.c")
SRC = $(addprefix $(SRCDIR),$(SRCFIL))
ODIR = ./OBJECTS/
SRCO = $(SRCFIL:.c=.o)
BLU = tput setaf 4
GRN = tput setaf 2
WHT = tput setaf 7
NOCOLOR = tput sgr 0

all: $(NAME)

$(NAME): objects
	@$(BLU)
	@echo "Making $(NAME)..."
	@ar -rc $(NAME) $(addprefix $(ODIR),$(SRCO))
	@ranlib $(NAME)
	@$(WHT)
	@echo "$(NAME) done."
	@$(NOCOLOR)

objects:
	@$(BLU)
	@echo "Making objects..."
	@$(CC) $(CFLAGS) -c $(SRC)
	@mkdir -p $(ODIR)
	@mv $(SRCO) $(ODIR)
	@$(WHT)
	@echo "objects done."
	@$(NOCOLOR)

re: fclean all
	@$(GRN)
	@echo "Project reset and rebuilt."
	@$(NOCOLOR)

clean:
	@$(BLU)
	@echo "Cleaning objects..."
	rm -rf $(ODIR)
	@$(WHT)
	@echo "Cleaning done."
	@$(NOCOLOR)

fclean: clean
	@$(BLU)
	@echo "Deleting output..."
	rm -f $(NAME)
	@$(WHT)
	@echo "Deletion done."
	@$(NOCOLOR)

