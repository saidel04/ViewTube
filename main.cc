#include <iostream>
#include "Channel.h"
#include "Control.h"

using namespace std;

int main(){
	
	Control* control = new Control();

	control->launch();
	
	delete control;
	return 0;

}
