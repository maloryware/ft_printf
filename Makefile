# To test program, execute 'make run'. #

NAME = libftprintf.a

ETC = etc

LIBS = $(ETC)/stdlibs
PRNT = $(ETC)/printers

LMAIN = __main_tests.c
TMAIN = __usr_tests.c

# ------------- #

STDLIBS = $(LIBS)/mini_libft.c $(LIBS)/substr.c \
			$(LIBS)/atoi.c $(LIBS)/itoa.c

PRINTERS = $(PRNT)/print_char.c $(PRNT)/print_dec_int.c \
			$(PRNT)/print_hex.c $(PRNT)/print_pointer.c \
			$(PRNT)/print_string.c $(PRNT)/print_uint.c

SRC = ft_printf.c \
			$(STDLIBS) $(PRINTERS) \
			$(ETC)/format_delegator.c \
			$(ETC)/aux.c

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
	$(CC) $(CFLAGS) -I$(ETC) -c $< -o $@

list: $(NAME)
	@ar -t $(NAME) | sed 's/\.o/.c/g' | awk '{print "#include \"" $$1 "\""}'

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

lmain: $(LMAIN)

$(LMAIN):
	@curl -o $(LMAIN) 'https://raw.githubusercontent.com/maloryware/ft_printf/refs/heads/main/__main_tests.c'

tmain: $(TMAIN)

$(TMAIN):
	@curl -o $(TMAIN) 'https://raw.githubusercontent.com/maloryware/ft_printf/refs/heads/main/__usr_tests.c'

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME) $(TMAIN) $(LMAIN) usr_test.out main_test.out

re: fclean all

.PHONY: all clean fclean re