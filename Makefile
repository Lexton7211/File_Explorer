CC = gcc
TARGET = build/app
SRCS = app.c

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CC) -o $@ $^
