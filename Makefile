NAME			=	philosophers.a
CC				=	cc
CFLAGS			=	-Werror -Wall -pthread -Wextra -g
SRC_DIR			=	src/
OBJ_DIR			=	obj/
AR				= 	ar rcs
SRC_FILES		=	main\
					utils/parsing_utils \
					create_threads

DEF_COLOR = \033[0;80m
GREEN = \033[0;92m

SRC = $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

OBJF = .cache_exists

all : $(NAME)

$(NAME): $(OBJ) #should make a library
	@$(AR) $(NAME) $(OBJ)
	@$(CC) $(CFLAGS) $(NAME) -o philosophers
	@echo "$(GREEN)philosophers compiled!$(DEF_COLOR)"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJF)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJF):
	@mkdir -p $(OBJ_DIR)
	@mkdir -p obj/utils

clean	:
		@rm -rf $(OBJ_DIR)

fclean	:	clean
		@rm -rf $(NAME)
		
re		: 	fclean all
		@echo "$(GREEN)Cleaned and rebuilt everything.$(DEF_COLOR)"
		
fclean	:	clean

.PHONY	:	all clean fclean re