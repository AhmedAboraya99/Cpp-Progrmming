//============================================================================
// Name        : P2_MaterialObjects.cpp
// Author      : Ahmed Aboraya
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <iostream>
using namespace std;

class MaterialObject {
protected:
    string name;

public:
    MaterialObject() {};
    virtual ~MaterialObject(){};
    virtual void printType() const { cout << "Material Object" << endl; }

};

class LivingThing : virtual public MaterialObject {
protected:
        string family;
public:
    LivingThing(){};
    LivingThing(string fam):family(fam) {};
    virtual ~LivingThing(){};
    void printType()const override { cout << "Living Thing" << endl; }
    void setFamily(string fam) { family = fam; }
    string getFamily() { return family; }
};

class NonLivingThing : virtual public MaterialObject {
protected:
    string state;

public:
    NonLivingThing(){};
    NonLivingThing(const string& st):state(st) {};
    virtual ~NonLivingThing(){};
    void printType()const override { cout << "Non-Living Thing" << endl; }
};

class Animals : virtual public LivingThing {
protected:
    int numberOfLegs;
    string gender;
    string  breed;
    int size;

public:
    Animals():numberOfLegs(0), size(0) {};
    Animals(int legs,const string& gen,const string& fm,const string& br,int sz): LivingThing(fm), numberOfLegs(legs), gender(gen), breed(br),size(sz) {};
    virtual ~Animals(){};
    void printType()const override  { 
        cout << "<<Animal>>" << endl;
        cout << "Number of legs: " << numberOfLegs << ", gender: " << gender << ", family: "<< ", breed: " << breed <<", size: " << size <<endl;
   }
    
    // Add getters and setters for attributes
    int getNumberOfLegs() { return numberOfLegs; }
    string getGender() { return gender; }
    string getBreed() { return breed; }
    int getSize() { return size; }
    void setNumberOfLegs(int legs) { numberOfLegs = legs; }
    void setGender(string gen) { gender = gen; }
    void setBreed(string br) { breed = br; }
    void setSize(int sz) { size = sz; }
};

class Mammal : virtual public Animals {
protected:
    string hairColor;

public:
    Mammal(){};
    virtual ~Mammal(){};
    void printType()const override { cout << "Mammal" << endl; }
    
    // Add getters and setters for attributes
    string getHairColor() { return hairColor; }
    void setHairColor(string color) { hairColor = color; }
};

class Reptile : virtual public Animals {
protected:
    string skinColor;

public:
    Reptile(){};
    virtual ~Reptile(){};
void printType()const override { cout << "Reptile" << endl; }
    
    // Add getters and setters for attributes
    string getSkinColor() { return skinColor; }
    void setSkinColor(string color) { skinColor = color; }
};

class HumanBeing :virtual public LivingThing, virtual public Mammal{
protected:
    string name;
    int age;
    string eyeColor;
    string skinColor;
    string race;
    string profession;

public:
    HumanBeing():age(0){};
    HumanBeing(string nm, int a,const string& ec,const string& sc,const string& rc,const string& pr)
                :name(nm), age(a), eyeColor(ec), skinColor(sc), race(rc), profession(pr){};
    virtual ~HumanBeing(){};
    void printType()const override {
        cout << "<<Human Being>>" << endl; 
        cout<< "name: "<< name<<", age: "<< age <<", eyeColor"<< eyeColor<<", skinColor"<< skinColor<<", race"<< race<<", profession: "<<profession<<endl;
        }
    
    // Add getters and setters for attributes
    string getName() { return name; }
    int getAge() { return age; }
    string getEyeColor() { return eyeColor; }
    string getSkinColor() { return skinColor; }
    string getRace() { return race; }
    string getProfession() { return profession; }
    void setName(string nm) { name = nm; }
    void setAge(int a) { age = a; }
    void setEyeColor(string color) { eyeColor = color; }
    void setSkinColor(string color) { skinColor = color; }
    void setRace(string rc) { race = rc; }
    void setProfession(string pr) { profession = pr; }
};

