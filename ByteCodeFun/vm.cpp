#include "vm.h"
#include <iostream>

void VM::Execute(vector<char> data, int len)
{
	

	for (int i = 0; i < len; i++)
	{
		char dat = data[i];
		switch (dat)
		{
			case INST_LITERAL:
				push(data[++i]);
				break;


			case INST_PRINTRES:
			{
				cout << "\"" << pop() << "\"" << endl;
				break;
			}
			

			case INST_ADD:
			{
				int add1 = pop();
				int add2 = pop();
				push(add1 + add2);
				break;
			}

			case INST_SUB:
			{
				int sub1 = pop();
				int sub2 = pop();
				push(sub1 - sub2);
				break;
			}
			
			default:
				break;
		}
	}
}