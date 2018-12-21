NAME = avm

SRC = main.cpp\
      beginRead.cpp\
      AvmClass.cpp\
      ParseInput.cpp\
      ValuesClass.cpp\
      ValFactory.cpp\
      ValStorClass.cpp\
      ValStorClassExep.cpp


OBJ		= $(addprefix $(OBJDIR),$(SRC:.cpp=.o))

SRCDIR	= ./src/
INCDIR	= ./include/
OBJDIR	= ./obj/

CC = clang++

FLAGS = -Wall -Wextra -Werror

all: obj $(NAME)

obj:
	mkdir -p $(OBJDIR)

$(OBJDIR)%.o:$(SRCDIR)%.cpp
	$(CC) $(FLAGS) -I $(INCDIR) -o $@ -c $<


$(NAME): $(OBJ)
		$(CC) $(FLAGS) $(OBJ) -o $(NAME)

clean:
		rm -rf $(OBJDIR)

fclean: clean
		rm -f $(NAME)

re: fclean all
