GCC = gcc
CFLAG = -Wall -Wextra -Werror -g

SRC = main.c grid.c get.c cfour.c play.c isend.c rand.c won.c two.c grade.c

INCLUDE = -I libft/include -I printf/include -I includes

#INC = $(addprefix -I , %) 

DEP = Makefile libft/src libft/include libft/Makefile printf/src printf/include printf/Makefile

NAME = puissance4

LIBS = libft\
	   printf

LIBSA = $(patsubst %, %/libft.a, $(LIBS))

OBJ = $(SRC:.c=.o)

all: $(NAME)

%.o: $(addprefix src/, %.c)  $(LIBSA)
	    $(GCC) $(CFLAG) $(INCLUDE) -c $< -o $@

$(NAME): $(OBJ) $(LIBSA) $(DEP)
	    $(GCC) $(CFLAG) -o $@ $(OBJ) $(LIBSA) $(INCLUDE)
%/libft.a: %/ $(DEP)
	    @make -C $<

clean: $(LIBS)
	    @rm -rf $(OBJ)
		    @$(foreach di, $(LIBS) , make fclean -C $(di);)

fclean: clean
	    @rm -rf $(NAME)

re: fclean all
