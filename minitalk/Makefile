CC = gcc
CFLAGS = -Wall -Werror -Wextra
SERVER = server
CLIENT = client

FG_BLACK   = \e[30m
FG_RED     = \e[31m
FG_GREEN   = \e[32m
FG_YELLOW  = \e[33m
FG_LBLUE   = \e[94m
FG_MAGENTA = \e[35m
NO_COLOR   = \e[0m

SERVER_FILES = $(addprefix srcs/,	\
	server	\
)

CLIENT_FILES = $(addprefix srcs/,	\
	client	\
)

COMMON_FILES = $(addprefix srcs/,	\
	print	\
	utils	\
)

SERVER_SRCS = $(addsuffix .c, $(SERVER_FILES) $(COMMON_FILES))
CLIENT_SRCS = $(addsuffix .c, $(CLIENT_FILES) $(COMMON_FILES))

.PHONY: all clean fclean re

all : $(SERVER) $(CLIENT)

$(SERVER) : $(SERVER_SRCS)
	@$(CC) $(CFLAGS) $^ -I ./ -o $@
	@printf "${FG_GREEN}server build success\n${NO_COLOR}"

$(CLIENT) : $(CLIENT_SRCS)
	@$(CC) $(CFLAGS) $^ -I ./ -o $@
	@printf "${FG_GREEN}client build success\n${NO_COLOR}"

clean :
	@rm -f $(SERVER_OBJS) $(CLIENT_OBJS)
	@printf "${FG_LBLUE}clean success\n${NO_COLOR}"

fclean : clean
	@rm -f $(SERVER) $(CLIENT)
	@printf "${FG_LBLUE}fclean success\n${NO_COLOR}"

re : fclean all
