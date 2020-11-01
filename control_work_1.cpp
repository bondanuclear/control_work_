// kr_1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <Windows.h>
#include <windows.h>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;
class dev
{
private:
	string worker;
	vector<string> tech;
	int eff; // efficiency
public:
	dev(string worker, vector<string> tech, int eff)
	{
		this->worker = worker;
		this->tech = tech;
		this->eff = eff;
	}
	/*int count_devs(project& pr,string techno)
	{

	}*/
	void show_devs()
	{
		cout << "Name of a worker: " << worker << endl;
		cout << "Efficiency of a worker: " << eff << endl;

		cout << " List of technologies of a worker: ";
		for (auto w: tech)
		{
			cout <<  w << " ";
		}
		cout << endl;
		cout <<"===========================================================" << endl;
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
	project(vector<string> tech_com, int level, int finish_perc,vector<string> dep_on, list<string> cur_working)
	{
		
		
		this->tech_com = tech_com; // technologies for accomplishing the project
		this->level = level; // level of difficulty 0.100
		this->finish_perc = finish_perc; // % of finishing a project 0..100
		this->dep_on = dep_on;
		this->cur_working = cur_working; // developers currently working
	}
	void showlist(list <int> g)
	{
		list <int> ::iterator it;
		for (it = g.begin(); it != g.end(); ++it)
			cout << '\t' << *it;
		cout << '\n';
	}
	int time(dev& devs, int k) // evaluate the random time of a project in hours , where func random - random factor
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
	void show()
	{
		cout << "PROJECTS TO DO: " << endl;
		cout << "Technologies, needed to accomplish: " << endl;
		for (auto w : tech_com)
			cout << w << " ";
		cout << endl;
		cout <<"Level of difficulty of the project: " << level << endl;
		cout <<"Finished : " << finish_perc << "%" << endl;
		cout << "List of relations: " << endl;
		for (auto w : dep_on)
			cout << w << " ";
		cout << endl;
		cout << "List of workers currently working on the project: " << endl;
		for (auto w : cur_working)
			cout << w << "; ";
		cout << endl;
		cout << "===================================" << endl;
	}
	project transfer(dev &devs,project & pr,project & pr2)	// dev can transfer to another project only if its progress > 50%
		//and another project has just begun (it has 0% progress) + if the dev knows appropriate technologies
	{
		if ((pr.finish_perc > 50) && (devs.eff > pr.level) && (pr2.finish_perc == 0) && (pr2.can_do(devs)==1))
		{
			pr.cur_working.remove(devs.worker);
			pr2.cur_working.push_back(devs.worker);

	    }
		return *this;
	}
	int count()
	{
		return this->cur_working.size();
	}
	int similar(dev & devs, project & pr, string w1, string w2) // обрахування близькості
	{
		int sim = 0;
		for (int i = 0; i < devs.tech.size(); i++)
		{
			if (devs.tech[i] == w1 && devs.tech[i] == w2) sim++;
			if (pr.tech_com[i] == w1 && pr.tech_com[i] == w2) sim++;
		}
		return sim;
	}
	friend class dev;
};

int main()
{
	srand((unsigned)time(NULL));
	unsigned long time = 0;
	unsigned long endTime = 70;
	unsigned long tick = 1;
	unsigned long nextstep = rand() % 6 + 1;
	dev A("Ann", { "a","w" }, 80);
	dev B("Bee", { "b1","e1" }, 70);
	dev C("Cee", { "k1","b1" }, 65);
	project P({ "w","b1" }, 50, 60, {}, { "Ann","Cee" });
	project P1({ "a","e1" }, 50, 0, {}, { "Bee" });

	while (time < endTime)  // modeling time  - simulating "IT COMPANY"
	{
		time += tick;
		std::cout << "Time: " << time / 60 << ":" << std::setw(2)
			<< std::setfill('0') << time % 60 << "\n";
		if (time % 40 == 0)
		{
			cout << "Introducing the workers: " << endl;
			A.show_devs();
			B.show_devs();
			C.show_devs();
		}
		
		if (time % 50 == 0)
		{
			P.show();
			P1.show();
		}
			//
		if (time % 60 == 0) // transfer Ann to the project p1. Since she knows all needed technologies + the project just started 
			// + level of her efficiency is higher than needed + the project p is 60% finished - Ann can be transfered
		{
			cout << "Transfer Ann to project P1 " << endl;
			cout << P1.can_do(A) << endl; // check if Ann is suitable
			P1.transfer(A, P, P1);
			P.show();
			cout << "--------------------" << endl;
			P1.show();
		}
			//
		if (time % 65 == 0)
		{
			cout << "Estimated time of accomplishing the projects: " << endl;// evaluate the time using self-made formula ^_^
			cout << endl;
			cout << P1.time(A, P1.count()) << " hours" << endl;
		}
			//cout << P.can_do(A);
			//int a = P.time(A, P1.count());
		//	cout << a;
		
	}
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
