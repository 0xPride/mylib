CC = clang
NAME= mylib
MAKEFLAGS += --no-print-directory

INCLUDE = -I include 
CFLAGS = $(INCLUDE) #-Wall -Werror -Wextra

OBJS_DIR = objs/

SRC_DIR = src/
SRC_FILES = main.c

LIST_DIR = $(SRC_DIR)list/
LIST_FILES = create.c insert.c

CFILES = $(addprefix $(SRC_DIR), $(SRC_FILES))
CFILES += $(addprefix $(LIST_DIR), $(LIST_FILES))

OFILES_ = $(patsubst %.c, %.o, $(CFILES))
OFILES = $(addprefix $(OBJS_DIR), $(OFILES_))

all: $(NAME)

$(NAME): $(OFILES)
	@echo "$(green)source files compiled successfully \n $(reset)"
	@echo "$(yellow)linking object files.. $(reset)"

	@$(CC) $(CFLAGS) $(MLX_FLAGS) $(LIBS) $(OFILES) -o $(NAME)

	@echo "$(green)All done, binary file path: ./$(NAME)$(reset)"

fsanitize: CFLAGS += -fsanitize=address -g
fsanitize: re all
	@echo "$(red)fsanitize activated $(reset)"

debug: CFLAGS += -g
debug: re all

error: CFLAGS += -Wall -Werror -Wextra
error: re all

$(OBJS_DIR)%.o:%.c
	@echo "$(yellow)Compiling $(reset)$<"
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

re: fclean all

fclean: clean
	@echo "$(yellow)Cleaning Library file... $(reset)"
	@rm -f $(NAME)
	@echo "$(green)Library file cleaned \n $(reset)"

clean:
	@echo "$(yellow)Cleaning object files... $(reset)"
	@rm -f $(OFILES)
	@rm -rf $(OBJS_DIR)
	@echo "$(green)object files cleaned \n $(reset)"

.PHONY: clean fclean re

# colors
yellow=`tput setaf 3`
green=`tput setaf 2`
red=`tput setaf 1`
reset=`tput sgr0`
