# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/01 16:34:28 by marvin            #+#    #+#              #
#    Updated: 2024/07/01 16:58:27 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler
CC = gcc
# Compiler flags
CFLAGS = -Wall -Wextra -Werror -g3
# Directories
SRCDIR = srcs
INCDIR = includes
OBJDIR = obj

# Source files
SRC := $(wildcard $(SRCDIR)/*.c)
# Object files
OBJ := $(SRC:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
# Header files
HEADERS := $(wildcard $(INCDIR)/*.h)

# Output executable
TARGET = star_walking

# ANSI color codes
GREEN = \033[0;32m
YELLOW = \033[0;33m
RED = \033[0;31m
RESET = \033[0m

# Checkmark symbol
CHECKMARK = ✔

# Default target
all: $(TARGET)
	@echo "$(GREEN)$(CHECKMARK) Executable $(TARGET) built!$(RESET)"

# Linking the executable
$(TARGET): $(OBJ)
	@$(CC) $(CFLAGS) $^ -o $@

# Compiling source files into object files
$(OBJDIR)/%.o: $(SRCDIR)/%.c $(HEADERS) | $(OBJDIR)
	@echo "$(GREEN)$(CHECKMARK) Compiling $<$(RESET)"
	@$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

# Create the obj directory if it doesn't exist
$(OBJDIR):
	@echo "$(YELLOW)Creating directory $@$(RESET)"
	@mkdir -p $(OBJDIR)

# Cleaning compiled files
clean:
	@echo "$(YELLOW)Cleaning files$(RESET)"
	@rm -f $(OBJ)
	@rm -rf $(OBJDIR)

# Cleaning everything, including executable
fclean: clean
	@echo "$(RED)Cleaning executable $(TARGET)$(RESET)"
	@rm -f $(TARGET)

# Rebuild everything from scratch
re: fclean all

# Phony targets to avoid conflicts with filenames
.PHONY: all clean fclean re
