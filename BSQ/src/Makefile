# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpruvot <mpruvot@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/26 20:12:35 by mpruvot           #+#    #+#              #
#    Updated: 2024/02/28 17:22:56 by mpruvot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Define the output binary name
NAME	:= bsq

# Define the flags for the compiler
CFLAGS	:= -Wall -Wextra -Werror -g3

# Define the C compiler to use
CC	:= cc

# SOURCES

# List the source files without extension
SRC_FILES := main pack_everything parse_file read_input tools tools2 free ft_split magictrick quick_count wedidit parsing_struct control_maps

# Use addsuffix to generate object file names from source files
OBJ_FILES := $(addsuffix .o, $(SRC_FILES))

# List of header files
HEADERS := bsq.h

# RULES

# Default rule executed
all: $(NAME)

# Rule for making the binary and indirectly the object files
$(NAME): $(OBJ_FILES)
	$(CC) $(OBJ_FILES) -o $(NAME)

# Rule for converting .c files to .o files
# The compiler flags are applied here
%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

# Rule for removing object files
clean:
	rm -f $(OBJ_FILES)

# Rule for removing object files and the binary file
fclean: clean
	rm -f $(NAME)

# Rule for re-making everything
re: fclean all

# .PHONY tells make that these rules do not represent files
.PHONY: all clean fclean re
