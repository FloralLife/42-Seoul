CC = gcc
CFLAGS = -Wall -Werror -Wextra
NAME = libftprintf.a
AR = ar cr

FILES = $(addprefix ./,	\
	ft_printf	\
	print_char	\
	print_string	\
	print_number	\
	)

SRCS = $(addsuffix .c, $(FILES))

OBJS = $(SRCS:%.c=%.o)

.PHONY: all clean fclean re

all : $(NAME)

$(NAME) : $(OBJS)
	$(AR) $@ $^

%.o : %.c
	$(CC) $(CFLAGS) -c $< -I ./ -o $@

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all
