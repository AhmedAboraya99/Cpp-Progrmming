//============================================================================
// Name        : P2_HospitalSystem.cpp
// Author      : Ahmed Aboraya
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <vector>

using namespace std;
/*********************************************************
 * MACROS
**********************************************************/
#define  GET_InputString(InputStr)  fflush(stdout); fflush(stdin);getline(cin, InputStr );
/********************************************************
 * FUNCTION PROTOTYPES
*********************************************************/
void Hospitals_Init();
void Hospitals_Display();

void Hospital_ShowInfo();
void Hospital_UpdateInfo();
void Hospital_ShowAllPatients();
void Hospital_DeleteAllPatients();
void Hospital_ShowAllDoctors();
void Hospital_DeleteAllDoctors();
void Hospital_ShowAllData();
void Hospital_DeleteAllData();

void Hospital_AddPatient();
void Hospital_UpdatePatient();
void Hospital_ViewPatient();
void Hospital_DeletePatient();

void Hospital_AddDoctor();
void Hospital_UpdateDoctor();
void Hospital_ViewDoctor();
void Hospital_DeleteDoctor();



/********************************************************
 * CLASS DEFINITION
*********************************************************/
class Patient {
private:
    int ID;
    string name;
    int age;
    string gender;
    string illness;
public:
    Patient(): ID(0),name (""), age (0), gender(""), illness (""){};
    Patient(int id ,string n, int a, string g, string i) {
       ID = id;
        name = n;
        age = a;
        gender = g;
        illness = i;
    }
    void setID(int i) { ID = i; }
    void setName(string n) { name = n; }
    void setAge(int a) { age = a; }
    void setGender(string g) { gender = g; }
    void setIllness(string i) { illness = i; }

    int getID() { return ID; }
    string getName() {return name;}
    int getAge() { return age;}
    string getGender() { return gender;}
    string getIllness() { return illness;}

    void print(){
        cout<< "ID : " << ID <<endl ;
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Gender: " << gender << endl;
        cout << "Illness: " << illness << endl;
    }
};

class Doctor {
private:
    int ID;
    string name;
    int age;
    string gender;
    string spatiality;
public:
    Doctor(): ID(0),name (""), age (0), gender(""), spatiality (""){};
    Doctor(int id,string n,int a,string g,string s) {
        ID = id;
        name = n;
        age = a;
        gender = g;
        spatiality = s;
    }
    void setID(int i) { ID = i; }
    void setName(string n) { name = n; }
    void setAge(int a) { age = a; }
    void setGender(string g) { gender = g; }
    void setSpatiality(string s) { spatiality = s; }

    int getID() { return ID; }
    string getName() {return name;}
    int getAge() {return age;}
    string getGender() {   return gender;}
    string getSpatiality() {   return spatiality;}

    void print(){
        cout<< "ID : " << ID <<endl ;
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Gender: " << gender << endl;
        cout << "spatiality: " << spatiality << endl;
    }
};

class Hospital {
private:
    string name;
    int RoomsCount;
    int PatientsCount;
    int DoctorsCount;

    vector<Patient> patients;
    vector<Doctor> doctors;
public:
    Hospital() : RoomsCount (0), PatientsCount (0), DoctorsCount (0) {}
    Hospital(string n, int r, int p, int d) {
        name = n;
        RoomsCount = r;
        PatientsCount = p;
        DoctorsCount = d;
    }
    void setName(string n) { name = n; }
    void setRoomsCount(int r) { RoomsCount = r; }
    void setPatientsCount(int p) { PatientsCount = p; }
    void setDoctorsCount(int d) { DoctorsCount = d; }

    string getName() { return name;}
    int getRoomsCount() { return RoomsCount;}
    int getPatientsCount() { return PatientsCount;}
    int getDoctorsCount() { return DoctorsCount;}

    void addPatient(Patient p) { 
        patients.push_back(p);
        Hospital::PatientsCount++;
    }
    void addDoctor(Doctor d) {
        doctors.push_back(d);
        Hospital::DoctorsCount++;
    }

