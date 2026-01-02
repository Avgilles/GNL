NAME = get_next_line.a
CC = cc
CFLAGS = -Wall -Wextra -Werror 
INCLUDES = -I$(SRCS_DIR)
SRCS_DIR = get_next_line

SRCS = get_next_line.c \
	   get_next_line_utils.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar -rcs $@ $^

$(SRCS_DIR)/%.o: $(SRCS_DIR)/%.c
	$(CC) $(CFLAGS) -c $(INCLUDES) $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -f $(NAME)
re: fclean all

run: re
	$(CC) -g get_next_line.c $(NAME) $(INCLUDES) -o a.out
	clear
	./a.out

.PHONY: all clean fclean re run