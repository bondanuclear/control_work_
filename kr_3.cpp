// kr_3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <vector>
#include <memory>
using namespace std;
class Base {
public:
	
	explicit Base(int num);// constructor 

	virtual ~Base(); // destructor

	
	 static int S()
	 { 
		 return Base::s; 
	 } 

	
	 virtual int acc() const = 0;
	 virtual const string& Name() const = 0;
	 const vector<shared_ptr<Base>>& f() const 
	 { 
		 return ff; 
	 }

	
	void Push(const shared_ptr<Base>& sib_);
	
protected:
	
	static int s;

	
	int N;
	std::string name;
	std::vector<std::shared_ptr<Base>> ff;

};
Base::Base(int num) : N(num) {
	cout << "Base: constructor\n";
	cout << "Base: index = " << num << endl;
}

Base::~Base() 
{
	cout << "Base: destructor" << endl;
	Base::s = 2 * Base::s - N + 39;
};


void Base::Push(const std::shared_ptr<Base>& sib_)
{
	ff.push_back(sib_);
}


int Base::s = 0;
class Alpha : public Base
{
public:
	
	Alpha();// constructor 
	~Alpha() override; // destructor

	
	static void Reset();

	
	 int acc() const override 
	 { 
		 return N; 
	 }
	 const std::string& Name() const override 
	 { 
		 return name;
	 }

private:
	
	static int n;

};
Alpha::Alpha() : Base(Alpha::n) {
	cout << "Alpha: constructor\n";
	N = Alpha::n++;
	name = "Alpha";
}

Alpha::~Alpha() {
	cout << "Alpha: destructor\n";
	Base::s = Base::s - N + 39;
}


void Alpha::Reset() 
{ 
	Alpha::n = 1; 
}


int Alpha::n = 1;

class Beta : public Base {
public:
	
	Beta();
	~Beta() override;

	static void Reset();

	 int acc() const override 
	 { 
		 return N;
	 }
	const std::string& Name() const override
	{ 
		return name; 
	}

private:
	static int n;

};
Beta::Beta() : Base(Beta::n) 
{
	cout << "Beta: constructor\n";
	N = Beta::n++;
	name = "Beta";
}

Beta::~Beta() {
	cout << "Beta: destructor\n";
	Base::s = Base::s + N;
}

void Beta::Reset()
{
	Beta::n = 1; 
}

int Beta::n = 1;
class Gamma : public Base 
{
public:
	
	Gamma();
	~Gamma() override;

	static void Reset();

	 int acc() const override 
	 { 
		 return N; 
	 }
	 const string& Name() const override 
	 { 
		 return name; 
	 }

private:
	static int n;

};
Gamma::Gamma() : Base(Gamma::n) 
{
	cout << "Gamma: constructor\n"; 
	N = Gamma::n++;
	name = "Gamma";
}

Gamma::~Gamma() {
	cout << "Gamma: destructor\n";
	Base::s = Base::s + 3 * N;
}

void Gamma::Reset() 
{ 
	Gamma::n = 1;
}

int Gamma::n = 1;

int main()
{
	shared_ptr<Base> alpha = make_shared<Alpha>();
	shared_ptr<Beta> beta = make_shared<Beta>();
	shared_ptr<Base> gamma =make_shared<Gamma>();
	alpha->Push(make_shared<Beta>());
	alpha->f().front()->Push(make_shared<Gamma>());
	cout << "Alpha: " << endl;
	alpha.reset();
	cout << "Beta: " << endl;
	beta.reset();
	cout << "Gamma: " << endl;
	gamma.reset();

	
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
