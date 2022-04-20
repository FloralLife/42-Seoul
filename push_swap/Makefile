NAME		=	push_swap
NAME_BONUS	=	cheker
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

FILES_BONUS	=	$(addprefix srcs_bonus/,	\
	so_long_bonus		\
	validate_bonus		\
	read_map_bonus		\
	draw_bonus			\
	get_next_line_bonus	\
	key_input_bonus		\
	enemy_bonus			\
	utils_bonus			\
	factory_bonus		\
	ft_itoa_bonus		\
	free_bonus			\
	print_bonus			\
	error_bonus			\
)
SRCS	=	$(addsuffix .c, $(FILES))
OBJS	=	$(SRCS:%.c=%.o)

SRCS_BONUS	=	$(addsuffix .c, $(FILES_BONUS))
OBJS_BONUS	=	$(SRCS_BONUS:%.c=%.o)

.PHONY : all clean fclean re bonus

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $^ $(MLXFLAGS) $(CFLAGS) -I $(INCLUDE) -o $(NAME)
	@printf "${FG_GREEN}build success\n${NO_COLOR}"

%.o : %.c
	$(CC) $(CFLAGS) -I ./mlx -I $(INCLUDE) -c $< -o $@

clean :
	$(RM) $(OBJS)
	$(RM) $(OBJS_BONUS)

fclean : clean
	$(RM) $(NAME)
	$(RM) $(NAME_BONUS)
	$(RM) *.out

re : fclean all

bonus : $(NAME_BONUS)

$(NAME_BONUS) : $(OBJS_BONUS)
	$(CC) $^ $(MLXFLAGS) $(CFLAGS) -I $(INCLUDE) -o $(NAME_BONUS)
	@printf "${FG_GREEN}build success\n${NO_COLOR}"
