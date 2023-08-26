CXX := c++
CXXFLAGS := -std=c++98 -Wall -Wextra -Werror

TARGET := harlFilter

SRCS := main.cpp \
		Harl.cpp

OBJS := $(SRCS:.cpp=.o)

.PHONY: all clean fclean re

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(TARGET)

re: fclean all
