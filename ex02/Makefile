NAME			:= a.out
CC				:= c++
MANDATORY_FLAGS	:= -Wall -Wextra -Werror -std=c++98
CFLAGS			:= $(MANDATORY_FLAGS)

SRCS			:= \
					main.cpp \
					Fixed.cpp

BUILD_DIR		:= build
OBJS			:= $(SRCS:%.cpp=$(BUILD_DIR)/%.o)

RM				:= rm
RMFLAGS			:= -rf

all: $(NAME)

$(NAME): $(OBJS)
		$(CC) $(OBJS) -o $@

$(BUILD_DIR)/%.o: %.cpp
		@if [ ! -d $(@D) ]; then mkdir -pv $(@D); fi
		$(CC) $(CFLAGS) -c $< -o $@

clean:
		$(RM) $(RMFLAGS) $(BUILD_DIR)

fclean: clean
		$(RM) $(RMFLAGS) $(NAME)

re: fclean all

.PHONY: all clean fclean re
