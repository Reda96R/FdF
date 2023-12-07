OS = $(shell uname -s)
NAME = fdf
BONUS = fdf_bonus
FILES = ft_helpers.c ft_maps_reader.c ft_reader_tools.c ft_checkers.c ft_janitor.c\
		ft_maps_drawer.c ft_colors_converter.c ft_menu.c ft_keylogger.c ft_app_keys.c
MYLIB = mylib/mylib.a
MYPRINT = mylib/ft_printf/ft_printf.a
BONUS_M = fdf_b.c
OBJS = $(FILES:.c=.o)
OBJS_M = $(FILES_M:.c=.o)
BM_OBJS = $(BONUS_M:.c=.o)
CFLAGS = -Wall -Wextra -Werror #-g -fsanitize=address

ifeq ($(OS), Darwin)
FILES_M = fdf.c
COMP = -lmlx -framework OpenGL -framework AppKit
COMP_O = -Imlx
else
FILES_M = fdf.c
COMP = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
COMP_O = -I/usr/include -Imlx_linux
endif

all: os $(NAME)

bonus: os $(BONUS)

$(NAME): $(OBJS) $(OBJS_M)
	@echo $(CURSIVE)$(GRAY) ":::Compiling $(NAME):::" $(NONE)
	@cc $(CFLAGS) $(OBJS) $(OBJS_M) $(MYLIB) $(MYPRINT) $(COMP) -o $(NAME)
	@echo $(GREEN)"::: $(NAME) is ready:::"$(NONE)

$(BONUS): $(OBJS) $(BM_OBJS)
	@echo $(CURSIVE)$(GRAY) ":::Compiling $(BONUS):::" $(NONE)
	@cc $(CFLAGS) $(OBJS) $(BM_OBJS) $(MYLIB) $(MYPRINT) $(COMP) -o $(BONUS)
	@echo $(GREEN)":::Compiled:::"$(NONE)

$(OBJS): $(FILES)
	@echo $(CURSIVE)$(GRAY) ":::Making object files:::" $(NONE)
	@make -s -C mylib/
	@cc $(CFLAGS) $(COMP_O) -c $(FILES)
	@echo $(GREEN)":::Done:::"$(NONE)

$(OBJS_M): $(FILES_M)
	@cc $(CFLAGS) -c $(FILES_M)

$(BM_OBJS): $(BONUS_M)
	@cc $(CFLAGS) -c $(BONUS_M)

clean:
	@echo $(CURSIVE)$(GRAY) ":::Deleting object files:::" $(NONE)
	@rm -f $(OBJS) $(B_OBJS) $(OBJS_M) $(BM_OBJS)
	@make -s clean -C mylib/
	@echo $(RED)":::Deleted:::"$(NONE)


fclean: clean
	@echo $(CURSIVE)$(GRAY) ":::Deleting executables:::" $(NONE)
	@rm -f $(NAME) $(BONUS)
	@make -s fclean -C mylib/
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
