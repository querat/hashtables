##
## Makefile for Makefile in /home/querat_g/colles/colle3
##
## Made by gwendal querat
## Login   <querat_g@epitech.net>
##
## Started on  Sun Oct 26 00:43:12 2014 gwendal querat
## Last update Mon Jan 19 16:37:06 2015 gwendal querat
##

RM	=	rm -f

CC	=	gcc

LDFLAGS	=	-I./include

CFLAGS	+=	-Wextra -Wall -Wextra
CFLAGS	+=	-pedantic -g -g3 -std=gnu99
CFLAGS	+=	$(LDFLAGS)

SRCS	=	src/main.c \
		src/list/list_init.c \
		src/list/list_append.c \
		src/list/list_prepend.c \
		src/list/list_print.c \
		src/list/list_destruct.c \
		src/list/list_rm.c \
		src/list/list_len.c \
		src/list/list_insert.c \
		src/hash/ht_hash.c \
		src/hash/ht_init.c \
		src/hash/ht_add_entry.c \
		src/hash/ht_get_entry.c \
		src/hash/ht_print.c \
		src/hash/ht_free.c \
		src/hash/ht_key_cmp.c \
		src/hash/ht_rm_entry.c \
		src/hash/ht_count.c \
		src/hash/ht_foreach.c \

NAME 	=	a.out

OBJS	=	$(SRCS:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
		$(CC) -o $(NAME) $(LDFLAGS) $(OBJS) $(LIB)

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all
