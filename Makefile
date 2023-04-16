OS = $(shell uname -s)
NAME = fdf
BONUS = fdf_bonus
FILES = ft_helpers.c ft_maps_reader.c ft_split.c get_next_line.c get_next_line_utils.c
OBJS = $(FILES:.c=.o)
OBJS_M = $(FILES_M:.c=.o)
B_OBJS = $(BONUS_FILES:.c=.o)
CFLAGS = -Wall -Wextra -Werror #-g -fsanitize=address

ifeq ($(OS), Darwin)
FILES_M = fdf.c
COMP = -lmlx -framework OpenGL -framework AppKit
COMP_O = -Imlx
else
FILES_M = fdf_linux.c
COMP = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
COMP_O = -I/usr/include -Imlx_linux -O3
endif

all: os $(NAME)

bonus: $(BONUS)

$(NAME): $(OBJS) $(OBJS_M)
	@echo $(CURSIVE)$(GRAY) ":::Compiling $(NAME):::" $(NONE)
	@cc $(CFLAGS) $(COMP) $(OBJS) $(OBJS_M) -o $(NAME)
	@echo $(GREEN)"::: $(NAME) is ready:::"$(NONE)

$(BONUS): $(B_OBJS) $(OBJS)
	@echo $(CURSIVE)$(GRAY) ":::Compiling $(BONUS):::" $(NONE)
	@cc $(CFLAGS) $(B_OBJS) $(OBJS) -o $(BONUS)
	@echo $(GREEN)":::Compiled:::"$(NONE)

$(OBJS): $(FILES)
	@echo $(CURSIVE)$(GRAY) ":::Making object files:::" $(NONE)
	@cc $(CFLAGS) $(COMP_O) -c $(FILES)
	@echo $(GREEN)":::Done:::"$(NONE)

$(OBJS_M): $(FILES_M)
	@cc $(CFLAGS) -c $(FILES_M)

$(B_OBJS): $(BONUS_FILES)
	@echo $(CURSIVE)$(GRAY) ":::Making object files:::" $(NONE)
	@cc $(CFLAGS) -c $(BONUS_FILES)
	@echo $(GREEN)":::Done:::"$(NONE)

clean:
	@echo $(CURSIVE)$(GRAY) ":::Deleting object files:::" $(NONE)
	@rm -f $(OBJS) $(B_OBJS) $(OBJS_M)
	@echo $(RED)":::Deleted:::"$(NONE)


fclean: clean
	@echo $(CURSIVE)$(GRAY) ":::Deleting executables:::" $(NONE)
	@rm -f $(NAME) $(BONUS)
	@echo $(RED)":::All deleted:::"$(NONE)

re: fclean all

.PHONY:all clean fclean re bonus

NONE='\033[0m'
GREEN='\033[32m'
GRAY='\033[2;37m'
RED = '\033[1;31m'
YELLOW = '\033[1;33m'
CURSIVE='\033[3m'


os : 
	@echo $(YELLOW) "         _             _                  _      " $(NONE)
	@echo $(YELLOW) "        /\ \          /\ \               /\ \    " $(NONE)
	@echo $(YELLOW) "       /  \ \        /  \ \____         /  \ \   " $(NONE)
	@echo $(YELLOW) "      / /\ \ \      / /\ \_____\       / /\ \ \  " $(NONE)
	@echo $(YELLOW) "     / / /\ \_\    / / /\/___  /      / / /\ \_\ " $(NONE)
	@echo $(YELLOW) "    / /_/_ \/_/   / / /   / / /      / /_/_ \/_/ " $(NONE)
	@echo $(YELLOW) "   / /____/\     / / /   / / /      / /____/\    " $(NONE)
	@echo $(YELLOW) "  / /\____\/    / / /   / / /      / /\____\/    " $(NONE)
	@echo $(YELLOW) " / / /          \ \ \__/ / /      / / /          " $(NONE)
	@echo $(YELLOW) "/ / /            \ \___\/ /      / / /           " $(NONE)
	@echo $(YELLOW) "\/_/              \/_____/       \/_/            " $(NONE)
	@echo $(GREEN) "                                       for $(OS)" $(NONE)
	@echo $(GREEN) "                                                  " $(NONE)
	@echo $(GREEN) "                                                  " $(NONE)
