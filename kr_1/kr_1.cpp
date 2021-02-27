// kr_1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <time.h>
using namespace std;
class dev
{
private:
	//string worker;
	vector<string> tech;
	int eff; // efficiency
public:
	dev( vector<string> tech, int eff)
	{
		//this->worker = worker;
		this->tech = tech;
		this->eff = eff;
	}
	dev()
	{

	}
	friend class project;
};
class project
{
private:
	vector<string> tech_com;
	int level;
	int finish_perc; // percentage of a project is finished
	vector<string> dep_on;
	list<string> cur_working; // list of devs who are currently working on a project
public:
	project(vector<string> tech_com, int level, vector<string> dep_on)
	{
		this->level = level;
		this->dep_on = dep_on;
		this->tech_com = tech_com;

	}
	void showlist(list <int> g)
	{
		list <int> ::iterator it;
		for (it = g.begin(); it != g.end(); ++it)
			cout << '\t' << *it;
		cout << '\n';
	}
	int time(dev &devs,int k) // evaluate the time of a project , where func random - random factor
	{
		int result;
		result = level + (k * devs.eff) + (rand() % 100 - 50);
		return result;
	}
	bool can_do(dev& devs) // перевірка, чи знає розробник потрібну технологію
	{
		for (int i = 0; i < devs.tech.size(); i++)
		{
			if (devs.tech[i] == tech_com[i])
			{
				return true; 
				break;
			}
			else return false;
		}

	}

	friend class dev;
};

int main()
{
	dev A();
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
