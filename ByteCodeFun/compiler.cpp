#include "compiler.h"
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include "vm.h"

using namespace std;

vector<string> Parse(string);

vector<char> Compiler::Compile(const char* path)
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
	
	vector<char> res;

	for (unsigned int i = 0; i < prsd.size(); i++)
	{

		try{
			string s = prsd[i];

			if (s == "+"){
				res.push_back(0x00);
				res.push_back(stoi(prsd[++i]));
				res.push_back(0x01);
				continue;
			}

			if (s == "p")
			{
				res.push_back(0x05);
				continue;
			}

			res.push_back(0x00);
			res.push_back(stoi(s));
		}
		catch (exception& e){
			cerr << "Error occured: " << e.what() << endl;
		}

	}

	return res;

}

vector<string> Parse(string org)
{
	vector<string> res;
	string word;

	for (unsigned int i = 0; i < org.length(); i++)
	{
		if (org[i] != ' ')
		{	
			word += org[i];
		}
		else
		{
			res.push_back(word);
			word.clear();
			continue;
		}

	}
	
	res.push_back(word);
	return res;
}