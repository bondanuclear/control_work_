// CONTROL_2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <list>
#include <sstream>
#include <algorithm>
#include <math.h>
using namespace std;
int convert(int N, int b);

int fact(int n);
vector<int> find_string(string str);
template <typename T>
list<int> foo1int(const T& value) {
	list<int> res;
	int result;
	if (value > 0)
	{
		for (int k = 2; k <= 139; k++)
		{
			result = (fact(value) - (value * value)) % k;
			res.push_back(result);
		}
	}
	else if (value < 0)
	{
		result = ((value * value * value * value) + (value * value * value)) % 239;
		result = convert(result, 4);
		res.push_back(result);
	}

	return res;
}
template <typename T>
list<int> foo1float(const T& value) {
	list<int> res;
	int result;
	for (int k = 1; k <= 42; k++)
	{
		result = exp(1 / (cos(k * value)));
		res.push_back(result);
	}
	
	return res;
	
}
/*template <typename T>
typename std::enable_if<std::is_same<T, double>::value>::type
foo(T value)
{
	list<int> res;
	int result;
	for (int k = 1; k <= 42; k++)
	{
		result = exp(1 / (cos(k * value)));
		res.push_back(result);
	}

	showlist(res);
}*/
template <typename T>
list<int> foo(const T& value) {
	if (std::is_integral<T>::value) {
		return foo1int(value);
	}
	else if (std::is_floating_point<T>::value) {
		return foo1float(value);
	}

	return { 4,0,4,9 };
}
template <typename T>
list<int> foo(const string& value) 
{
	int result;
	list<int> res;
	vector<int> w = find_string(value);
	for (int i = 0; i < w.size(); i++)
	{
		result = (w[i] * w[i]) % 439;
		res.push_back(result);
	}
	return res;
}
template <typename First, typename Second>
list<int> foo(const std::pair<First, Second>& value) {
	list<int> result;
	list<int> l1 = foo(value.first);
	list<int> l2 = foo(value.second);

	for (size_t i = 0; i < min(l1.size(), l2.size()); ++i)
		for (int j = 0; j < l2[i]; ++j)
			result.push_back(l1[i]);

	return result;
}
template <typename T>
list<int> foo(const std::list<T>& value) {
	vector<int> result;

	for (auto w : value) {
		vector<int> t = foo(w);

		reverse(t.begin(), t.end());

		for (auto g : t)
			result.push_back(g);
	}

	return result;
}


int convert(int N, int b) // convert to 4-based digit
	{
		if (N == 0)
			return 0;
		int x = N % 4;
		N /= 4;
		if (x < 0)
			N += 1;
		convert(N, 4);
		if (x < 0)
		{
			return x + (4 * -1);
		}
		else return x;


	}
vector<int> find_string(string str) // function to extract all the int digits from the given string
{
		vector<int> nums;
		stringstream ss;
		/* збережемо весь рядко в стрім */
		ss << str;
		string temp;
		int found;
		while (!ss.eof()) {

			/* з потоку беремо по 1 слову*/
			ss >> temp;
			/* перевіряємо, чи є воно інтовим */
			if (stringstream(temp) >> found)
			{
				nums.push_back(found);
			}
		}
		return nums;
}
int fact(int n)
{

	return (n == 0) || (n == 1) ? 1 : n * fact(n - 1);
}

int main()
{
	list<int> a = foo(67);
	for (auto w : a)
		cout << w << "  ";
		return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
