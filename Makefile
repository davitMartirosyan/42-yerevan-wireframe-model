NAME = fdf
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
FRAME_FLAGS = -lmlx -framework OpenGL -framework AppKit
G_FLAG = -Imlx
S_DIR = src/
LIBFT = libft/libft.a
SOURCE = $(wildcard $(S_DIR)*.c)
OBJECT = $(patsubst %.c, %.o, $(SOURCE))
all : $(NAME)

$(NAME) : $(OBJECT)
	@$(CC) $(OBJECT) $(FRAME_FLAGS) $(LIBFT) -o $(NAME)

%.o : %.c header.h
	@echo "Compiling $<"
	@$(CC) $(CFLAGS) $(G_FLAG) -c $< -o $@

clean : 
	@rm $(S_DIR)*.o
	@echo "Object Files Was Cleaned"

fclean :
	@rm -f $(NAME)
	@echo "Executable $(NAME) Was Removed"