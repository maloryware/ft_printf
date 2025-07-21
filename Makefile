# To test program, execute 'make run'.

NAME = libftprintf.a

INCL = include

HNDL = $(INCL)/handler
LFT = $(INCL)/libft

MAIN = main.c

# ------------- #



LIBFT = $(INCL)/libft/get_next_line_utils.c $(INCL)/libft/get_next_line.c $(LFT)/ft_atoi.c $(LFT)/ft_bzero.c $(LFT)/ft_calloc.c $(LFT)/ft_isalnum.c $(LFT)/ft_isalpha.c $(LFT)/ft_isascii.c $(LFT)/ft_isdigit.c \
			$(LFT)/ft_isprint.c $(LFT)/ft_itoa.c $(LFT)/ft_memchr.c $(LFT)/ft_memcmp.c $(LFT)/ft_memcpy.c $(LFT)/ft_memmove.c $(LFT)/ft_memset.c \
			$(LFT)/ft_putchar_fd.c $(LFT)/ft_putendl_fd.c $(LFT)/ft_putnbr_fd.c $(LFT)/ft_putstr_fd.c $(LFT)/ft_split.c $(LFT)/ft_strchr.c \
			$(LFT)/ft_strdup.c $(LFT)/ft_striteri.c $(LFT)/ft_strjoin.c $(LFT)/ft_strlcat.c $(LFT)/ft_strlcpy.c $(LFT)/ft_strlen.c \
			$(LFT)/ft_strmapi.c $(LFT)/ft_strncmp.c $(LFT)/ft_strnstr.c $(LFT)/ft_strrchr.c $(LFT)/ft_strtrim.c $(LFT)/ft_substr.c \
			$(LFT)/ft_tolower.c $(LFT)/ft_toupper.c $(LFT)/ft_lstadd_back_bonus.c $(LFT)/ft_lstadd_front_bonus.c $(LFT)/ft_lstclear_bonus.c $(LFT)/ft_lstdelone_bonus.c \
			$(LFT)/ft_lstiter_bonus.c $(LFT)/ft_lstlast_bonus.c $(LFT)/ft_lstnew_bonus.c $(LFT)/ft_lstsize_bonus.c $(LFT)/ft_lstmap_bonus.c

SRC = ft_printf.c \
			$(HANDLERS) \
			$(INCL)/format_delegator.c \
			$(INCL)/aux.c \
			$(LIBFT)

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

tests:
	cc behaviour_tests.c && ./a.out

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

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME) $(TMAIN) $(LMAIN) usr_test.out main_test.out

re: fclean all

.PHONY: all clean fclean re