    bool updatePatient(Patient p) {
        for (int i = 0; i < patients.size(); i++) {
            if (p.getID() == patients[i].getID()) {
                patients[i] = p;
                return true;
            }
        }
        return false;
    }
    bool getPatient(int id, Patient* p) {
        for (int i = 0; i < patients.size(); i++) {
            if (patients[i].getID() == id) {
                *p = patients[i];
                return true;
            }
        }
        cout<<"[Error]Patient not found"<<endl;
        return false;
    }
    bool getDoctor(int id, Doctor* d) {
        for (int i = 0; i < doctors.size(); i++) {
            if (doctors[i].getID() == id) {
                *d = doctors[i];
                return true;
            }
        }
        cout<<"[Error]Doctor not found"<<endl;
        return false;
    }
    bool updateDoctor(Doctor d) {
        for (int i = 0; i < doctors.size(); i++) {
            if (d.getID() == doctors[i].getID()) {
                doctors[i] = d;
                return true;
            }
        }
        cout<<"[Error]Doctor not found"<<endl;
        return false;
    }
    void deletePatient(int Id) {
        for (int i = 0; i < patients.size(); i++) {
            if (patients[i].getID() == Id) {
                patients.erase(patients.begin() + i);
                Hospital::PatientsCount--;
                break;
            }
        }
        cout<<"[Error]Patient not found"<<endl;
    }
    void deleteDoctor(int Id) {
        for (int i = 0; i < doctors.size(); i++) {
            if (doctors[i].getID() == Id) {
                doctors.erase(doctors.begin() + i);
                Hospital::DoctorsCount--;
                break;
            }
        }
        cout<<"[Error]Doctor not found"<<endl;
    }

    void printPatients() {
        cout << "Patients in " << name << " hospital:" << endl;
        cout << "-------------------------------------------------------------------------------------------" << endl ;
        cout << "ID"<< " | "<< "Name" << " | " <<"Age"<< " | " << "Gender" << " | " << "Illness"            << endl ;
        cout << "-------------------------------------------------------------------------------------------" << endl ;
   
        for (int i = 0; i < patients.size(); i++) {

            cout << patients[i].getID()<<patients[i].getName() << " , " << patients[i].getAge() << " , " << patients[i].getGender() << " , " << patients[i].getIllness() << endl;
        }
    }
    void printDoctors() {
        cout << "Doctors in " << name << " hospital:" << endl;
        cout << "-------------------------------------------------------------------------------------------" << endl ;
        cout << "ID"<< " | "<< "Name" << " | " <<"Age"<< " | " << "Gender" << " | " << "spatiality"           << endl ;
        cout << "-------------------------------------------------------------------------------------------" << endl ;
        for (int i = 0; i < doctors.size(); i++) {
            cout << doctors[i].getID()<< " , " <<doctors[i].getName() << " , " <<doctors[i].getAge() << " , " << doctors[i].getSpatiality() << endl;
        }
    }
    void print() {
        cout  << "Hospital : "<<name <<endl;
        cout << "Rooms Count: " <<RoomsCount << endl;
        cout << "Patients Count: " <<PatientsCount << endl;
        cout << "Doctors Count: " <<DoctorsCount << endl;
        }
    void printHospitalData() {
                print();
                for (int i = 0; i < patients.size(); i++) {
                    cout << patients[i].getID()<<patients[i].getName() << ", " << patients[i].getAge() << ", " << patients[i].getGender() << ", " << patients[i].getIllness() << endl;
                }

                for (int i = 0; i < doctors.size(); i++) {
                    cout << doctors[i].getID()<< ", " <<doctors[i].getName() << ", " <<doctors[i].getAge() << ", " << doctors[i].getSpatiality() << endl;
                }

    }
};

/********************************************************
 * GLOBAL DATA
*********************************************************/
static vector <Hospital*> Hospitals;

