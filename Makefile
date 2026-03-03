.PHONY: build clean

CFLAGS := -std=c99 -Wall -Wextra $(shell pkg-config --cflags raylib)
LDFLAGS := $(shell pkg-config --libs raylib)

clean:
	rm -rf build/

build:
	mkdir -p build/
	cc src/main.c $(CFLAGS) -o build/baghchaal $(LDFLAGS)

run: build
	./build/baghchaal
