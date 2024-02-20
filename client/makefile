CC = gcc
CFLAGS = -Wall -Wextra -pthread
TARGET = clnt
SRCS = globalVariable.c recv_msg.c send_msg.c run.c main.c
OBJS = $(SRCS:.c=.o)
INCLUDES = -I.

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(TARGET) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c -o $@ $<

clean:
	rm -f $(OBJS) $(TARGET)