/********************************************************
 * MAIN FUNCTION
*********************************************************/
int main() {

    int section,option, choice;

    Hospitals_Init();

    while(1)
    {
         cout << "=====================================================================================" << endl ;
        cout << " ///////////////////////// Select Section ///////////////////////////// "<<endl ;
        cout << "=====================================================================================" << endl ;
        cout << "                  (1) Patient                     "       << endl ;
        cout << "                  (2) Doctor                "       << endl ;
        cout << "                  (3) Hospital               "       << endl ;
        cout << "                  (0) Exit                    "       << endl ;
        cout << "=====================================================================================" << endl ;
        cout << "Enter your choice: ";
        cin >> section;
        system("cls");
        switch(section){
            case 0:
                exit(0);
            case 1:
                cout << "=====================================================================================" << endl ;
                cout << " ///////////////// Select One of the Following Options ///////////////////////////// " <<endl ;
                cout << "=====================================================================================" << endl ;
                cout << "                  (1) Add Patient                     "       << endl ;
                cout << "                  (2) Update Patient Data               "       << endl ;
                cout << "                  (3) View Patient Data               "       << endl ;
                cout << "                  (4) Delete Patient Data             "       << endl ;
                cout << "                  (0) Back                         "       << endl
                << "=====================================================================================" << endl ;
                cout << "Enter your choice: ";
                cin >> option;
                system("cls");
                switch(option){
                case 0: break;
                case 1: Hospital_AddPatient(); break;
                case 2: Hospital_UpdatePatient(); break;
                case 3: Hospital_ViewPatient(); break;
                case 4: Hospital_DeletePatient(); break;
                default: cout<<"wrong option"<<endl; break;

                }

                break;
            case 2:
                cout << "=====================================================================================" << endl ;
                cout << " ///////////////// Select One of the Following Options ///////////////////////////// " <<endl ;
                cout << "=====================================================================================" << endl ;
                cout << "                  (1) Add Doctor                     "       << endl ;
                cout << "                  (2) Update Doctor Data               "       << endl ;
                cout << "                  (3) View Doctor Data               "       << endl ;
                cout << "                  (4) Delete Doctor Data             "       << endl ;
                cout << "                  (0) Back                         "       << endl
                << "=====================================================================================" << endl ;
                cout << "Enter your choice: ";
                cin >> option;
                system("cls");
                switch(option){
                    case 0:
                        break;
                    case 1: Hospital_AddDoctor(); break;
                    case 2: Hospital_UpdateDoctor(); break;
                    case 3: Hospital_ViewDoctor(); break;
                    case 4: Hospital_DeleteDoctor(); break;
                    default: cout<<"wrong option"<<endl; break;
                }
                break;
            case 3:
                cout << "=====================================================================================" << endl ;
                cout << " ///////////////// Select One of the Following Options ///////////////////////////// " <<endl ;
                cout << "=====================================================================================" << endl ;
                cout << "                  (1) View Hospital Info              "       << endl ;
                cout << "                  (2) Update Hospital Info         "       << endl ;
                cout << "                  (3) View All Patients Data          "       << endl ;
                cout << "                  (4) Delete All Patients Data       "       << endl ;
                cout << "                  (5) View All Doctors Data          "       << endl ;
                cout << "                  (6) Delete All Doctors Data        "       << endl ;
                cout << "                  (7) View Hospital Data         "       << endl ;
                cout << "                  (8) Delete Hospital Data       "       << endl ;
                cout << "                  [0] Back                    "       << endl ;
                cout << "=====================================================================================" << endl ;
                cin >> option;
                system("cls");
                switch (option)
                {
                case 0: break;
                case 1: Hospital_ShowInfo(); break;
                case 2: Hospital_UpdateInfo(); break;
                case 3: Hospital_ShowAllPatients(); break;
                case 4: Hospital_DeleteAllPatients(); break;
                case 5: Hospital_ShowAllDoctors(); break;
                case 6: Hospital_DeleteAllDoctors(); break;
                case 7: Hospital_ShowAllData(); break;
                case 8: Hospital_DeleteAllData(); break;
                default: cout << "Invalid option "; break;
                }
                break;
            default:
                cout << "Invalid choice" << endl;
                break;
        }


    }

    return 0;
}

