CC = gcc
CFLAGS = -Wall -Werror -Wextra
NAME = libft.a
SRCDIR = srcs
FILES = $(addprefix $(SRCDIR)/, ft_memset ft_bzero ft_memcpy)
SRCS = $(addsuffix .c, $(FILES))
OBJS = $(addsuffix .o, $(FILES))

all : $(NAME)

$(NAME) : $(OBJS)
	ar cr $@ $^

%.o : %.c
	$(CC) -c $(CLFAGS) $< -I ./includes -o $@

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all
