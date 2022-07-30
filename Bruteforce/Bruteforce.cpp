#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
using namespace std;
using namespace std::chrono;

void bruteforce(vector<int>&, int);

int main()
{
	cout << "Valor da Soma: ";
	int soma;
	cin >> soma;

	// ------------------------------------
	auto t0 = high_resolution_clock::now();
	// ------------------------------------

	ifstream fin("../conjunto.txt");
	vector<int> vet;
	int num;

	while (fin >> num)
		vet.push_back(num);

	bruteforce(vet, soma);

	// ------------------------------------
	auto t1 = high_resolution_clock::now();
	// ------------------------------------
	
	cout << fixed;
	cout.precision(3);
	cout << "Tempo: " << duration<double>(t1 - t0).count() << " segundos" << endl;

	fin.close();
	system("pause");
	return 0;
}

void bruteforce(vector<int>& v, int k)
{
	const size_t VetSize = v.size();

	for (size_t i = 0; i < VetSize - 1; ++i)
	{
		for (size_t j = i + 1; j < VetSize; ++j)
		{
			if ((v[i] + v[j]) == k)
			{
				cout << "(" << v[i] << "," << v[j] << ")" << endl;
			}
		}
	}
}