/****************************************************************
 * FUNCTIONS DEFINITION
*****************************************************************/
void Hospitals_Init()
{
    Patient p1(10, "Amr Gamal", 32, "Male", "Flu");
    Patient p2(101,"Nancy Agram", 42, "Female", "Broken leg");
    Patient p3(51,"Shikabala", 37, "Male", "Pneumonia");

    Doctor d1(92, "Dr. Wael Gomaa", 43,"Male","Cardiology");
    Doctor d2(73, "Dr. Aboulmaaty Zaki", 50, "Male","ophthalmology");
    Doctor d3(19, "Dr. Ahmed Amin", 36, "Male","Pediatrics");

    Hospital* h1 = new Hospital("Al-Demerdash", 100, 70, 30);
    Hospital* h2 = new Hospital("Ibn Sina", 50, 40, 25);
    Hospitals.push_back(h1);
    Hospitals.push_back(h2);
    
    h1->addPatient(p1);
    h1->addPatient(p2);
    h1->addPatient(p3);
    h1->addDoctor(d1);
    h1->addDoctor(d2);


}

void Hospitals_Display(){
    int hostIndex = 0;
    cout<< endl;
    for ( hostIndex = 0;hostIndex<Hospitals.size();hostIndex++) {
        cout << hostIndex <<" - "<<Hospitals[hostIndex]->getName() << endl;
    }
}
void Hospital_ShowInfo(){
    int Local_HostNum = 0;
    Hospitals_Display();
    cin>> Local_HostNum;
    Hospitals[Local_HostNum]->print();
}
void Hospital_UpdateInfo(){
    int Local_HostNum = 0;
        string Local_Name ;
    int Local_RoomCount , Local_PatientsCount, Local_DoctorsCount;

    Hospitals_Display();
    cin>> Local_HostNum;

    cout << "Enter Rooms Count: " ;
    cin  >>  Local_RoomCount ;
    Hospitals[Local_HostNum]->setRoomsCount(Local_RoomCount) ;

    cout << "Enter Patients Count: " ;
    cin  >>  Local_PatientsCount ;
    Hospitals[Local_HostNum]->setPatientsCount(Local_PatientsCount) ;

    cout << "Enter Doctors Count: " ;
    cin  >>  Local_DoctorsCount ;
    Hospitals[Local_HostNum]->setDoctorsCount(Local_DoctorsCount) ;

    cout << "======================================================" << endl; 
    cout << "              Update operation success                 " << endl;
    cout << "==========================================================" << endl;

    Hospital_ShowInfo();
}
void Hospital_ShowAllDoctors(){
    int Local_HostNum = 0;
    Hospitals_Display();
    cin>> Local_HostNum;
    Hospitals[Local_HostNum]->printDoctors();
}
void Hospital_ShowAllPatients(){
    int Local_HostNum = 0;
    Hospitals_Display();
    cin>> Local_HostNum;
    Hospitals[Local_HostNum]->printPatients();
}
void Hospital_DeleteAllPatients(){
    int Local_HostNum = 0;
    Hospitals_Display();
    cin>> Local_HostNum;
    for(int i=0; i<Hospitals[Local_HostNum]->getPatientsCount();i++)
    {
        Hospitals[Local_HostNum]->deletePatient(i);
    }
    cout << "======================================================" << endl; 
    cout << "              Delete operation success                 " << endl;
    cout << "==========================================================" << endl;
    Hospital_ShowInfo();
}
void Hospital_DeleteAllDoctors(){
    int Local_HostNum = 0;
    Hospitals_Display();
    cin>> Local_HostNum;
    for(int i=0; i<Hospitals[Local_HostNum]->getDoctorsCount();i++)
    {
        Hospitals[Local_HostNum]->deleteDoctor(i);
    }
    cout << "======================================================" << endl; 
    cout << "              Deleting operation success                 " << endl;
    cout << "==========================================================" << endl;
    Hospital_ShowInfo();
}
void Hospital_ShowAllData(){
    int Local_HostNum = 0;
    Hospitals_Display();
    cin>> Local_HostNum;


    Hospital_ShowInfo();
    cout << "======================================================" << endl;
    Hospitals[Local_HostNum]->printPatients();
    cout << "======================================================" << endl;
    Hospitals[Local_HostNum]->printDoctors();
    cout << "======================================================" << endl;

}

