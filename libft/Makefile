CC = gcc
CFLAGS = -Wall -Werror -Wextra
NAME = libft.a

FILES = $(addprefix srcs/, ft_memset ft_bzero ft_memcpy ft_memccpy ft_memmove ft_memchr ft_memcmp ft_strlen ft_strlcpy ft_strchr ft_strrchr ft_strnstr ft_calloc ft_strdup ft_substr ft_strjoin ft_strtrim ft_split ft_itoa ft_strmapi ft_putchar_fd ft_putendl_fd ft_putnbr_fd )
FILES_BONUS = $(addprefix srcs_bonus/, ft_lstnew ft_lstadd_front ft_lstsize ft_lstlast ft_lstadd_back ft_lstdelone ft_lstclear ft_lstiter ft_lstmap)

SRCS = $(addsuffix .c, $(FILES))
SRCS_BONUS = $(addsuffix .c, $(FILES_BONUS))

OBJS = $(addsuffix .o, $(FILES))
OBJS_BONUS = $(addsuffix .o, $(FILES_BONUS))


all : $(NAME)

$(NAME) : $(OBJS)
	ar cr $@ $^

%.o : %.c
	$(CC) $(CFLAGS) -c $< -I ./includes -o $@

bonus : $(OBJS_BONUS)
	ar cr $(NAME) $<

clean :
	rm -f $(OBJS)
	rm -f $(OBJS_BONUS)

fclean : clean
	rm -f $(NAME)

re : fclean all
