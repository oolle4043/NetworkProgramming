CC = gcc
CFLAGS = -Wall -Wextra -pthread
TARGET = server
SRCS = main.c handle_clnt.c send_msg.c globalVariable.c run.c
OBJS = $(SRCS:.c=.o)
INCLUDES = -I.

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(TARGET) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c -o $@ $<

clean:
	rm -f $(OBJS) $(TARGET)