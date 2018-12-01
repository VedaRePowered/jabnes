#include <gtkmm-3.0/gtkmm/application.h>
#include <gtkmm-3.0/gtkmm/window.h>

#include "loop.h"

int main(int argc, char ** argv) {
	auto app = Gtk::Application::create(argc, argv, "ca.ben1jen.jabnes");

	Gtk::Window win;
	win.set_title("JabNES");

	JabnesCanvas c;
	win.add(c);
	c.show();

	return app->run(win);
}
