# Variables
CC = gcc
CFLAGS = -Wall -I./ArduinoCore-crio/cores/arduino -I./generated
LDFLAGS = -ldl
DEPS = ArduinoCore-crio/cores/arduino/Arduino.h generated/NiFpga_f.h generated/NiFpga.h
OBJ = generated/Blink.o generated/main.o generated/analog.o generated/digital.o generated/wiring.o generated/NiFpga.o

# Default rule
all: exe copy

# Rule to rename .ino to .cpp
%.cpp: %.ino
	cp %< $@

# Rule to compile .cpp to .o
generated/%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

# Rule to compile main.cpp to main.o
generated/main.o: ArduinoCore-crio/cores/arduino/main.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS) -lstdc++

# Rule to compile analog.c, digital.c, and wiring.c to analog.o, digital.o, and wiring.o
generated/%.o: ArduinoCore-crio/cores/arduino/%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS) -lstdc++

generated/NiFpga.o: generated/NiFpga.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

# Rule to link .o files to executable
exe: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS) -lstdc++

# Rule to copy .lvbitx to parent folder
copy:
	cp generated/*.lvbitx ..

# Rule to clean up
clean:
	rm -f generated/*.o exe *.cpp
