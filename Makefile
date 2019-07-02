.PHONY: all
all: main

.PHONY: clean
clean:
	rm -rf main

main: main.c vops.c
