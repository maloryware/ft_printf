NAME = libft.a

SRC_DIR = .
OBJ_DIR = .
INC_DIR = .

# TESTS = $(wildcard $(SRC_DIR)/__*__.c)
# CFILES = $(filter-out $(TESTS), $(wildcard $(SRC_DIR)/*.c))


GNL_CFILES = get_next_line/get_next_line.c get_next_line/get_next_line.h get_next_line/get_next_line_utils.c

GNL_BONUS_CFILES = get_next_line/get_next_line_bonus.c get_next_line/get_next_line_bonus.h get_next_line/get_next_line_utils_bonus.c 

CFILES = $(GNL_CFILES) ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
			ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c \
			ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c \
			ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c \
			ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c \
			ft_tolower.c ft_toupper.c

BONUS_CFILES = $(GNL_BONUS_CFILES) ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c ft_lstclear_bonus.c ft_lstdelone_bonus.c \
			ft_lstiter_bonus.c ft_lstlast_bonus.c ft_lstnew_bonus.c ft_lstsize_bonus.c ft_lstmap_bonus.c

OFILES = $(CFILES:.c=.o)
BONUS_OFILES = $(BONUS_CFILES:.c=.o)

CC = cc
CFLAGS = -Wextra -Wall -Werror


all: $(NAME) $(BONUS)

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@echo Compiling C files.
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

$(NAME): $(OFILES)
	@echo Compiling library with mandatory files.
	@ar rcs $(NAME) $(OFILES)

bonus: $(NAME) $(BONUS_OFILES) 
	@echo Compiling library with bonus C files.
	@ar rcs $(NAME) $(BONUS_OFILES) $(OFILES)

clean:
	@echo Cleaning obj files.
	@rm -f $(OBJ_DIR)/*.o

fclean: clean
	@echo Cleaning $(NAME).
	@rm -f $(NAME)

re: fclean all

.PHONY: re clean fclean all bonus