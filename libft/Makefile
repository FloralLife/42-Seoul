CC = gcc
CFLAGS = -Wall -Werror -Wextra
NAME = libft.a
AR = ar cr

FILES = $(addprefix ./,\
	ft_memset		\
	ft_bzero		\
	ft_memcpy		\
	ft_memccpy		\
	ft_memmove		\
	ft_memchr		\
	ft_memcmp		\
	ft_strlen		\
	ft_strlcpy		\
	ft_strlcat		\
	ft_strchr		\
	ft_strrchr		\
	ft_strnstr		\
	ft_strncmp		\
	ft_atoi			\
	ft_isalpha		\
	ft_isdigit		\
	ft_isalnum		\
	ft_isascii		\
	ft_isprint 		\
	ft_toupper		\
	ft_tolower		\
	ft_calloc		\
	ft_strdup		\
	ft_substr		\
	ft_strjoin		\
	ft_strtrim		\
	ft_split		\
	ft_itoa			\
	ft_strmapi		\
	ft_putchar_fd	\
	ft_putstr_fd	\
	ft_putendl_fd	\
	ft_putnbr_fd	\
	)
FILES_BONUS = $(addprefix ./,\
	ft_lstnew		\
	ft_lstadd_front	\
	ft_lstsize		\
	ft_lstlast		\
	ft_lstadd_back	\
	ft_lstdelone	\
	ft_lstclear		\
	ft_lstiter		\
	ft_lstmap		\
)

SRCS = $(addsuffix .c, $(FILES))
SRCS_BONUS = $(addsuffix .c, $(FILES_BONUS))

OBJS = $(SRCS:%.c=%.o)
OBJS_BONUS = $(SRCS_BONUS:%.c=%.o)

ifdef WITH_BONUS
	OBJ_FILES = $(OBJS) $(OBJS_BONUS)
else
	OBJ_FILES = $(OBJS)
endif

.PHONY: all bonus clean fclean re

all : $(NAME)

$(NAME) : $(OBJ_FILES)
	$(AR) $@ $^

%.o : %.c
	$(CC) $(CFLAGS) -c $< -I ./includes -o $@

bonus :
	@make WITH_BONUS=1 all

clean :
	rm -f $(OBJS)
	rm -f $(OBJS_BONUS)

fclean : clean
	rm -f $(NAME)

re : fclean all
