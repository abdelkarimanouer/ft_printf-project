NAME = libftprintf.a
CC = cc
FLAGS = -Wall -Wextra -Werror
SRC = 
OBJ = $(SRC:%.c=%:.o)
HEADERS = 

all : $(NAME)

$(NAME) : $(OBJ)
	ar rsc $(NAME) $(OBJ)

%.o : %.c $(HEADERS)
	$(CC) $(FLAGS) -c $< -o $@

clean :
	rm -rf *.o

fclean : clean
	rm $(NAME)

re : fclean all

.PHONEY : clean