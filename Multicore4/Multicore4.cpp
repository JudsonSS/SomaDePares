#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include <thread>
using namespace std;
using namespace std::chrono;

void multicore4(vector<int>&, int);

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

	multicore4(vet, soma);

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

void pares(vector<int>& v, size_t ini, size_t end, int k)
{
	size_t VetSize = v.size();

	for (size_t i = ini; i < end; ++i)
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

void multicore4(vector<int>& vec, int k)
{
	size_t start = 0;
	auto size = vec.size();

	thread t1{ pares, ref(vec), start, size / 4, k };
	thread t2{ pares, ref(vec), size / 4, size / 2, k };
	thread t3{ pares, ref(vec), size / 2, size * 3 / 4, k };
	thread t4{ pares, ref(vec), size * 3 / 4, size - 1, k };

	t1.join();
	t2.join();
	t3.join();
	t4.join();
}