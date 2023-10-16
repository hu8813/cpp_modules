CXX := c++
CXXFLAGS := -std=c++98 -Wall -Wextra -Werror -MMD -MP -pedantic 

TARGET := diamondtrap

SRCS := main.cpp \
		ClapTrap.cpp \
		FragTrap.cpp \
		ScavTrap.cpp \
		DiamondTrap.cpp

OBJS := $(SRCS:.cpp=.o)
DEPS := $(OBJS:.o=.d) 

.PHONY: all clean fclean re

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@ -I./

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@ -I./

clean:
	$(RM) $(OBJS) $(DEPS)

fclean: clean
	$(RM) $(TARGET)

re: fclean all

-include $(DEPS)