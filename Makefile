CC := gcc

CFLAGS := -Wall -Wextra -Werror

SRCS := my_mastermind.c 

OBJS := $(SRCS:.c=.o)

EXE := my_mastermind

all: $(EXE)

$(EXE): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^
	
fclean:
	rm -f $(EXE) $(OBJS)