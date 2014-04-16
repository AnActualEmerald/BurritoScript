#pragma once
#include <cassert>
#include <vector>

using namespace std;

class VM
{
public:
	VM() :
		_stackSize(0)
	{}
	~VM() {}

	void Execute(vector<char> bytes, int len);

	void push(char inf)
	{
		assert(_stackSize < MAX_STACK);
		_stack[_stackSize++] = inf;
	}

	int pop()
	{
		assert(_stackSize > 0);
		return _stack[--_stackSize];
	}

	static const int MAX_STACK = 286;

private:
	int _stackSize;
	int _stack[MAX_STACK];

	enum
	{
		INST_LITERAL = 0x00,
		INST_ADD = 0x01,
		INST_SUB = 0x02,
		INST_MULT = 0x03,
		INST_DIV = 0x04,
		INST_PRINTRES = 0x05

	};

};

