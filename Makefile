NAME		=	so_long

SRCS_FILES	= 	${shell find ./source -name "*.c"}

UTILS_FILES	= 	${shell find ./utils -name "*.c"}

SRCS		= 	$(SRCS_FILES)
OBJS		=	$(patsubst %.c,%.o,$(SRCS))
SRCS_UTILS_FILES	=	$(UTILS_FILES)
OBJS_UTILS		=	$(patsubst %.c,%.o,$(SRCS_UTILS_FILES))

INCLUDE		=	include/so_long.h

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
MLX_FLAGS	=	-lmlx -framework OpenGL -framework AppKit
RM			=	rm -f

.PHONY:		all clean fclean re

all:		$(NAME)

%.o:		%.c $(INCLUDE)
			$(CC) $(CFLAGS) -I $(INCLUDE) -c $< -o $@
		
$(NAME):	$(OBJS) $(OBJS_UTILS) $(INCLUDE)
			@$(CC) $(CFLAGS) $(OBJS) $(OBJS_UTILS) -I./include $(MLX_FLAGS) libmlx.dylib -o $(NAME)

clean:
			$(RM) $(OBJS) $(OBJS_UTILS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all