# Definition of normal variables
CC := g++
LD := g++
SOURCES := $(wildcard *.cpp)
OBJECTIVES := $(patsubst %cpp, %o, $(SOURCES))
TARGET := test # PUT YOUR INTENDED NAME HERE

# Link ALL dependency files to carry out ALL target files
$(TARGET): $(OBJECTIVES)
	$(LD) -o $@ $^

# Compile ALL objective files EACH BY EACH
%.o:%.c
	$(CC) -c $^

# Definition of phony targets
.PHONY: all clear clean directory
all: $(TARGET)
clear:
	rm -f $(OBJECTIVES) $(TARGET)
	rm -f *.dat
clean:
	rm -f $(TARGET)

	
