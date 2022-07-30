#include <iostream>
#include <fstream>
#include <unordered_set>
#include <chrono>
using namespace std;
using namespace std::chrono;

void algoritmos(unordered_set<int>&, int);

int main()
{
	cout << "Valor da Soma: ";
	int soma;
	cin >> soma;

	// ------------------------------------
	auto t0 = high_resolution_clock::now();
	// ------------------------------------

	ifstream fin("../conjunto.txt");
	unordered_set<int> hash_table;
	int num;

	while (fin >> num)
		hash_table.insert(num);

	algoritmos(hash_table, soma);

	// ------------------------------------
	auto t1 = high_resolution_clock::now();
	// ------------------------------------  
	
	cout << fixed;
	cout.precision(3);
	cout << "Tempo: " << duration<double>(t1-t0).count() << " segundos" << endl; 

	fin.close();
	system("pause");
	return 0;
}

void algoritmos(unordered_set<int>& hash, int k)
{
	int x;
	int y;
	for (auto i = hash.begin(); i != hash.end(); ++i)
	{
		x = *i;
		y = k - x;
		auto it = hash.find(y);
		if (it != hash.end() && it != i)
		{
			hash.erase(it);
			cout << "(" << x << "," << y << ")" << endl;
		}
	}
}
