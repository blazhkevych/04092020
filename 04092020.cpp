//приведення типів(використовувати приведення типів с++)
//покажчики смарт поінтери
#include <iostream>
using namespace std;
class Human {
protected:
	char* name;
public:
	Human(const char* n) : name(_strdup(n)) { cout << "i was in human constr\n"; }
	~Human() { delete[] name; cout << "i was in human destr\n"; }
	virtual void Show() { cout << "Name : " << name << endl; }
};
class Student : public Human {
public:
	double avg;
	int kurs;
	Student(const char* n, double avg, int kurs) : Human(n), avg(avg), kurs(kurs) {}
	void Show() {
		Human::Show();
		cout << "Avg = " << avg << ", Kurs = " << kurs << endl;
	}
};
class Teacher :public Human {
public:
	double salary;
	char* subject;
	Teacher(const char* n, double sal, const char* sub) : Human(n), salary(sal), subject(_strdup(sub)) {  }
	~Teacher() { delete[] subject; }
	void Show() {
		Human::Show();
		cout << "Salary = " << salary << ", Subject = " << subject << endl;
	}
};
void func(Human* h) {
	Student* s = dynamic_cast <Student*>(h);
	if (s)
		s->kurs++;
}
void Testreinterpret() {
	int* p = new int(8500);
	char* c = reinterpret_cast <char*>(p);
	cout << *c;
	const char* h = _strdup("Hello\n");
	//const  char* h = "Hello\n";
	//int k = 1041;
	int k = reinterpret_cast <int>(h);
	cout << k << endl;
	const char* cc = reinterpret_cast <const char*>(k);
	cout << cc << endl;
}

template <class T>
class SmartPTR {
	T* ptr;
public:
	SmartPTR(T* p) : ptr(p) {}
	~SmartPTR() { delete ptr; }
	T* operator -> () { return ptr; }
	T& operator * () { return *ptr; }
private:
	T& operator = (const SmartPTR& p) = delete;  // заборона виклику оператору дорівнює
	SmartPTR(const SmartPTR& R) = delete;
};

void TestSmart() {
	SmartPTR <Human> H(new Human("Ivan"));
	H->Show();
	(*H).Show();
	SmartPTR <Human>Test(0);
	//Test = H; // заборонили використовувати
	//SmartPTR<Human>N(H);
}

int main()
{
	//Human* h = new Human("Petro");
	//Student* s = new Student("Ivan", 11, 2);
	///*Human* H = s;
	//Student* S = (Student*)h;
	//S->Show();
	//Student* SS = static_cast<Student*>(h);
	//SS->Show();
	//SS->avg = 1000;
	//SS->kurs = 2000;
	//SS->Show();
	//s->Show();*/
	//Teacher* t = new Teacher("Anna", 5, "C--");
	//h->Show();
	//s->Show();
	//t->Show();
	//cout << "*****************************" << endl;
	//func(t);
	//h->Show();
	//s->Show();
	//t->Show();
	//Testreinterpret();
	TestSmart();
}