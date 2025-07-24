# To test program, execute 'make run'.

FNC = ft_printf
NAME = libftprintf.a

INCL = include

MAIN = main.c

# ------------- #

HANDLERS = $(INCL)/print_char.c $(INCL)/print_dec_int.c \
			$(INCL)/print_hex.c	$(INCL)/print_pointer.c \
			$(INCL)/print_string.c $(INCL)/print_uint.c

SRC = ft_printf.c format_delegator.c $(HANDLERS)
# ------------- #

OBJ = $(SRC:.c=.o)

VALGRIND = valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --keep-stacktraces=alloc-and-free
CC = cc
CFLAGS = -Wall -Wextra -Werror

# ------------- #

all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)
	@echo Finished compiling.

%.o: %.c
	$(CC) $(CFLAGS) -I$(INCL) -c $< -o $@

list: $(NAME)
	@ar -t $(NAME) | sed 's/\.o/.c/g' | xargs -I% find . -name "%" | sed 's/\.\///g' | awk '{print "#include \"" $$1 "\""}'

download:
	@curl -o main.c https://raw.githubusercontent.com/maloryware/27tester-tests/refs/heads/main/ft_printf/framador/standard/main.c

.main: $(NAME) download
	$(CC) -g $(CFLAGS) $(MAIN) $(NAME) -o $(FNC)

run: $(NAME) .main
	clear; ./$(FNC)

debug: .main
	gdb ./$(FNC)

redo: re .main

redo_val: redo
	$(VALGRIND) ./$(FNC)

redo_val_full:
	$(CC) $(CFLAGS) -fsanitize=address -g -ggdb3 $(MAIN) $(NAME)
	$(VALGRIND) ./$(FNC)

clean:
	@rm -f $(OBJ) *.out

fclean: clean
	@rm -f $(NAME) $(FNC)

re: fclean all

.PHONY: all clean fclean re