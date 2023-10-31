NAME_C = client
NAME_S = server
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
INC = -I./include
SRC_DIR = ./src
SRCS_DIR_PRINTF = ./src/printf
FILES_C = client minitalk_utils
FILES_S = server minitalk_utils
FILES_PRINTF = ft_itoa ft_printf printf_utils

OBJS_C = $(addprefix $(SRC_DIR)/, $(addsuffix .o, $(FILES_C)))
OBJS_S = $(addprefix $(SRC_DIR)/, $(addsuffix .o, $(FILES_S)))
OBJS_PRINTF = $(addprefix $(SRCS_DIR_PRINTF)/, $(addsuffix .o, $(FILES_PRINTF)))

all: $(NAME_C) $(NAME_S)

%.o: %.c
	$(CC) $(INC) -c $< -o $@

$(NAME_C): $(OBJS_C) $(OBJS_PRINTF)
	$(CC) $(OBJS_C) $(OBJS_PRINTF) $(CFLAGS) $(INC) -o $(NAME_C)
$(NAME_S): $(OBJS_S) $(OBJS_PRINTF)	
	$(CC) $(OBJS_S) $(OBJS_PRINTF) $(CFLAGS) $(INC) -o $(NAME_S)

bonus: all

clean:
	$(RM) $(OBJS_C) $(OBJS_S) $(OBJS_PRINTF)

fclean: clean
	$(RM) $(NAME_C) $(NAME_S)

re: fclean all

.PHONY: all bonus clean fclean re