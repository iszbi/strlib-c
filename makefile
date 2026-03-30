IDIR = ./include
ODIR = ./obj
SRC = ./src
BIN = ./bin

_DEPS = my_string.h
DEPS = $(patsubst %, $(IDIR)/%, $(_DEPS))

_OBJ = my_string.o harness.o
OBJ = $(patsubst %, $(ODIR)/%, $(_OBJ))

CC = gcc
CFLAGS = -std=c99 -Wall -Wextra -pedantic -I$(IDIR)

$(ODIR)/%.o: $(SRC)/%.c $(DEPS)
	mkdir -p $(ODIR)
	$(CC) -c -o $@ $(CFLAGS) $<

harness: $(OBJ)	
	mkdir -p $(BIN)
	$(CC) -o $(patsubst %, $(BIN)/%, $@) $(CFLAGS) $^

# workbench file - for debugging individual functions
workbench: $(SRC)/workbench.c $(SRC)/my_string.c
	mkdir -p $(BIN)
	$(CC) -o $(patsubst %, $(BIN)/%, $@) $(CFLAGS) $^

clean:
	rm -f $(ODIR)/*.o *~ $(IDIR)/*~
	rm -rf $(ODIR)