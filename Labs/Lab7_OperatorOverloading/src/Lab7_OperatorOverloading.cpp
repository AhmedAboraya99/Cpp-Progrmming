//============================================================================
// Name        : Lab7_OperatorOverloading.cpp
// Author      : Ahmed Aboraya
// Version     :
// Copyright   : Your copyright notice
// Description : C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class Person
{
private:
    /* data */
    string name;
     int ID;
     int Age;

public:
   
    Person():name(""),ID(0), Age(0){}
    Person( int i, int a, string n = ""):name(n),ID(i), Age(a) {cout << "Person constructor called" << endl;}
    ~Person(){}
    void setID(int i) {ID = i;}
    int setAge() {return ID;}
    void setName(string n) {name = n;}

    int getID() {return ID;}
    string getName() {return name;}
    int getAge() {return Age;}

    void print() {
        cout << "Name: " << name << endl;
        cout << "ID: " << ID << endl;
        cout << "Age: " << Age << endl;
    }

    const Person operator++(int) 
     {
        Person temp = *this;
        ID++;
        Age++;
         return temp;
     }
   Person operator--(const int)
   {
       Person temp = *this;
       this->ID--;
       this->Age--;
       return temp;
   }
      Person operator +(const Person &rhs) const
   {

      int ID_result,Age_result;
      ID_result = ID + rhs.ID;
      Age_result = Age + rhs.Age;
       return Person(ID_result, Age_result);
   }
   Person operator -(Person rhs)
   {
      int ID_result,Age_result;
      ID_result = ID - rhs.ID;
      Age_result = Age - rhs.Age;
      return Person(ID_result, Age_result);
   }
   Person operator *(Person rhs)
   {
      int ID_result,Age_result;
      ID_result = ID * rhs.ID;
      Age_result = Age * rhs.Age;
    
      return Person(ID_result, Age_result);
   }
   Person operator /(Person rhs)
   {

      int ID_result,Age_result;
      ID_result = ID / rhs.ID;
      Age_result = Age / rhs.Age;
      return Person(ID_result, Age_result);
   }


};


int main()
{
    Person ahmed( 110, 20, "ahmed");
    Person  moahmed( 111,24, "mohamed");
    moahmed = ahmed--;
    Person Yousef(112, 30, "Yousef");
    Person Alaa ( 113,24, "Alaa");
    Alaa= ahmed+Yousef;
    ahmed.print();
    moahmed.print();
    Yousef.print();
    Alaa.print();
    return 0;




}

