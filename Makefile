# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mrabenja <mrabenja@student.42antananari    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/12 16:58:24 by mrabenja          #+#    #+#              #
#    Updated: 2025/02/12 18:09:22 by mrabenja         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Reset
Color_Off=\033[0m

# Regular Colors
Black = \e[0;30m
Red = \e[0;31m
Green = \e[0;32m
Yellow = \e[0;33m
Blue = \e[0;34m
Purple = \e[0;35m
Cyan = \e[0;36m
White = \e[0;37m

# Bold
BBlack = \e[1;30m
BRed = \e[1;31m
BGreen = \e[1;32m
BYellow = \e[1;33m
BBlue = \e[1;34m
BPurple = \e[1;35m
BCyan = \e[1;36m
BWhite = \e[1;37m

# Background
On_Black = \e[40m
On_Red = \e[41m
On_Green = \e[42m
On_Yellow = \e[43m
On_Blue = \e[44m
On_Purple = \e[45m
On_Cyan = \e[46m
On_White = \e[47m

define GP_NAME
 ▄▄▄  ■  ▗▞▀▜▌▗▞▀▘█  ▄     █  ▐▌▄▄▄▄     ▐▌▗▞▀▚▖ ▄▄▄ ▗▞▀▀▘█  ▄▄▄  ▄   ▄ 
▀▄▄▗▄▟▙▄▖▝▚▄▟▌▝▚▄▖█▄▀      ▀▄▄▞▘█   █    ▐▌▐▛▀▀▘█    ▐▌   █ █   █ █ ▄ █ 
▄▄▄▀ ▐▌           █ ▀▄          █   █ ▗▞▀▜▌▝▚▄▄▖█    ▐▛▀▘ █ ▀▄▄▄▀ █▄█▄█ 
     ▐▌           █  █                ▝▚▄▟▌          ▐▌   █             
     ▐▌                                                                 
                                                                        
                                                                        
endef	
export GP_NAME

define	CREATION
▗▞▀▚▖▄   ▄ ▗▞▀▚▖▗▞▀▘     ▄▄▄  █  ▄ 
▐▛▀▀▘ ▀▄▀  ▐▛▀▀▘▝▚▄▖    █   █ █▄▀  
▝▚▄▄▖▄▀ ▀▄ ▝▚▄▄▖        ▀▄▄▄▀ █ ▀▄ 
                              █  █ 
                                   
                                   
                                                     ░           ░                                           ░      
endef
export CREATION                                                                             
																		 
define WIPE_O
 ▄▄▄  ▗▖      ▗▖    ▄   ▄ ▄ ▄▄▄▄  ▗▞▀▚▖   ▐▌
█   █ ▐▌      ▗▖    █ ▄ █ ▄ █   █ ▐▛▀▀▘   ▐▌
▀▄▄▄▀ ▐▛▀▚▖▄  ▐▌    █▄█▄█ █ █▄▄▄▀ ▝▚▄▄▖▗▞▀▜▌
      ▐▙▄▞▘▀▄▄▞▘          █ █          ▝▚▄▟▌
                            ▀               
                                            
                                             
endef
export WIPE_O

define WIPE_ALL
▄▄▄▄     ▗▖   ■      ▄   ▄ ▄ ▄▄▄▄  ▗▞▀▚▖   ▐▌
█   █    ▗▖▗▄▟▙▄▖    █ ▄ █ ▄ █   █ ▐▛▀▀▘   ▐▌
█▄▄▄▀ ▄  ▐▌  ▐▌      █▄█▄█ █ █▄▄▄▀ ▝▚▄▄▖▗▞▀▜▌
█     ▀▄▄▞▘  ▐▌            █ █          ▝▚▄▟▌
▀            ▐▌              ▀               
                                             
                                                 
endef
export WIPE_ALL

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
	raycasting/solid_wall.c raycasting/texture_wall.c\
	raycasting/background.c \
	raycasting/texture.c \

OBJ = $(addprefix $(DIROBJ)/, $(SRC:.c=.o))

LIBFT = libft/libft.a
MINILIBX = ./minilibx-linux
LIBMLX = $(MINILIBX)/libmlx.a

LINKING_FLAGS = -Lmlx -L/usr/lib/X11 -lXext -lX11

SPINNER = /tmp/spinner.sh
✔ = \033[0;32m✔\033[0m

all:
	@clear
	@echo "$(BYellow)"
	@echo "$$GP_NAME"
	@echo "$(Color_Off)"
	@$(MAKE) $(NAME) --no-print-directory

$(DIROBJ):
	@mkdir -p $(DIROBJ)
	@mkdir -p $(DIROBJ)/print_hello_world
	@mkdir -p $(DIROBJ)/parsing
	@mkdir -p $(DIROBJ)/window
	@mkdir -p $(DIROBJ)/key
	@mkdir -p $(DIROBJ)/raycasting

$(MINILIBX):
	@echo "Cloning MinilibX..."
	@git clone https://github.com/42Paris/minilibx-linux.git >/dev/null 2>&1
	@echo "$(✔) MinilibX cloned successfully"

$(DIROBJ)/%.o: $(DIRSRC)/%.c $(DIROBJ) $(MINILIBX)
	@$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@ >/dev/null 2>&1

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
	@$(SPINNER) make  -s -C libft --no-print-directory 

$(LIBMLX): $(SPINNER) $(MINILIBX)
	@$(SPINNER) make -s -C $(MINILIBX) 2> /dev/null
	@echo "$(✔) Minilibx compiled successfully"

$(NAME): $(OBJ) $(LIBMLX) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(LIBMLX) $(LINKING_FLAGS) -o $(NAME) -lm >/dev/null 2>&1
	@echo "$(✔) Compiled successfully"

clean: $(SPINNER)
	@clear
	@echo "$(Red)"
	@echo "$$CLEAR$$WIPE_O"
	@echo "$(Color_Off)"
	@$(SPINNER) sleep 0.7
	@rm -rf libft/obj >/dev/null 2>&1
	@rm -rf $(DIROBJ) >/dev/null 2>&1
	@echo "$(✔) Cleaned object files successfully"

fclean: clean
	@clear
	@echo "$(BRed)"
	@echo "$$WIPE_ALL"
	@echo "$(Color_Off)"
	@$(SPINNER) sleep 0.7
	@rm -f $(SPINNER) >/dev/null 2>&1
	@rm -f $(LIBFT) >/dev/null 2>&1
	@rm -f $(NAME) >/dev/null 2>&1
	@rm -rf $(MINILIBX) >/dev/null 2>&1
	@echo "$(✔) Cleaned successfully"

rm_minilibx:
	@rm -rf $(MINILIBX) >/dev/null 2>&1
	@echo "$(✔) Minilibx removed successfully"

re: fclean all

.PHONY: all clean fclean re