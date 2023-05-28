NAME		=	GBpp.out
VERSION		=	0.0.1

SRCS		=	srcs/main.cpp

HEADERS		=	includes

BUILDDIR	=	.build
OBJS		=	$(SRCS:%.cpp=$(BUILDDIR)/%.o)
CC			=	g++
CFLAGS		=	-Wall -Wextra -Werror #-g -fsanitize=address
SFMLFLAGS	=	-lsfml-graphics -lsfml-window -lsfml-system
SFMLLIB		=	-LSFMLlinux/lib
SFMLINC		=	-ISFMLlinux/include

all	:	$(NAME)

$(NAME)	:	$(OBJS)
	$(CC) -o $(NAME) $(CFLAGS) $(OBJS) $(SFMLLIB) $(SFMLFLAGS)

$(BUILDDIR)/%.o	:	%.cpp $(HEADERS)/*.hpp Makefile
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -I$(HEADERS) $(SFMLINC) -c $< -o $@

clean :
	-rm -f $(OBJS)

fclean : clean
	-rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re
