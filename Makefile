NAME = eval_expr

SRC = main.c ./srcs/utils.c ./srcs/eval_expr.c

OBJ = main.o utils.o eval_expr.o

INC = ./includes/
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	gcc $(FLAGS) -I $(INC) -c $(SRC)
	gcc $(OBJ) -o $(NAME)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
