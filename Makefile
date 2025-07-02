# To test program, execute 'make run'.

NAME = libftprintf.a

INCL = include

HNDL = $(INCL)/handler
LIBFT = $(INCL)/libft/libft.a


MAIN = main.c
LMAIN = __main_tests.c
TMAIN = __usr_tests.c

# ------------- #

HANDLERS = $(HNDL)/print_char.c $(HNDL)/print_dec_int.c \
			$(HNDL)/print_hex.c $(HNDL)/print_pointer.c \
			$(HNDL)/print_string.c $(HNDL)/print_uint.c

SRC = ft_printf.c \
			$(HANDLERS) \
			$(INCL)/format_delegator.c \
			$(INCL)/aux.c

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

run: lmain $(NAME)
	cc -o main_test.out $(LMAIN) $(NAME)
	@make clean
	@echo 
	@echo '|-----TEST-----|'
	@echo 
	@./main_test.out
	@echo
	@echo
	@echo '|-----TEST-----|'
	@echo

test: $(NAME) tmain
	cc -fsanitize=address -g -ggdb3 -o usr_test.out $(TMAIN) $(NAME)
	@make clean
	@./usr_test.out

debug: $(NAME) run
	cc -fsanitize=address -g -ggdb3 -o main_test.out $(LMAIN) $(NAME)
	@make clean
	@$(VALGRIND) ./main_test.out

$(MAIN):
	$(CC) $(CFLAGS) -g main.c $(NAME)

redo: re $(MAIN)

redo-val: redo
	$(VALGRIND) ./a.out

redo-valplus: re 
	$(CC) $(CFLAGS) -fsanitize=address -g -ggdb3 $(MAIN) $(NAME)
	$(VALGRIND) ./a.out

lmain: $(LMAIN)

$(LMAIN):
	@curl -o $(LMAIN) 'https://raw.githubusercontent.com/maloryware/27tester-tests/refs/heads/main/ft_printf/mal/bonus/main.c'

tmain: $(TMAIN)

$(TMAIN):
	@curl -o $(TMAIN) 'https://raw.githubusercontent.com/maloryware/27tester-tests/refs/heads/main/ft_printf/vivaz-ca/bonus/main.c'

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME) $(TMAIN) $(LMAIN) usr_test.out main_test.out

re: fclean all

.PHONY: all clean fclean re