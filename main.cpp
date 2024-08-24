#include <iostream>
#include <memory>
#include "ProcessInfo.h"
using namespace std;

int main()
{
	ProcessInfo top;
	cout << top.help();
	top.display("pid,tty,cmd");
	return 0;
}
