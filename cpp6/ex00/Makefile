COMPILE = c++
FLAGS = -Wall -Wextra -Werror -std=c++98

TARGET = convert

SRCS = main.cpp ScalarConverter.cpp is_type.cpp convert_to_types.cpp

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