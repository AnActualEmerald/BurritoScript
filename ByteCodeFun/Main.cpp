#include "vm.h"
#include "compiler.h"
#include <iostream>
#include <vector>

int main()
{

	VM v;
	Compiler cp;
	vector<char> c;
	c = cp.Compile("./test.burr");

	v.Execute(c, c.size());

	getchar();

	return 0;
}