CXX      := c++
CXXFLAGS := -g -MMD -MP -Wall -Wextra -Werror -std=c++98
DFLAGS   := -fsanitize=address -fsanitize=bounds
INCLUDE  := -I include
NAME     := phonebook
SRCDIR   := src
SRCS     := src/Contact.cpp src/PhoneBook.cpp src/main.cpp
OBJDIR   := obj
OBJS     := $(subst $(SRCDIR), $(OBJDIR), $(SRCS:.cpp=.o))
DEPENDS  := $(OBJS:.o=.d)

all: $(NAME)

$(NAME): $(OBJS) $(LIBS)
	$(CXX) -o $@ $^ $(INCLUDE) $(CXXFLAGS) $(if $(DEBUG),$(DFLAGS),)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@ mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $(if $(DEBUG),$(DFLAGS),) $(INCLUDE) -o $@ -c $<

clean:
	$(RM) -r $(OBJDIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

debug:
	make DEBUG=1

cppfile:
	find . -name "*.cpp" | sed 's/\.\///g' | tr '\n' ' '

-include $(DEPENDS)

.PHONY: all clean fclean re
