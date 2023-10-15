CC      = c++
CFLAGS  = -g -MMD -MP -Wall -Wextra -Werror -std=c++98
DFLAGS  = -fsanitize=address -fsanitize=undefined -fsanitize=bounds
INCLUDE =
NAME    = megaphone
SRCS    = megaphone.cpp
OBJS    = $(SRCS:.cpp=.o)
DEPENDS = $(OBJS:.o=.d)

all: $(NAME)

$(NAME): $(OBJS) $(LIBS)
	echo $(OBJS)
	$(CC) -o $@ $^ $(INCLUDE) $(CFLAGS) $(if $(DEBUG),$(DFLAGS),)

%.o: %.cpp
	$(CC) $(CFLAGS) $(if $(DEBUG),$(DFLAGS),) $(INCLUDE) -o $@ -c $<

clean:
	$(RM) -r $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

debug:
	make DEBUG=1

-include $(DEPENDS)

.PHONY: all clean fclean re
