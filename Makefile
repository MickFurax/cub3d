NAME = cub3d
CC = gcc
CFLAGS = -Wall -Wextra -Werror

DIRSRC = src
DIROBJ = tmp

MAIN = $(DIRSRC)/main.c

SRC = print_hello_world/print_hello_world.c \

OBJ = $(addprefix $(DIROBJ)/, $(SRC:.c=.o))

all: $(NAME)

$(DIROBJ):
	@mkdir -p $(DIROBJ)
	@mkdir -p $(DIROBJ)/print_hello_world

$(DIROBJ)/%.o: $(DIRSRC)/%.c $(DIROBJ)
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(MAIN) -o $(NAME)
	@echo "\033[0;32m✔\033[0m Compiled successfully"

clean:
	@rm -rf $(DIROBJ)
	@echo "\033[0;32m✔\033[0m Cleaned object files successfully"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[0;32m✔\033[0m Cleaned executable successfully"

re: fclean all

.PHONY: all clean fclean re

