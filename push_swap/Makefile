NAME		=	push_swap
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
RM			=	rm -rf
INCLUDE		=	./includes/
MLXFLAGS	=	-L ./mlx/ -lmlx -framework OpenGL -framework AppKit

FG_BLACK	=	\e[30m
FG_RED		=	\e[31m
FG_GREEN	=	\e[32m
FG_YELLOW	=	\e[33m
FG_LBLUE	=	\e[94m
FG_MAGENTA	=	\e[35m
NO_COLOR	=	\e[0m

FILES	=	$(addprefix srcs/,	\
	main			\
	parse			\
	list			\
	cmd_list		\
	print			\
	error			\
	free			\
	validate		\
	stack			\
	sort			\
	sort_a			\
	sort_b			\
	command			\
	exec			\
	ft_atoi			\
	ft_split		\
	ft_strcmp		\
)

SRCS	=	$(addsuffix .c, $(FILES))
OBJS	=	$(SRCS:%.c=%.o)

.PHONY : all clean fclean re

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $^ $(CFLAGS) -I $(INCLUDE) -o $(NAME)
	@printf "${FG_GREEN}build success\n${NO_COLOR}"

%.o : %.c
	$(CC) $(CFLAGS) -I $(INCLUDE) -c $< -o $@

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)
	$(RM) *.out

re : fclean all
