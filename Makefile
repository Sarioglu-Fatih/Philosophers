NAME	=				philo

SRCS	=				main.c					\
						parsing.c				\
												\
						exec/eat.c				\
						exec/init.c				\
						exec/exec.c				\
						exec/think.c			\
						exec/free_struct.c		\
						exec/sleep_time.c		\
						exec/print_state.c		\
						exec/new_timestamp.c	\
						exec/check_get_dead.c	\
												\
						utils/ft_atoi.c			\
						utils/ft_strlen.c		\
						utils/get_usleep.c		\
						utils/set_timestamp.c	\
						utils/get_timestamp.c	\

HEADER_FILES	=	philo.h

OBJ_DIR			=	obj/
OBJS			=	$(addprefix $(OBJ_DIR), $(SRCS:.c=.o))

CC				=	gcc
RM				=	rm -rf
MKDIR			=	mkdir -p

CFLAGS			=	-Wall -Wextra -pthread -Werror

all				:	$(NAME)

$(OBJ_DIR)%.o	:	%.c	$(HEADER_FILES) Makefile
			@$(MKDIR) $(dir $@)
			$(CC) $(CFLAGS) -c $< -o $@

$(NAME)			:	$(OBJS)
			@$(CC) $(CFLAGS) -o $@ $^
clean			:
			$(RM) $(OBJ_DIR)

fclean			:	clean
			$(RM) $(NAME)

re				:	fclean all

.PHONY			:	all clean fclean re philo