NAME		=	so_long
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
	so_long			\
	validate		\
	read_map		\
	draw			\
	get_next_line	\
	key_input		\
	enemy			\
	utils			\
	factory			\
	ft_itoa			\
	free			\
	print			\
	error			\
)
SRCS	=	$(addsuffix .c, $(FILES))
OBJS	=	$(SRCS:%.c=%.o)

.PHONY : all clean fclean re

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $^ $(LIBFT) $(MLXFLAGS) $(CFLAGS) -I $(INCLUDE) -o $(NAME)
	@printf "${FG_GREEN}build success\n${NO_COLOR}"

%.o : %.c
	$(CC) $(CFLAGS) -I ./mlx -I $(INCLUDE) -c $< -o $@

play : all
	@printf "${FG_LBLUE}PLAY!!!!\n${NO_COLOR}"
	@./$(NAME) maps/map.ber

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)
	$(RM) *.out

re : fclean all

bonus : all
	@./$(NAME) maps/map_bonus.ber
	@printf "${FG_LBLUE}PLAY!!!!\n${NO_COLOR}"
