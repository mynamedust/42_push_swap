NAME	=	push_swap
S_DIR	=	src/
O_DIR	=	obj/
SRC		=	main.c		operations.c	sort_utils.c\
			sorting.c	stack_create.c	utils.c\
			operations_utils.c
OBJ		=	$(SRC:.c=.o)
SRCS	= 	$(addprefix $(S_DIR), $(SRC))
OBJS	=	$(addprefix $(O_DIR), $(OBJ))

NAME_B	=	checker
SB_DIR	=	src_b/
OB_DIR	=	obj_b/
SRC_B	=	checker.c	get_next_line.c	get_next_line_utils.c\
			utils.c		operations.c	sort_utils.c\
			sorting.c	stack_create.c	operations_utils.c
OBJ_B	=	$(SRC_B:.c=.o)
SRCS_B	= 	$(addprefix $(SB_DIR), $(SRC_B))
OBJS_B	=	$(addprefix $(OB_DIR), $(OBJ_B))

INC		=	-I ./includes/
CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror

all: $(O_DIR) $(NAME)

$(O_DIR)%.o : $(S_DIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INC)

$(O_DIR):
	mkdir $(O_DIR)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

bonus: all $(OB_DIR) $(NAME_B) 

$(OB_DIR)%.o : $(SB_DIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INC)

$(OB_DIR):
	mkdir $(OB_DIR)

$(NAME_B): $(OBJS_B)
	$(CC) $(CFLAGS) $(OBJS_B) -o $(NAME_B)

clean:
	rm -rf $(O_DIR) $(OB_DIR)

fclean: clean
	rm -f $(NAME) $(NAME_B)

re : fclean all

.PHONY : all clean fclean re bonus