void Hospital_DeleteAllData(){
    int Local_HostNum = 0;
    Hospitals_Display();
    cin>> Local_HostNum;

    for(int i=0; i<Hospitals[Local_HostNum]->getPatientsCount();i++)
    {
        Hospitals[Local_HostNum]->deletePatient(i);
    }
    for(int i=0; i<Hospitals[Local_HostNum]->getDoctorsCount();i++)
    {
        
        Hospitals[Local_HostNum]->deleteDoctor(i);
    }
    cout << "======================================================" << endl; 
    cout << "              Deleting operation success                 " << endl;
    cout << "==========================================================" << endl;
    Hospital_ShowInfo();
}

void Hospital_AddPatient()
{
    Patient P1;
    string Local_Name, Local_Illness ;
    int Local_ID , Local_Age , Local_Gender, Local_HostNum;
    cout << "Enter Patient ID : " ;
    cin  >>  Local_ID ;
    P1.setID(Local_ID) ;
    cout << "Enter Patient Name: " <<endl;
   GET_InputString(Local_Name );
    P1.setName(Local_Name) ;


    cout << "Enter Patient Age  : " ;
    cin  >>  Local_Age ;
    P1.setAge(Local_Age);

    cout << " Enter Patient Gender  [(1) Male, (2)Female]: " ;
    cin  >>  Local_Gender ;
    if ( Local_Gender == 1 ){ P1.setGender("Male");}
    else if ( Local_Gender == 2 ){ P1.setGender("Female");}

    cout << "Enter Patient Illness: " <<endl;
    GET_InputString(Local_Illness );
    P1.setIllness(Local_Illness) ;

    cout << "Enter Patient Hospital: " ;
   
   Hospitals_Display();

    cin  >>  Local_HostNum ;

    
    
    Hospitals[Local_HostNum]->addPatient(P1);

}

void Hospital_AddDoctor(){
    Doctor D1;

    string Local_Name , Local_Spatiality;
    int Local_ID, Local_Age, Local_Gender, Local_HostNum;

    cout << "Enter Doctor ID : " ;
    cin  >>  Local_ID ;

    D1.setID(Local_ID) ;

    cout << "Enter Doctor Name : " <<endl;
   GET_InputString(Local_Name );
    D1.setName(Local_Name) ;

    cout << "Enter Doctor Age : " ;
    cin  >>  Local_Age ;
    D1.setAge(Local_Age);

    cout << "Enter Doctor Gender [(1) Male, (2)Female]: " ;
    cin  >>  Local_Gender ;
    if ( Local_Gender == 1 ){ D1.setGender("Male");}
    else if ( Local_Gender == 2 ){ D1.setGender("Female");}

    cout<<"Enter Doctor Spacality: ";
    GET_InputString(Local_Spatiality);
    D1.setSpatiality(Local_Spatiality);
    
    cout << "Enter Patient Hospital: " ;
    Hospitals_Display();
    cin  >>  Local_HostNum ;


    Hospitals[Local_HostNum]->addDoctor(D1);
    
}

void Hospital_UpdatePatient(void){
    Patient P1;

    string Local_Name, Local_Illness ;
    int Local_ID, Local_Age , Local_Gender, Local_HostNum;

    cout << "Enter Patient ID: " ;
    cin  >>  Local_ID ;
    P1.setID(Local_ID) ;
   GET_InputString(Local_Name );
    cout << "Enter Patient Name: "<<endl ;
    P1.setName(Local_Name) ;

    cout << "Enter Patient Age: " ;
    cin  >>  Local_Age ;
    P1.setAge(Local_Age);

    cout << " Enter Gender Of Patient [(1) Male, (2)Female]: " ;
    cin  >>  Local_Gender ;
    if ( Local_Gender == 1 ){ P1.setGender("Male");}
    else if ( Local_Gender == 2 ){ P1.setGender("Female");}

    cout << "Enter Patient Illness: " <<endl;
    GET_InputString(Local_Illness );
    P1.setIllness(Local_Illness) ;

    cout << "Enter Patient Hospital: " ;
   
    Hospitals_Display();
    cin  >>  Local_HostNum ;

    
    if( Local_HostNum < Hospitals.size()){ 
        if (Hospitals[Local_HostNum]->updatePatient(P1) == true)
        {
            cout << "======================================================" << endl; 
            cout << "              Updating operation success                 " << endl;
            cout << "==========================================================" << endl;

        }else {
            cout << "=========================================================" << endl; 
            cout << "              Updating operation failure                 " << endl;
            cout << "==========================================================" << endl;
        }
    }else
    {
        cout << "===============[Erorr] Hospital Not found ======================" << endl; 
        cout << "              Updating operation failure                 " << endl;
        cout << "==========================================================" << endl;
    }
}

