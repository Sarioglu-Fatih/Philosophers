NAME	=				philo

SRCS	=				main.c					\
						parsing.c				\
												\
						utils/put_fd.c			\
						utils/ft_strlen.c		\
						utils/ft_atoi.c			\
						utils/free_struct.c		\
						utils/ft_itoa.c			\
						utils/set_timestamp.c	\
						utils/get_timestamp.c	\
												\
						exec/exec.c				\
						exec/init.c				\
						exec/philo_is_dead.c	\
						exec/new_timestamp.c	\

HEADER_FILES =			philo.h

OBJS	=		${SRCS:.c=.o}

CC		=				gcc
RM		=				rm -f

CFLAGS	=				-Wall -Wextra -Werror #-fsanitize=thread

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