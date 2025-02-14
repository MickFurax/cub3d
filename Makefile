# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arabeman <arabeman@student.42antananari    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/12 16:58:24 by mrabenja          #+#    #+#              #
#    Updated: 2025/02/14 15:07:51 by arabeman         ###   ########.fr        #
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

define	WIPE_MAX
▗▖ ▗▖▄ ▄▄▄▄  ▄ ▄▄▄▄        ▗▞▀▚▖▄   ▄ ▗▞▀▚▖ ▄▄▄ ▄   ▄    ■  ▐▌   ▄ ▄▄▄▄    
▐▌ ▐▌▄ █   █ ▄ █   █       ▐▛▀▀▘█   █ ▐▛▀▀▘█    █   █ ▗▄▟▙▄▖▐▌   ▄ █   █   
▐▌ ▐▌█ █▄▄▄▀ █ █   █       ▝▚▄▄▖ ▀▄▀  ▝▚▄▄▖█     ▀▀▀█   ▐▌  ▐▛▀▚▖█ █   █   
▐▙█▟▌█ █     █     ▗▄▖                          ▄   █   ▐▌  ▐▌ ▐▌█     ▗▄▖ 
       ▀          ▐▌ ▐▌                          ▀▀▀    ▐▌            ▐▌ ▐▌
                   ▝▀▜▌                                                ▝▀▜▌
                  ▐▙▄▞▘                                               ▐▙▄▞▘
endef
export WIPE_MAX                                                                             

NAME = cub3d
NAMEBONUS = cub3d_bonus
CC = gcc
CFLAGS = -Wall -Wextra -Werror

DIRSRC = src
DIRBONUS = bonus/src
DIROBJ = tmp

MAIN = $(DIRSRC)/main.c

#* Update $(DIROBJ) when adding new source files
#* Source directory inclusion not required (src)
SRC = main.c \
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

SRCBONUS = $(SRC) \
	minimap/minimap.c \
	minimap/render_minimap.c \
	minimap/player.c \
	minimap/wall.c \
	minimap/move.c \
	
OBJ = $(addprefix $(DIROBJ)/, $(SRC:.c=.o))
OBJBONUS = $(addprefix $(DIROBJ)/, $(SRCBONUS:.c=.o))

LIBFT = libft/libft.a
MINILIBX = ./minilibx-linux
LIBMLX = $(MINILIBX)/libmlx.a

LINKING_FLAGS = -Lmlx -L/usr/lib/X11 -lXext -lX11

SPINNER = /tmp/spinner.sh
✔ = \033[0;32m✔\033[0m

all: $(NAME)

bonus: $(NAMEBONUS)

$(DIROBJ):
	@mkdir -p $(DIROBJ)
	@mkdir -p $(DIROBJ)/parsing
	@mkdir -p $(DIROBJ)/window
	@mkdir -p $(DIROBJ)/key
	@mkdir -p $(DIROBJ)/raycasting
	@mkdir -p $(DIROBJ)/minimap

$(MINILIBX):
	@echo "Cloning MinilibX..."
	@git clone https://github.com/42Paris/minilibx-linux.git >/dev/null
	@echo "$(✔) MinilibX cloned successfully"

$(DIROBJ)/%.o: $(DIRSRC)/%.c $(DIROBJ) $(MINILIBX)
	@$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@ >/dev/null

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
	@$(SPINNER) make   -C libft --no-print-directory 

$(LIBMLX): $(SPINNER) $(MINILIBX)
	@$(SPINNER) make  -C $(MINILIBX) 2> /dev/null
	@echo "$(✔) Minilibx compiled successfully"

$(NAME): $(OBJ) $(LIBMLX) $(LIBFT)
	@echo "$(BYellow)"
	@echo "$$GP_NAME"
	@echo "$(Color_Off)"
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(LIBMLX) $(LINKING_FLAGS) -o $(NAME) -lm >/dev/null
	@echo "$(✔) Project successfully compiled"

$(NAMEBONUS) : $(OBJBONUS) $(LIBMLX) $(LIBFT)
	@echo "$(BYellow)"
	@echo "$$GP_NAME"
	@echo "$(Color_Off)"
	@$(CC) $(CFLAGS) $(OBJBONUS) $(LIBFT) $(LIBMLX) $(LINKING_FLAGS) -o $(NAMEBONUS) -lm >/dev/null
	@echo "$(✔) Bonus project successfully compiled"

clean: $(SPINNER)
	@echo "$(Purple)"
	@echo "$$CLEAR$$WIPE_O"
	@echo "$(Color_Off)"
	@$(SPINNER) sleep 0.7
	@rm -rf libft/obj >/dev/null
	@rm -rf $(DIROBJ) >/dev/null
	@echo "$(✔) Object files successfully cleaned"

fclean: clean
	@echo "$(BPurple)"
	@echo "$$WIPE_ALL"
	@echo "$(Color_Off)"
	@$(SPINNER) sleep 0.7
	@rm -f $(SPINNER) >/dev/null
	@rm -f $(LIBFT) >/dev/null
	@rm -f $(NAME) $(NAMEBONUS) >/dev/null
	@echo "$(✔) Project successfully cleaned"

wipe_all: fclean
	@echo "$(BRed)"
	@echo "$$WIPE_MAX"
	@echo "$(Color_Off)"
	@rm -rf $(MINILIBX) >/dev/null
	@echo "$(✔) Minilibx removed successfully"
	@echo "$(✔) Everything wiped out"
re: fclean all

.PHONY: all clean fclean re wipe_all