void Hospital_UpdateDoctor(void)
{
    Doctor D1;

    string Local_Name, Local_Spatiality ;
    int  Local_ID, Local_Age, Local_Gender, Local_HostNum;

    cout << "Enter Doctor ID : " ;
    cin  >>  Local_ID ;
    D1.setID(Local_ID) ;

   GET_InputString(Local_Name );
    cout << "Enter Doctor Name: " ;
    D1.setName(Local_Name) ;

    cout << "Enter Doctor Age: "<<endl ;
    cin  >>  Local_Age ;
    D1.setAge(Local_Age);

    cout << " Enter Gender Of Doctor [(1) Male, (2)Female]: " ;
    cin  >>  Local_Gender ;
    if ( Local_Gender == 1 ){ D1.setGender("Male");}
    else if ( Local_Gender == 2 ){ D1.setGender("Female");}

    cout<<"Enter Doctor Spacality: ";
    GET_InputString(Local_Spatiality);
    D1.setSpatiality(Local_Spatiality);

    cout << "Enter Doctor Hospital: " ;
    Hospitals_Display();
    cin  >>  Local_HostNum ;
    if( Local_HostNum < Hospitals.size()){ 
    if (Hospitals[Local_HostNum]->updateDoctor(D1) == true)
    {
        cout << "==================== Doctor Updated ======================" << endl; 
        cout << "              Updating operation success                 " << endl;
        cout << "==========================================================" << endl;
    }
    else{
        cout << "=========================================================" << endl; 
        cout << "              Updating operation failure                 " << endl;
        cout << "==========================================================" << endl;

    }
    }else
    {
        cout << "================ Hospital Not found ======================" << endl; 
        cout << "              Updating operation failure                 " << endl;
        cout << "==========================================================" << endl;
    }


}
void Hospital_ViewPatient(void)
{
    int Local_ID, Local_HostNum;
    Patient L_Patient;
    cout << "Enter Patient Hospital: " ;
    Hospitals_Display();
    cin  >>  Local_HostNum ;
    cout<<"Enter Patient ID: ";
    cin>>Local_ID;
    Hospitals[Local_ID]->getPatient(Local_ID, &L_Patient);
    L_Patient.print();    
}

void Hospital_ViewDoctor(void)
{
    int Local_ID, Local_HostNum;
    Doctor L_Doctor;
    cout << "Enter Doctor Hospital: " ;
    Hospitals_Display();
    cin  >>  Local_HostNum ;
    cout<<"Enter Doctor ID: ";
    cin>>Local_ID;
    Hospitals[Local_ID]->getDoctor(Local_ID, &L_Doctor);
    L_Doctor.print();
}

void Hospital_DeletePatient(void)
{
    int Local_ID, Local_HostNum;
    Patient L_Patient;
    cout << "Enter Patient Hospital: " ;
    Hospitals_Display();
    cin  >>  Local_HostNum ;
    cout<<"Enter Patient ID: ";
    cin>>Local_ID;
    Hospitals[Local_ID]->deletePatient(Local_ID);
    L_Patient.print();
}

void Hospital_DeleteDoctor(void)
{
    int Local_ID, Local_HostNum;
    Doctor L_Doctor;
    cout << "Enter Doctor Hospital: " ;
    Hospitals_Display();
    cin  >>  Local_HostNum ;
    cout<<"Enter Doctor ID: ";
    cin>>Local_ID;
    Hospitals[Local_ID]->deleteDoctor(Local_ID);
    L_Doctor.print();
}
