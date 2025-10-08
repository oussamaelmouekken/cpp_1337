COMPILE = c++
FLAGS = -Wall -Wextra -Werror 

TARGET = PhoneBook

SRCS = PhoneBook.cpp main.cpp contact.cpp

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