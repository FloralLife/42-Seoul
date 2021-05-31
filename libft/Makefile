CC = gcc
CFLAGS = -Wall -Werror -Wextra
NAME = libft.a
SRCDIR = srcs
FILES = $(addprefix $(SRCDIR)/, ft_memset ft_bzero ft_memcpy ft_memccpy ft_nemmove ft_memchr ft_memcmp ft_strlen ft_strlcpy ft_strchr ft_strrchr ft_strnstr ft_calloc ft_strdup ft_substr ft_strjoin ft_strtrim ft_split ft_itoa ft_strmapi ft_putchar_fd ft_putendl_fd ft_putnbr_fd )
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
