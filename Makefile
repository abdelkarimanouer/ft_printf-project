NAME = libftprintf.a
CC = cc
FLAGS = -Wall -Wextra -Werror
SRC = 
OBJ = $(SRC:%.c=%.o)
HEADERS = 

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