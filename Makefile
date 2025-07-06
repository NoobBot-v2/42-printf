CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
OBJ_DIR = obj

SRC = \
	src/ft_helper.c \
	src/ft_parse_fmt.c \
	src/ft_print_fmt_char.c \
	src/ft_print_fmt_hex.c \
	src/ft_print_fmt_number.c \
	src/ft_print_fmt_ptr.c \
	src/ft_print_fmt_string.c \
	src/ft_print_fmt_unsigned.c \
	src/ft_print_format.c \
	src/ft_printf.c \
	src/ft_to_hexbase.c \
	src/ft_to_hexptr.c \
	src/ft_unsigned_itoa.c

LIBFT = \
	libft/ft_atoi.c \
	libft/ft_isalnum.c \
	libft/ft_isalpha.c \
	libft/ft_isascii.c \
	libft/ft_isdigit.c \
	libft/ft_isprint.c \
	libft/ft_itoa.c \
	libft/ft_putchar_fd.c \
	libft/ft_putstr_fd.c \
	libft/ft_strchr.c \
	libft/ft_strlen.c \
	libft/ft_substr.c \
	libft/ft_tolower.c \
	libft/ft_toupper.c \
	libft/ft_strdup.c

SRCS = $(SRC) $(LIBFT)

# Generate corresponding object files
OBJS = $(SRCS:.c=.o)
OBJS := $(patsubst %, $(OBJ_DIR)/%, $(notdir $(OBJS)))

# Default target
all: $(NAME)

# Bonus rule does the same as all
bonus: all

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

# Compile src and libft files into obj
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

# Test files
TEST_DIR = tests
TEST_FILES = \
	test_42printf_flags.c \
	test_42printf_specifiers.c \
	test_hexbase.c \
	test_parse_fmt.c \
	test_print_char.c \
	test_print_hex.c \
	test_print_number.c \
	test_print_ptr.c \
	test_print_str.c \
	test_print_unsigned.c \
	test_42printf_zero.c

TEST_BINS = $(patsubst %.c, $(TEST_DIR)/%, $(TEST_FILES))

# Rule to build all test binaries
tests: $(TEST_BINS)

# Rule to compile each test file into its own binary
$(TEST_DIR)/test_%: $(TEST_DIR)/test_%.c $(NAME)
	$(CC) $(CFLAGS) $< $(NAME) -I. -o $@
	@echo "✅ Built $@"

# Clean test binaries
clean_tests:
	rm -f $(TEST_BINS)

.PHONY: all bonus clean fclean re tests clean_tests
