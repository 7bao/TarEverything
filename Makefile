EXEC = te

BIN_DIR = /usr/bin/

CC = g++

all: $(EXEC)

$(EXEC): tareverything.o 
	$(CC) -o $(EXEC) $^

tareverything.o : tareverything.h 

clean:
	@find . -type f -name "*.o" | xargs -i rm {}
	@find . -type f -name "*~" | xargs -i rm {}
	@find . -type f -name "*.gch" | xargs -i rm {}
	@find . -type f -name "*.gdb" | xargs -i rm {}

install:
	cp $(EXEC) $(BIN_DIR)
