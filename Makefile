##
## Makefile for Makefile in /home/benjamin.g/save/nouveau_projet
##
## Made by Benjamin GAYMAY
## Login   <benjamin.g@epitech.net>
##
## Started on  Sun Nov 20 13:42:20 2016 Benjamin GAYMAY
## Last update Mon Feb 20 13:30:10 2017 Benjamin GAYMAY

CC	=	gcc -g

NAME	=	matchstick

SRC	=	./src/main.c \
		./src/matchstick.c \
		./src/xor.c \
		./src/bin.c \
		./src/player.c \
		./basics/my_getnbr.c \
		./basics/my_power_rec.c \
		./basics/my_showtab.c \
		./basics/my_putchar.c \
		./basics/my_puterror.c \
		./basics/my_putstr.c \
		./basics/my_str_isnum.c \
		./basics/my_strlen.c \
		./get_next_line/get_next_line.c \
                ./my_printf/flag.c \
                ./my_printf/hexa.c \
                ./my_printf/octal_bin.c \
                ./my_printf/my_printf.c \
                ./my_printf/my_putstr_printf.c \
                ./my_printf/my_strlen_printf.c \
		./my_printf/my_put_nbr_printf.c \
		./my_printf/my_putchar_printf.c \
                ./my_printf/my_put_nbr_unsigned.c \

OBJ	=	$(SRC:.c=.o)

CFLAGS +=	-I./include

RM	=	rm -f

all	:	$(NAME)

$(NAME)	:	$(OBJ)
		$(CC) -o $(NAME) $(OBJ)

clean	:
		$(RM) $(OBJ)

fclean	:	clean
		$(RM) $(NAME)

re	:	fclean all

.PHONY	:	all clean fclean re
