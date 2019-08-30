#include <iostream>
#include <stdexcept>
#include <exception>
#include <direct.h>

using namespace std;

#ifndef cmdError_CPP
#define cmdError_CPP

class cmdError: public runtime_error{
	public:
		cmdError(char* msg):runtime_error(msg){
		}
};

#endif
