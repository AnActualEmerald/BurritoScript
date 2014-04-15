#include "compiler.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "vm.h"

using namespace std;

vector<string> Parse(string);

char* Compiler::Compile(const char* path)
{
	ifstream file;
	file.open(path);

	string org;
	string line;

	while (getline(file, line))
	{
		org += line;
	}

	vector<string> prsd = Parse(org);
	
	
	int pos = 0;
	char res[VM::MAX_STACK];

	for (int i = 0; i < prsd.size(); i++)
	{
		string s = prsd[i];

		if (s == "+"){
			res[pos++] = 0x00;
			res[pos++] = stoi(prsd[i++]);
			res[pos++] = 0x01;
			continue;
		}

		res[pos++] = 0x00;
		res[pos++] = stoi(s);

	}

	return res;

}

vector<string> Parse(string org)
{
	vector<string> res;

	for (int i = 0; i < org.length(); i++)
	{
		if (org[i] != ' ')
			res.push_back(org[i]);
	}

	
	return res;
}