class Birds : virtual public LivingThing {
protected:
    int numberOfWings;
    int maxAltitude;

public:
    Birds(){};
    virtual ~Birds(){};
    void printType()const override { cout << "Bird" << endl; }
    
    // Add getters and setters for attributes
    int getNumberOfWings() { return numberOfWings; }
    int getMaxAltitude() { return maxAltitude; }
    void setNumberOfWings(int wings) { numberOfWings = wings; }
    void setMaxAltitude(int altitude) { maxAltitude = altitude; }
};

class Solid : virtual public NonLivingThing {
protected:
    int size;
    string Type;
    string color;

public:
    Solid(){};
    virtual ~Solid(){};
    void printType()const override { cout << "<<Solid>>" << endl;
    cout<< "size: " << size <<", Type: " << Type << ", color: "<< color<<endl;
    }
    
    // Add getters and setters for attributes
    int getSize() { return size; }
    string getType() { return Type; }
    string getColor() { return color; }
    void setSize(int sz) { size = sz; }
    void setType(string type) { Type = type; }
    void setColor(string color) { this->color = color; }
};

class Gas : virtual public NonLivingThing {
    protected:

    int density;
    string smell;

public:
    Gas(){};
    Gas(int dens,const string& sm):density(dens), smell(sm) {};
    virtual ~Gas(){};
    int getDensity() { return density; }
    string getSmell() { return smell; }
    void setDensity(int dens) { density = dens; }
    void setSmell(const string& sm) { smell = sm; }
    void printType()const override { 
        cout << "<<Gas>>" << endl;
        cout<<"Density: " << density<<", smell: " << smell<<endl;
    }
};

class Liquid : virtual public NonLivingThing {
    protected:
    int density;
    string taste;
public:
    Liquid(){};
    Liquid(int dens,const string& ts):density(dens), taste(ts) {};
    virtual ~Liquid(){};
    void printType()const override {
         cout << "<<Liquid>>" << endl;
         cout<<"Density: " << density<<", taste: " << taste<<endl;
    }
};

int main() {
    // Create an animal object with specific attributes
    Animals dog(4, "male" ,"Canidae", "Labrador", 30);
    // Create an animal object with specific attributes
    Animals cat(4, "female","Cats","Siamese", 20);
    // Create an animal object with specific attributes
    Animals platypus(2, "male", "duck-billed","semiaquatic", 15);
    
    // Set and get attributes using getters and setters
    cout << "Dog has " << dog.getNumberOfLegs() << " legs." << endl;
    cout << "Dog is " << dog.getGender() << "." << endl;
    cout << "Dog belongs to the " << dog.getFamily() << " family." << endl;
    cout << "Dog breed is " << dog.getBreed() << "." << endl;
    cout << "Dog size " << dog.getSize() << " inch2." << endl;
    
        // create an object of class HumanBeing
    HumanBeing Ken;
    Ken.setName("Ken");
    Ken.setAge(40);
    Ken.setProfession("Dentist");
    Ken.setEyeColor("blue");
    Ken.setHairColor("black");
    Ken.setSkinColor("black");

    // create an object of class FloShopkeeper
    HumanBeing Flo;
    Flo.setName("Flo");
    Flo.setAge(30);
    Flo.setProfession("Shopkeeper");
    Flo.setEyeColor("Black");
    Flo.setHairColor("Brown");
    Flo.setSkinColor("White");

    // create an object of class BethArtist
    HumanBeing beth;
    beth.setName("Beth");
    beth.setAge(25);
    beth.setProfession("Artist");
    beth.setEyeColor("green");
    beth.setHairColor("Black");
    beth.setSkinColor("Brown");

    // create an object of class Air
    Gas air;
    air.setDensity(1.225);
    air.setSmell("Fresh");

    // create an object of class Rock
    Solid rock;
    rock.setSize(10);
    rock.setType("Granite");
    rock.setColor("Gray");

    // print the types of the created objects
    cat.printType();
    dog.printType();
    platypus.printType();
    beth.printType();
    Flo.printType();
    beth.printType();
    air.printType();
    rock.printType();
    return 0;
}
