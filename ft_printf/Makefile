CC = gcc
CFLAGS = -Wall -Werror -Wextra
NAME = libft.a
AR = ar cr

FILES = $(addprefix ./,	)

SRCS = $(addsuffix .c, $(FILES))

OBJS = $(SRCS:%.c=%.o)

.PHONY: all clean fclean re

all : $(NAME)

$(NAME) : $(OBJ_FILES)
	$(AR) $@ $^

%.o : %.c
	$(CC) $(CFLAGS) -c $< -I ./includes -o $@

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all
