NAME = cub3d
CC = gcc
CFLAGS = -Wall -Wextra -Werror

DIRSRC = src
DIROBJ = tmp

MAIN = $(DIRSRC)/main.c

#* Update $(DIROBJ) when adding new source files
#* Source directory inclusion not required (src)
SRC = main.c \
	print_hello_world/print_hello_world.c \
	parsing/ft_split_wsp.c \
	parsing/parsing1.c parsing/parsing2.c \
	parsing/free_map_config.c \
	window/window.c \
	key/key.c \
	raycasting/angle.c raycasting/frame.c \
	raycasting/move.c raycasting/raycasting.c \
	raycasting/wall.c 


OBJ = $(addprefix $(DIROBJ)/, $(SRC:.c=.o))

LIBFT = libft/libft.a
MINILIBX = ./minilibx-linux
LIBMLX = $(MINILIBX)/libmlx.a

LINKING_FLAGS = -Lmlx -L/usr/lib/X11 -lXext -lX11

SPINNER = /tmp/spinner.sh
✔ = \033[0;32m✔\033[0m

all: $(NAME)

$(DIROBJ):
	@mkdir -p $(DIROBJ)
	@mkdir -p $(DIROBJ)/print_hello_world
	@mkdir -p $(DIROBJ)/parsing
	@mkdir -p $(DIROBJ)/window
	@mkdir -p $(DIROBJ)/key
	@mkdir -p $(DIROBJ)/raycasting

$(MINILIBX):
	@git clone https://github.com/42Paris/minilibx-linux.git

$(DIROBJ)/%.o: $(DIRSRC)/%.c $(DIROBJ) $(MINILIBX)
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

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
	@echo '  local message="Loading"' >> $@
	@echo '  local spin="⠁⠂⠄⡀⢀⠠⠐⠈"' >> $@
	@echo '  local charwidth=$${#message}' >> $@
	@echo '  tput civis' >> $@
	@echo '  while kill -0 $$pid 2>/dev/null; do' >> $@
	@echo '    for ((i = 0; i < $${#spin}; i++)); do' >> $@
	@echo '      echo -n "$${spin:i:1} $$message"' >> $@
	@echo '      cursorBack $$((charwidth + 2))' >> $@
	@echo '      sleep 0.065' >> $@
	@echo '    done' >> $@
	@echo '  done' >> $@
	@echo '  tput cnorm' >> $@
	@echo '  wait $$pid' >> $@
	@echo '}' >> $@
	@echo '("$$@") & spinner $$!' >> $@

$(LIBFT): $(SPINNER)
	@$(SPINNER) make -C libft

$(LIBMLX): $(SPINNER) $(MINILIBX)
	@make -C $(MINILIBX) 2> /dev/null
	@echo "$(✔) Minilibx compiled successfully"

$(NAME): $(OBJ) $(LIBMLX) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(LIBMLX) $(LINKING_FLAGS) -o $(NAME) -lm
	@echo "$(✔) Compiled successfully"

clean:
	@rm -f $(SPINNER)
	@rm -rf libft/obj
	@rm -rf $(DIROBJ)
	@echo "$(✔) Cleaned object files successfully"

fclean: clean
	@rm -f $(LIBFT)
	@rm -f $(NAME)
	@[ -d "$(MINILIBX)" ] && make clean -C $(MINILIBX) || :
	@echo "$(✔) Cleaned successfully"

rm_minilibx:
	@rm -rf $(MINILIBX)
	@echo "$(✔) Minilibx removed successfully"

re: fclean all

.PHONY: all clean fclean re
