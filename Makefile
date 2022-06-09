NAME = fdf
CC = gcc
CFLAGS = -Wall -Wextra -Werror
FRAME_FLAGS = -lmlx -framework OpenGL -framework AppKit
G_FLAG = -Imlx
S_DIR = src/

SOURCE = $(wildcard $(S_DIR)*.c)
OBJECT = $(patsubst %.c, %.o, $(SOURCE))

all : $(NAME)

$(NAME) : $(OBJECT)
	@$(CC) $(OBJECT) $(FRAME_FLAGS) -o $(NAME)

%.o : %.c
	@echo "Compiling $<"
	@$(CC) $(CFLAGS) $(G_FLAG) -c $< -o $@

clean :
	@rm $(S_DIR)*.o
	@rm $(NAME)
	@echo "Cleaned"