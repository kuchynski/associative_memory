
SRC_FILES = ./main.c \
			./amemory.c

amemory: $(SRC_FILES)
	gcc -o app $^
#-Wall
clean: rm -f *.o
