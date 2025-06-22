CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC_DIRS = src libft
OBJ_DIR = obj

NAME = libftprintf.a

# Gather all .c files from both directories
SRCS = $(wildcard src/*.c) $(wildcard libft/*.c)

# Replace src/foo.c or libft/bar.c with obj/foo.o or obj/bar.o
OBJS = $(patsubst %.c, $(OBJ_DIR)/%.o, $(notdir $(SRCS)))

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $@ $^

# Compile each source file to obj/
$(OBJ_DIR)/%.o: src/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: libft/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
