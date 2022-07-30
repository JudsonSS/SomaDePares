#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include <thread>
using namespace std;
using namespace std::chrono;

void multicore12(vector<int>&, int);

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

	multicore12(vet, soma);

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

void multicore12(vector<int>& vec, int k)
{
	size_t start = 0;
	auto size = vec.size();

	thread t01{ pares, ref(vec), start, size * 1 / 12, k };
	thread t02{ pares, ref(vec), size * 1 / 12, size * 2 / 12, k };
	thread t03{ pares, ref(vec), size * 2 / 12, size * 3 / 12, k };
	thread t04{ pares, ref(vec), size * 3 / 12, size * 4 / 12, k };
	thread t05{ pares, ref(vec), size * 4 / 12, size * 5 / 12, k };
	thread t06{ pares, ref(vec), size * 5 / 12, size * 6 / 12, k };
	thread t07{ pares, ref(vec), size * 6 / 12, size * 7 / 12, k };
	thread t08{ pares, ref(vec), size * 7 / 12, size * 8 / 12, k };
	thread t09{ pares, ref(vec), size * 8 / 12, size * 9 / 12, k };
	thread t10{ pares, ref(vec), size * 9 / 12, size * 10 / 12, k };
	thread t11{ pares, ref(vec), size * 10 / 12, size * 11 / 12, k };
	thread t12{ pares, ref(vec), size * 11 / 12, size - 1, k };

	t01.join();
	t02.join();
	t03.join();
	t04.join();
	t05.join();
	t06.join();
	t07.join();
	t08.join();
	t09.join();
	t10.join();
	t11.join();
	t12.join();
}