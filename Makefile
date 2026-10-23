C = g++
CFLAGS = -std=c++11 -Wall -Wextra -g
TARGET = program

SOURCES = main.cpp address.cpp credit_card.cpp person.cpp product.cpp transaction.cpp store.cpp
OBJECTS = $(SOURCES:.cpp=.o)
HDRS = address.h credit_card.h person.h product.h transaction.h store.h

## Link all object files into the executable
$(TARGET): $(OBJECTS)
	$(C) $(CFLAGS) -o $(TARGET) $(OBJECTS)

## Compile each .cpp into a .o (rebuilds if the .cpp or any header changed)
%.o: %.cpp $(HDRS)
	$(C) $(CFLAGS) -c $< -o $@

## Remove build products
clean:
	rm -f $(OBJECTS) $(TARGET)

.PHONY: clean
