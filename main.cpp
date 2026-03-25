#include <iostream>

#include "counter.h"

int main() {
	setlocale(LC_ALL, "RUSSIAN");
	my_namespace::Counter c;
	c.run();
	return EXIT_SUCCESS;
}
