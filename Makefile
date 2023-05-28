BASENAME	=	GBpp
VERSION		=	0.0.1

SRCS		=	srcs/imgui.cpp \
				srcs/imgui_demo.cpp \
				srcs/imgui_draw.cpp \
				srcs/imgui-SFML.cpp \
				srcs/imgui_tables.cpp \
				srcs/imgui_widgets.cpp \
				srcs/main.cpp

HEADERS		=	includes

BUILDDIR	=	.build
OBJS		=	$(SRCS:%.cpp=$(BUILDDIR)/%.o)
CC			=	g++
CFLAGS		=	#-Wall -Wextra -Werror #-g -fsanitize=address

ifeq ($(OS), Windows_NT)
	SFMLLIB		=	-LSFMLwin/lib
	SFMLINC		=	-ISFMLwin/include -DSFML_STATIC 
	CREA_DIR	=	if not exist ".build/srcs" md ".build/srcs"
	SFMLFLAGS	=	-lsfml-graphics-s -lsfml-window-s -lsfml-system-s -lopengl32 -lfreetype -lwinmm -lgdi32 -mwindows
	RM_DIR		=	rd /s /q
	RM			=	del /f
	NAME		=	$(addprefix $(BASENAME), .exe)
else
	SFMLLIB		=	-LSFMLlinux/lib
	SFMLINC		=	-ISFMLlinux/include
	CREA_DIR	=	@mkdir -p $(BUILDDIR)/srcs
	SFMLFLAGS	=	-lsfml-graphics -lsfml-window -lsfml-system -lGL #-lGLU
	RM_DIR		=	rm -rf
	RM			=	rm -f
	NAME		=	$(addprefix $(BASENAME), .out)
endif

all	:	$(NAME)

$(NAME)	:	$(OBJS)
	$(CC) -o $(NAME) $(CFLAGS) $(OBJS) $(SFMLLIB) $(SFMLFLAGS)

$(BUILDDIR)/%.o	:	%.cpp $(HEADERS)/*.hpp Makefile
	$(CREA_DIR)
	$(CC) $(CFLAGS) -I$(HEADERS) $(SFMLINC) -c $< -o $@

clean :
	-$(RM_DIR) $(BUILDDIR)

fclean : clean
	-$(RM) $(NAME)

re : fclean all

.PHONY: all clean fclean re
