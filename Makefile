# Variables
CC = g++
CFLAGS = -Wall -I./ArduinoCore-crio/cores/arduino -I./generated
DEPS = ArduinoCore-crio/cores/arduino/Arduino.h generated/NiFpga_f.h generated/NiFpga.h
OBJ = Blink.o main.o analog.o digital.o wiring.o

# Default rule
all: Blink

# Rule to rename Blink.ino to Blink.cpp
Blink.cpp: Blink.ino
	mv Blink.ino Blink.cpp

# Rule to compile Blink.cpp to Blink.o
%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

# Rule to compile main.cpp to main.o
main.o: ArduinoCore-crio/cores/arduino/main.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

# Rule to compile analog.c, digital.c, and wiring.c to analog.o, digital.o, and wiring.o
%.o: ArduinoCore-crio/cores/arduino/%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

# Rule to link Blink.o, main.o, analog.o, digital.o, and wiring.o to executable Blink
Blink: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

# Rule to clean up
clean:
	rm -f *.o Blink Blink.cpp