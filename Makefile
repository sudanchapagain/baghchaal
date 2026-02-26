.PHONY: build clean

clean:
	rm -rf build/

build:
	mkdir -p build/
	cc -std=c99 src/main.c -Wall -Wextra -lraylib -o build/baghchaal
