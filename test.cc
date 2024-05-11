#include <iostream>
#include "Channel.h"
#include "TestControl.h"

using namespace std;

int main(){
	
	TestControl* control = new TestControl();

	control->launch();
	
	delete control;
	return 0;

}
