
SRC_FILES = ./main.c \
			./amemory.c \
			./bmemory.c

amemory: $(SRC_FILES)
	gcc -o app $^
#-Wall
clean: rm -f *.o
