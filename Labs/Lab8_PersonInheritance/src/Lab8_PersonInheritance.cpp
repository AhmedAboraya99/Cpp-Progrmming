//============================================================================
// Name        : Lab8_PersonInheritance.cpp
// Author      : Ahmed Aboraya
// Version     :
// Copyright   : Your copyright notice
// Description : C++, Ansi-style
//============================================================================

    #include <iostream>
#include <string>
using namespace std;

class Person
{
protected:
    string name;
    int age;
public:
    Person(const string& n, int a) : name(n), age(a) {}
    virtual ~Person() {}
    virtual void print() const {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

class Employee : virtual public Person
{
private:
    int employeeID;
    int salary;
    int workingHours;
public:
    Employee(const string& n, int a, int id, int s, int w) : Person(n, a), employeeID(id), salary(id) , workingHours(w){}
    virtual ~Employee() {}
    virtual void print() const {
        Person::print();
        cout << "Employee ID: " << employeeID << endl;
        cout << "Salary: " << salary << endl;
    }
};

class Student :virtual public Person
{
private:
    int studentID;
    int level;
    int grade;
public:
    Student(const string& n, int a, int id, int l, int g) : Person(n, a), studentID(id),level(l),grade(g){}
    virtual ~Student() {}
    virtual void print() const {
        Person::print();
        cout << "Student ID: " << studentID << endl;
        cout << "Level: " << level << endl;
        cout << "Grade: " << grade << endl;
    }
};

class Athlete : public Student
{
private:
    string sport;
public:
    Athlete(const string& n, int a, int studID, int studLev, int studGd,const string& s) : Person(n,a), Student(n, a, studID,studLev,studGd), sport(s) {}
    virtual ~Athlete() {}
    virtual void print() const {

        Student::print();
        cout << "Sport: " << sport << endl;
    }
};

class TeachingAssistant: public Student, public Employee {
    private:
    string courseID;
public:
    TeachingAssistant(const string& n, int a, int studID, int studLev, int studGd, int empID, int empSalary, int empWHour,const string& cID)
      : Person(n,a), Student(n, a, studID,studLev,studGd) , Employee(n, a, empID, empSalary, empWHour ) , courseID(cID){}
      virtual ~TeachingAssistant() {}
       void print() const override {
          Student::print();
          Employee::print();
          cout<<"Course ID: "<<courseID<<endl;
      }

};
int main()
{
    Person p("Ali", 25);
    Employee e("Ahmed", 30, 1234, 3500, 9);
    Student s("Moahmed", 20, 5678, 6, 86);
    Athlete a("Yousef", 22, 4321, 10, 73,"football");
    TeachingAssistant TA("Mohamed Taher", 30, 1415, 4, 92, 2301,4500,9, "EC2201");
    p.print();
    cout << endl;
    e.print();
    cout << endl;
    s.print();
    cout << endl;
    a.print();
    cout << endl;
    TA.print();

    return 0;
}
