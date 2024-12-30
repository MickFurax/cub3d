NAME = cub3d
CC = gcc
CFLAGS = -Wall -Wextra -Werror

DIRSRC = src
DIROBJ = tmp

MAIN = $(DIRSRC)/main.c

#* Update $(DIROBJ) when adding new source files
SRC = print_hello_world/print_hello_world.c \

OBJ = $(addprefix $(DIROBJ)/, $(SRC:.c=.o))

LIBFT = libft/libft.a

SPINNER = ./.spinner.sh

all: $(NAME)

$(SPINNER):
	@touch $@
	@chmod +x $@
	@echo '#!/bin/bash' > $@
	@echo "trap 'tput cnorm' EXIT" >> $@
	@echo "cursorBack() {" >> $@
	@echo '  echo -en "\\033[$$1D"' >> $@
	@echo "}" >> $@
	@echo "spinner() {" >> $@
	@echo '  local pid=$$1' >> $@
	@echo '  local message="Compiling libft"' >> $@
	@echo '  local spin="⠁⠂⠄⡀⢀⠠⠐⠈"' >> $@
	@echo '  local charwidth=$${#message}' >> $@
	@echo '  tput civis' >> $@
	@echo '  while kill -0 $$pid 2>/dev/null; do' >> $@
	@echo '    for ((i = 0; i < $${#spin}; i++)); do' >> $@
	@echo '      echo -n "$${spin:i:1} $$message"' >> $@
	@echo '      cursorBack $$((charwidth + 2))' >> $@
	@echo '      sleep 0.1' >> $@
	@echo '    done' >> $@
	@echo '  done' >> $@
	@echo '  tput cnorm' >> $@
	@echo '  wait $$pid' >> $@
	@echo '}' >> $@
	@echo '("$$@") & spinner $$!' >> $@

$(DIROBJ):
	@mkdir -p $(DIROBJ)
	@mkdir -p $(DIROBJ)/print_hello_world

$(DIROBJ)/%.o: $(DIRSRC)/%.c $(DIROBJ)
	@$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT): $(SPINNER)
	@$(SPINNER) make -C libft

$(NAME): $(OBJ) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJ) $(MAIN) $(LIBFT) -o $(NAME)
	@echo "\033[0;32m✔\033[0m Compiled successfully"

clean:
	@rm -f $(SPINNER)
	@rm -rf libft/obj
	@rm -rf $(DIROBJ)
	@echo "\033[0;32m✔\033[0m Cleaned object files successfully"

fclean: clean
	@rm -f $(LIBFT)
	@rm -f $(NAME)
	@rm -f $(SPINNER)
	@echo "\033[0;32m✔\033[0m Cleaned executable successfully"

re: fclean all


.PHONY: all clean fclean re

