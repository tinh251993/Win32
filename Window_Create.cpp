#include <iostream>
#include "Window.h"

int main(int argc, char** argv)
{
	std::cout << "start creating window" << std::endl;

	Window* w = new Window();

	bool is_running = true;
	while (is_running) {
		if (!w->ProcessMesage()) {
			std::cout << "Close window" << std::endl;
			is_running = false;
		}
	}

	delete(w);
	return 0;
}
