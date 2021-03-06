
#LIBFT_DIR = libft
#LIBPROTOCOL_DIR = libprotocol
NAME =	opgl
#LFTFLAGS = -L $(LIBFT_DIR) -lft
#LPROTOCOLFLAGS = -L $(LIBPROTOCOL_DIR) -lprotocol
OBJSERV =$(SRCSERV:src/%.cpp=.obj/%.o)
SRCSERV = 	src/main.cpp \
		src/loadShader.cpp \
		src/init_vertex.cpp \
		src/init_matrix.cpp \
		src/render_vertex.cpp \
		src/render_matrix.cpp

CC		=	clang++
FLAGS	=	-Wall -Werror -Wextra -O3

# OS NAME
OS := $(shell uname -s)

ifeq ($(OS),Darwin)
CC_CMD = $(CC) -o $@ $(OBJSERV) -L $(HOME)/.brew/lib -lglfw3 -lGLEW -framework OpenGL #-DAPPLE#$(LPROTOCOLFLAGS) $(LFTFLAGS) 
OBJ_CMD = $(CC) $(FLAGS) -o $@ -c $< $(INC)
INC		=	-Iinc -I$(HOME)/.brew/include #-Ilibprotocol/includes -Ilibft/includes
endif
ifeq ($(OS),Linux)
INC		=	-Iinc #-Ilibprotocol/includes -Ilibft/includes
CC_CMD = $(CC) -o $@ $(OBJSERV) -lglfw -lGLEW -lGL#$(LPROTOCOLFLAGS) $(LFTFLAGS) -Wl,--no-as-needed
OBJ_CMD = $(CC) $(FLAGS) -o $@ -c $< $(INC)
endif


.PHONY: all re clean fclean

all: $(NAME)

$(NAME): $(OBJSERV) #$(LIBFT_DIR)/libft.a $(LIBPROTOCOL_DIR)/libprotocol.a
	$(CC_CMD)

.obj/%.o: src/%.cpp
	@mkdir -p .obj/
	$(OBJ_CMD)

#$(LIBFT_DIR)/libft.a:
#	@(cd $(LIBFT_DIR) && $(MAKE))

#$(LIBPROTOCOL_DIR)/libprotocol.a:
#	@(cd $(LIBPROTOCOL_DIR) && $(MAKE))

re: fclean all

clean:
#	make -C $(LIBFT_DIR) clean
#	make -C $(LIBPROTOCOL_DIR) clean
	rm -rf $(OBJ)

fclean:
#	make -C $(LIBFT_DIR) fclean
#	make -C $(LIBPROTOCOL_DIR) fclean
	rm -rf $(OBJ)
	rm -rf $(NAME)
