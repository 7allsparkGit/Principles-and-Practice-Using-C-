#include "std_lib_facilities.h"
#include "Book.h"
#include  <ctype.h>

int main()
try {
	
	Book myBook("title","gabor",1987,"1-2-3-4-h", false);
	std::cout << myBook;
}

catch (exception& e) {
	cerr << "Error: " << e.what() << endl;
	//keep_window_open();
	return 1;
}
catch (...) {
	cerr << "Unknown exception!\n";
	return 2;
}
