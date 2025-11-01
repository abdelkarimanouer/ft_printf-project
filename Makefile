NAME = libftprintf.a
CC = cc
FLAGS = -Wall -Wextra -Werror
SRC = ft_printf.c
OBJ = $(SRC:%.c=%.o)
HEADERS = ft_printf.h

all : $(NAME)

$(NAME) : $(OBJ)
	ar rsc $(NAME) $(OBJ)

%.o : %.c $(HEADERS)
	$(CC) $(CFLAGS) -I. -c $< -o $@

clean :
	rm -f *.o

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : clean