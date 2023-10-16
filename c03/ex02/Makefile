CXX := c++
CXXFLAGS := -std=c++98 -Wall -Wextra -Werror -MMD -MP -pedantic 

TARGET := fragtrap

SRCS := main.cpp \
		ClapTrap.cpp \
		ScavTrap.cpp \
		FragTrap.cpp

OBJS := $(SRCS:.cpp=.o)
DEPS := $(OBJS:.o=.d) 
-include $(DEPS)

.PHONY: all clean fclean re

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS) $(DEPS)

fclean: clean
	$(RM) $(TARGET)

re: fclean all
