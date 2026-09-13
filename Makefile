CC = gcc
CFLAGS = -Wall -Wextra -g $(shell pkg-config --cflags sdl2)
LDFLAGS = $(shell pkg-config --libs sdl2 SDL2_ttf)



TARGET = build/app
SRCS = app.c display.c logic.c

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)
clean:
	rm -f $(TARGET)
