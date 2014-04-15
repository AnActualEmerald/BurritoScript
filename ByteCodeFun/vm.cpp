#include "vm.h"
#include <iostream>

void VM::Execute(char* data, int len)
{
	for (int i = 0; i < len; i++)
	{
		char dat = data[i];
		switch (dat)
		{
			case INST_LITERAL:
				push(data[++i]);
				break;
/*

			case INST_PRINT:
			{
					if (_stackSize <= 0)
					{
						cout << "SWAG" << endl;
						break;
					}
				cout << "\"" << pop() << "\"" << endl;
				break;
			}
			*/

			case INST_ADD:
			{
				int add1 = pop();
				int add2 = pop();
				cout << add1 + add2 << endl;
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