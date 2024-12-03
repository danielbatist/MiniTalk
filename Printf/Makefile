CC = cc 

CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

SRC = ft_atoi.c ft_printf.c ft_putchar.c\ 
	  ft_putnbr_hex_low.c ft_putnbr_hex_low.c\
	  ft_putnbr_hex_up.c ft_putnbr_u.c ft_putnbr.c\
	  ft_putptr.c ft_putstr.c ft_strlen.c\ 
OBJ = $(SRC:.c=.o)

all: $(NAME)

.c.o: 
	@$(CC) $(CFLAGS) -c $< -o ${<:.c=.o}

$(NAME): $(OBJ)
	ar rcs $@ $(OBJ)

clean: 
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY:	all clean fclean
