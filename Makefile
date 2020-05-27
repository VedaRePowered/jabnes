Gxx = g++
TARGET = jabnes
MODULES = main.o loop.o instructions.o nes_instruction.o ppu.o state.o
CPPFLAGS = -Wall
CPPFLAGS += `pkg-config --cflags gtkmm-3.0`
LDFLAGS += `pkg-config --libs gtkmm-3.0`

$(TARGET): $(MODULES)
	$(Gxx) $(MODULES) $(LDFLAGS) -o $(TARGET)

run: $(TARGET)
	./$(TARGET) $(ARGS)

clean:
	rm -f $(MODULES) $(TARGET)

all: clean $(TARGET)

instructions.o: instructions.cpp instructions.h nes_instruction.h state.h

nes_instruction.o: nes_instruction.cpp nes_instruction.h

ppo.o: ppu.cpp ppu.h state.h

state.o: state.cpp state.h

loop.o: loop.cpp loop.h instructions.h ppu.h state.h

# -I /usr/include/* -I /usr/lib/x86_64-linux-gnu/*/include
#  -I /usr/lib/x86_64-linux-gnu/gtkmm-3.0/include -I /usr/lib/x86_64-linux-gnu/gdkmm-3.0/include -I /usr/lib/x86_64-linux-gnu/pangomm-1.4/include -I /usr/lib/x86_64-linux-gnu/glibmm-2.4/include -I /usr/include/glibmm-2.4 -I /usr/include/glib-2.0 -I /usr/lib/x86_64-linux-gnu/glib-2.0/include -I /usr/include/sigc++-2.0 -I /usr/lib/x86_64-linux-gnu/sigc++-2.0/include -I /usr/include/gtkmm-3.0 -I /usr/include/pangomm-1.4 -I /usr/include/pango-1.0 -I /usr/include/cairomm-1.0 -I /usr/include/cairo -I /usr/include/freetype2 -I /usr/lib/x86_64-linux-gnu/gtkmm-3.0/include -I /usr/lib/x86_64-linux-gnu/gdkmm-3.0/include -I /usr/lib/x86_64-linux-gnu/pangomm-1.4/include -I /usr/lib/x86_64-linux-gnu/glibmm-2.4/include -I /usr/include/glibmm-2.4 -I /usr/include/glib-2.0 -I /usr/lib/x86_64-linux-gnu/glib-2.0/include -I /usr/include/sigc++-2.0 -I /usr/lib/x86_64-linux-gnu/sigc++-2.0/include -I /usr/include/gtkmm-3.0 -I /usr/include/pangomm-1.4 -I /usr/include/pango-1.0 -I /usr/include/cairomm-1.0 -I /usr/include/cairo -I /usr/include/freetype2

main.o: main.cpp loop.h

testsmb: $(TARGET)
	./$(TARGET) > jabnes_SMB1.log
	./cmplogs nintendulator_SMB1.log jabnes_SMB1.log