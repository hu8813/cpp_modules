CXX := c++
CXXFLAGS := -std=c++98 -Wall -Wextra -Werror -MMD -MP -pedantic

TARGET := span

SRCS := main.cpp \
		Span.cpp

OBJDIR := .obj
OBJS := $(addprefix $(OBJDIR)/,$(SRCS:.cpp=.o))
DEPS := $(addprefix $(OBJDIR)/,$(SRCS:.cpp=.d))

.PHONY: all clean fclean re

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

$(OBJDIR)/:
	mkdir -p $(OBJDIR)

$(OBJDIR)/%.o: %.cpp | $(OBJDIR)/
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -rf $(TARGET)

re: fclean all

-include $(DEPS)
