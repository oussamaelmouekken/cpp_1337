COMPILE = c++
FLAGS = -Wall -Wextra -Werror -std=c++98 #-fsanitize=address -g

TARGET = No_violence

SRCS = main.cpp Weapon.cpp HumanA.cpp HumanB.cpp 
OBJS = $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(COMPILE) $(FLAGS) $(OBJS) -o $(TARGET)

%.o: %.cpp
	$(COMPILE) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(TARGET)

re: fclean all

.PHONY: all clean fclean re