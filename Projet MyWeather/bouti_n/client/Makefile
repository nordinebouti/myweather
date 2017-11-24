CC		=		gcc

NAME	=		weather-client

SRC		=		main.c\
				str.c\

RM		=		rm -f

OBJ		=		$(SRC:%.c=%.o)

CFLAGS	=		-W -Wall -Werror -g -pedantic -lzmq -lczmq


all		:		$(OBJ)
				$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean	:
				$(RM) $(OBJ)

fclean	:		clean
				$(RM) $(NAME)

re 		:		fclean all