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

HEADER_FILES =			philo.h

OBJS	=		${SRCS:.c=.o}

CC		=				gcc
RM		=				rm -f

CFLAGS	=				-Wall -Wextra -pthread -Werror -fsanitize=thread

all:			${NAME}

%.o : %.c		${HEADER_FILES} Makefile
				${CC} ${CFLAGS} -c $< -o ${<:.c=.o} 

$(NAME):		${OBJS}
				@${CC} ${CFLAGS} -o $@ $^
clean:
				${RM} ${OBJS}

fclean:			clean
				${RM} $(NAME)

re:				fclean all

.PHONY:			all clean fclean re philo