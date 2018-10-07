Gxx=g++
TARGET=jabnes
MODULES=main.o instructions.o nes_instruction.o state.o
CPPFLAGS=

$(TARGET): $(MODULES)
	$(Gxx) main.o instructions.o nes_instruction.o state.o -o $(TARGET)

clean:
	rm $(MODULES) $(TARGET)

all: clean $(TARGET)

instructions.o: instructions.cpp instructions.h nes_instruction.h state.h

nes_instruction.o: nes_instruction.cpp nes_instruction.h

state.o: state.cpp state.h

main.o: main.cpp instructions.h
