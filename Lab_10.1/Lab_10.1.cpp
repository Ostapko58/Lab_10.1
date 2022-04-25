#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<fstream>
#include <string>
using namespace std;

int Count(char* fname) 
{
	ifstream fin(fname); 
	size_t pos = 0;
	int k = 0; 
	char line[100];
	char* t;
	while (fin.getline(line, sizeof(line)))
	{
		while (t = strchr(line + pos, ','))
			{
				pos = t - line + 1;
				if (line[pos] == '-')
					k++;
			}
		pos = 0;
	}
	fin.close();
	return k;
}

int main()
{
	char fname[]="t.txt";
	cout << "File contained " << Count(fname) << " groups of ',-'" << endl;
	return 0;
}
