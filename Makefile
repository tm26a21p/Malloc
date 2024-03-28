##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## makefile
##

NAME		=	libmy_malloc.so

BIN			=	malloc

#########################################
############ COMPILIATION ###############
#########################################

CC		=	gcc

SRC_DIR		=	src/

SRC		=	$(SRC_DIR)my_malloc.c			\
			$(SRC_DIR)free.c			\
			$(SRC_DIR)calloc.c			\
			$(SRC_DIR)core.c			\
			$(SRC_DIR)realloc.c			\
			$(SRC_DIR)reallocarray.c			\
			# $(SRC_DIR)debug.c			\


OBJ		=	$(SRC:.c=.o)

CFLAGS		=	-Wall -Wextra -fPIC

CPPFLAGS 	=	-I./include

INCL		=	-I./include

#########################################
################# TESTS #################
#########################################

TESTS		=	unit_tests

GCOVR		=	gcovr

CRIT		=	-lcriterion

COVER		=	--coverage

BRANCH		=	--branches

EXCLUD		=	--exclude

TESTS_SRC	=	$(SRC_DIR)my_malloc.c			\

UNIT_TEST	=	tests/tests_my_malloc.c		\

#########################################
################# CLEAN #################
#########################################

RM		=	rm -f

#########################################
################# RULES #################
#########################################

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) -shared -fPIC -o $(NAME) $(OBJ) $(INCL)
db:	CFLAGS += -g3
db: $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LIB)

x:
	$(CC) -o $(BIN) $(INCL) $(SRC_DIR)main.c
	LD_PRELOAD=./$(NAME) ./$(BIN)

xdb:	$(OBJ)
	$(CC) -o $(BIN) $(INCL) $(OBJ) $(SRC_DIR)main.c -g3
	LD_PRELOAD=./$(NAME) gdb $(BIN)

ls:
	LD_PRELOAD=./$(NAME) ls

lsl:
	LD_PRELOAD=./$(NAME) ls -l

tree:
	LD_PRELOAD=./$(NAME) tree

unit_test:	fclean
	$(CC) -o $(TESTS) $(TESTS_SRC) $(UNIT_TEST) $(LIB)$(INCL) $(COVER) $(CRIT)

tests_run: 	unit_test
	./$(TESTS)
	$(GCOVR) $(EXCLUD) $(TESTS_DIR)
	$(GCOVR) $(EXCLUD) $(TESTS_DIR) $(BRANCH)

clean:
	$(RM) $(OBJ) *gc*

fclean:		clean
	$(RM) $(NAME) $(TESTS)
	$(RM) $(BIN)
	$(RM) vgcore*
re:	fclean all

redb:	fclean db

.PHONY:		all tests fclean re db redb
