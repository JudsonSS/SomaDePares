#include <iostream>
#include <fstream>
#include <random>
#include <unordered_set>
using namespace std;

int main()
{
	random_device rd;
	mt19937 mt(rd());
	uniform_int_distribution<int> dist(0, INT_MAX);
	unordered_set<int> hash;

	ofstream fout;
	fout.open("../conjunto.txt");
	int i = 0;
	int num;
	while (i < 80000)
	{
		num = dist(mt);
		if (hash.find(num) == hash.end())
		{
			hash.insert(num);
			fout << num << " ";
			++i;
		}
	}
	fout.close();

	system("pause");
	return 0;
}