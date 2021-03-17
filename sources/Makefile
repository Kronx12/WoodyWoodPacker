# Exec #
NAME			=	woody_woodpacker

# PATH #
SRCS_DIR		=	src
OBJS_DIR		=	obj
INCS_DIR		=	include
VPATH			=	$(SRCS_DIR):$(OBJS_DIR):$(INCS_DIR)

# File with Path #
SRCS_PATH		=	$(wildcard $(SRCS_DIR)/*.c)
OBJS_PATH		=	$(patsubst $(SRCS_DIR)%,$(OBJS_DIR)%,$(SRCS_PATH:%.c=%.o))
INCS_PATH		=	$(wildcard $(INCS_DIR)/*.h)

# File #
SRCS			=	$(notdir $(SRCS_PATH))
OBJS			=	$(notdir $(OBJS_PATH))
INCS			=	$(notdir $(INCS_PATH))

# Compile #
CC				=	clang
CFLAGS			=	-g3 -Wall -Wextra -Werror
FSANITIZE		=	-fsanitize=address
LFLAGS  		=	-I $(INCS_DIR)
CALLF			=	$(CC) $(CFLAGS)

# Defauilt Make #
all				:	directories $(NAME)

# Stuff #
$(NAME)			:	$(OBJS_PATH)
	$(CC) $(OBJS_PATH) -o $(NAME)

$(OBJS_DIR)/%.o	:	%.c $(INCS)
	$(CC) $(LFLAGS) -c $< -o $@

# Make the Directories #
directories		:
	@mkdir -p $(OBJS_DIR)

run: all
ifdef file
	./$(NAME) $(file)
else
	./$(NAME)
endif

# Clean obj #
clean			:
	@rm -f $(OBJS_PATH)
	@rm -rf $(NAME).dSYM
	$(info Build done! Cleaning object files...)

# Clean all #
fclean			:	clean
	@rm -rf $(OBJS_DIR)
	@rm -f $(NAME)
	$(info Build done! Cleaning $(NAME) exec...)

re				:	fclean all

.PHONY			:	all fclean clean re directories run