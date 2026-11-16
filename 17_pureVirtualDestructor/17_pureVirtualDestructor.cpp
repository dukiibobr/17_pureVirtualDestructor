#include <iostream>
#include <windows.h>    
using namespace std;

//
//class Student {
//	string name;
//	string specialization;
//	int age;
//	int* marks;
//	int countMarks;
//public:
//	Student():name("-"),age(0),specialization("-"),marks(nullptr), countMarks(0) {}
//	Student(string n,string s, int a) :name(n),specialization(s), age(a), marks(nullptr), countMarks(0)
//    {
//	countMarks = rand() % 15 + 1; 
//	marks = new int[countMarks];
//	for (int i = 0; i < countMarks; i++)
//	 {
//		marks[i] = rand() % 12 + 1;
//	 }
//    }
//	
//
//	virtual void print() {
//		cout << "name: " << name << endl;
//		cout << "age: " << age << endl;
//		cout << "specialization: " << specialization << endl;
//		cout << "marks: ";
//		for (int i = 0; i < countMarks; i++)
//		{
//			cout << marks[i] << " ";
//		}
//		cout << endl << endl;
//	}
//
//
//	virtual ~Student() {
//		if (marks!=nullptr)
//			delete[]marks;
//     }
//};
//
//
//class Aspirant:public Student {
//	string* subject;
//	int counrSubjects;
//public:
//	Aspirant():Student(),subject(nullptr),counrSubjects(0){}
//	Aspirant(string n,string s,int a,initializer_list<string> list):Student(n,s,a),counrSubjects(0)
//	{
//		this->counrSubjects = list.size();
//		subject = new string[counrSubjects];
//		int i = 0;
//		for (string sub :list)
//		{
//			subject[i] = sub;
//			i++;
//		}
//	}
//	
//	void print()override {
//		Student::print();
//		cout << "subject: ";
//		for (int i = 0; i < counrSubjects; i++)
//		{
//			cout << subject[i] << " | ";
//		}
//		cout << endl;
//	}
//
//	 ~Aspirant() {
//		if (subject!=nullptr)
//			delete[]subject;
//	}
//};
//
//int main()
//{
//	srand(time(0));
//
//
//
//	Student s("vasya","elektrik", 18);
//	s.print();
//
//	Aspirant a("oper", "history", 20, { "hitler and friends","oiuh"});
//	a.print();
//
//	cout << "====================================" << endl;
//
//	Student* group[3]{
//		new Student("vasya","elektrik", 18),
//		new Aspirant("oper", "history", 20, { "hitler and friends","oiuh"})
//
//	};
//	for (int i = 0; i < 3; i++)
//	{
//		group[i]->print();
//		delete[]group[i];
//	}
//}







//2 in class





//class Person {
//    string name;
//
//public:
//    Person() : name("-") {}
//
//    Person(string n) : name(n) {}
//
//    virtual void print() {
//        cout << "name: " << name << endl;
//    }
//
//    virtual ~Person() = 0 {}
//};
//
//
//class Aspirant : public Person {
//    string* subject;
//    int countSubjects;
//
//public:
//    Aspirant() : Person(), subject(nullptr), countSubjects(0) {}
//
//    Aspirant(string n, initializer_list<string> list)
//        : Person(n), subject(nullptr), countSubjects(list.size())
//    {
//        subject = new string[countSubjects];
//
//        int i = 0;
//        for (const string& sub : list) {
//            subject[i] = sub;
//            i++;
//        }
//    }
//
//    void print() override {
//        Person::print();
//
//        cout << "subject: ";
//
//        for (int i = 0; i < countSubjects; i++) {
//            cout << subject[i] << " | ";
//        }
//
//        cout << endl;
//    }
//
//    ~Aspirant() override {
//        delete[] subject;
//    }
//};





//dz

void gotoxy(int x, int y)
{
    COORD coordinate;
    coordinate.X = x;
    coordinate.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinate);
}


class Shape {
protected:
    string type;
public:
    Shape():type("-"){}
    Shape(string t):type(t){}
   
    virtual void print()const = 0;

};


class Line :public Shape {
    struct Point {
        int x;
        int y;

        Point():x(0),y(0){}
        Point(int x,int y):x(x),y(y){}
    };

    Point start;
    Point end;
public:
    Line():Shape(){}
    Line(Point start,Point end,string t):start(start),end(end),Shape(t){}
    
    
    void print()const {
        cout << "type: " << type << endl;
        gotoxy(start.x, start.y); cout << "*";
        gotoxy(end.x, end.y); cout << "*";
        cout << endl;
    }
};


class Rectangle1 :public Shape {
    struct Point {
        int x;
        int y;

        Point() :x(0), y(0) {}
        Point(int x, int y) :x(x), y(y) {}
    };
    Point coord;

    int width;
    int height;
public:
    Rectangle1():width(0),height(0){}
    Rectangle1(Point  p,int w,int h,string t):coord(p), width(w), height(h),Shape(t) {}
   
    void print()const override {
        cout << "type: " << type << endl;
        for (int i = 0; i < width; i++)
        {
            gotoxy(coord.x, coord.y+i);
            for (int i = 0; i < height; i++)
            {
                cout << "* ";
            }
            cout << endl;
        }
    }
};


class Polyline :public Shape {
    int* points;
public:
    Polyline():points(nullptr){}
   
    void print()const override {
        //setcursor + gotoxy

    }

    virtual ~Polyline() {
        if (points != nullptr)
            delete[]points;
    }
};


int main() {
    
  /*  Line l({ 9,3}, { 5,7 }, "line1");
    l.print();*/

    Rectangle1 r({ 5,6 }, 6, 6, "rectangle1");
    r.print();






  /* //Person s("vasya");
    //s.print();

    cout << endl;

    Aspirant a("oper", { "history", "math", "programming" });
    a.print();

    cout << "====================================" << endl;

    Person* group[3]{
        //new Person("vasya"),
        new Aspirant("oper", { "history", "math" }),
        new Aspirant("petya", { "physics", "chemistry" })
    };

    for (int i = 0; i < 3; i++) {
        group[i]->print();
        cout << endl;

        delete group[i];
    }
    */
    return 0;
}
