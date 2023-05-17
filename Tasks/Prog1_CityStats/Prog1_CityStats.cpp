//============================================================================
// Name        : Prog1_CityStats.cpp
// Author      : Ahmed Aboraya
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <vector>

using namespace std;


    struct CityStats{
        int population;
        int family;
        int employee;
        int student;
    };



namespace governorate
{

    namespace city1
    {
        CityStats stats;
        void edit(void)
        {
           cout << "===============City 1================" << endl ;
            cout << "Enter Number of population   : " ;
            cin >> stats.population ;
            cout << "Enter Number of Families  : " ;
            cin >> stats.family ;
            cout << "Enter Number of Employees : " ;
            cin >> stats.employee ;
            cout << "Enter Number of Students  : " ;
            cin >> stats.student ;
        }
        void print(void)
        {
            cout << "===============City 1================" << endl ;
            cout << "Number of population   : " << stats.population << endl ;
            cout << "Number of Families  : " << stats.family << endl ;
            cout << "Number of Employees : " <<  stats.employee << endl ;
            cout << "Number of Students  : " << stats.student<< endl ;
        }
        void reset(void)
        {

            stats.population = 0 ;
            stats.family = 0;
            stats.employee = 0;
            stats.student = 0;
        }
    }
    namespace city2
    {
       CityStats stats;
        void edit(void )
        {
           cout << "===============City 2================" << endl ;
            cout << "Enter Number of population   : " ;
            cin >> stats.population;
            cout << "Enter Number of Families  : " ;
            cin >> stats.family ;
            cout << "Enter Number of Employees : " ;
            cin >> stats.employee ;
            cout << "Enter Number of Students  : " ;
            cin >> stats.student ;
        }
        void print(void)
        {
            cout << "===============City 2================" << endl ;
            cout << "Number of population   : " << stats.population << endl ;
            cout << "Number of Families  : " << stats.family  << endl ;
            cout << "Number of Employees : " << stats.employee  << endl ;
            cout << "Number of Students  : " << stats.student << endl ;
        }
        void reset(void)
        {

            stats.population = 0 ;
            stats.family  = 0;
            stats.employee  = 0;
            stats.student = 0;
        }
    }
    namespace city3
    {
      CityStats stats;
        void edit(void )
        {
           cout << "===============City 3================" << endl ;
            cout << "Enter Number of population   : " ;
            cin >> stats.population ;
            cout << "Enter Number of Families  : " ;
            cin >> stats.family  ;
            cout << "Enter Number of Employees : " ;
            cin >> stats.employee  ;
            cout << "Enter Number of Students  : " ;
            cin >> stats.student ;
        }
        void print(void)
        {
            cout << "===============City 3================" << endl ;
            cout << "Number of population   : " << stats.population << endl ;
            cout << "Number of families  : " << stats.family  << endl ;
            cout << "Number of employees : " << stats.employee  << endl ;
            cout << "Number of students  : " << stats.student << endl ;
        }
        void reset(void)
        {

            stats.population = 0 ;
            stats.family  = 0;
            stats.employee  = 0;
            stats.student = 0;
        }
    }
}

template <typename T1>
T1* Merge_TwoCities(T1* Copy_city1, T1*  Copy_city2)
{
        T1* Cities_Sum = new T1;

    Cities_Sum->population = Copy_city1->population + Copy_city2->population;
    Cities_Sum->family = Copy_city1->family + Copy_city2->family;
    Cities_Sum->employee = Copy_city1->employee + Copy_city2->employee;
    Cities_Sum->student = Copy_city1->student + Copy_city2->student;

        cout << "===============[Two Cities Statistics]===================" << endl ;
        cout << "Total number of population : "  << Cities_Sum->population << endl ;
        cout << "Total number of families   : "  << Cities_Sum->family << endl ;
        cout << "Total number of employees  : "  << Cities_Sum->employee << endl ;
        cout << "Total number of students   : "  << Cities_Sum->student << endl ;

    return Cities_Sum;
}
template <typename T2>
T2* Merge_ThreeCities(T2* Copy_city1, T2* Copy_city2, T2* Copy_city3)
{
        T2* Cities_Sum = new T2;


    Cities_Sum->population = Copy_city1->population + Copy_city2->population+ Copy_city3->population;
    Cities_Sum->family = Copy_city1->family + Copy_city2->family+ Copy_city3->family;
    Cities_Sum->employee = Copy_city1->employee + Copy_city2->employee + Copy_city3->employee;
    Cities_Sum->student = Copy_city1->student + Copy_city2->student + Copy_city3->student;

        cout << "===============[Three Cities Statistics]===================" << endl ;
        cout << "Total number of population : "  << Cities_Sum->population << endl ;
        cout << "Total number of families   : "  << Cities_Sum->family << endl ;
        cout << "Total number of employees  : "  << Cities_Sum->employee << endl ;
        cout << "Total number of students   : "  << Cities_Sum->student << endl ;

    return Cities_Sum;
}

int main()
{
    int option, choice, City1_Input, City2_Input;
    while(1)
    {
        cout << "=====================================================================================" << endl ;
        cout << " ///////////////// Select One of the Following Options ///////////////////////////// "<<endl ;
        cout << "=====================================================================================" << endl ;
        cout << "                  (1) Edit City Data               "       << endl ;
        cout << "                  (2) View City Data               "       << endl ;
        cout << "                  (3) Delete City Data             "       << endl ;
        cout << "                  (4) Edit All Cities Data         "       << endl ;
        cout << "                  (5) View All Cities Data         "       << endl ;
        cout << "                  (6) Delete All Cities Data       "       << endl ;
        cout << "                  (7) View Two Cities Merged Statistics         "       << endl ;
        cout << "                  (8) View All Merged Cities Statistics      "       << endl ;
        cout << "                  [0] Exit Program                       "       << endl ;
        cout << "=====================================================================================" << endl ;
        cin >> option;

        system("cls");
        switch (option)
        {
        case 0:
        	exit(0);
            break;
        case 1:

            cout << "Select a City to edit" << endl;
            cout << "===============" << endl ;
            cout << "[1] City 1 "     << endl ;
            cout << "[2] City 2 "     << endl ;
            cout << "[3] City 3 "     << endl ;
            cout << "[0] Back   "     << endl ;
            cout << "===============" << endl ;
            cin>>choice;
            system("cls");
            switch (choice)
            {

                case 1: governorate::city1::edit();  break;
                case 2: governorate::city2::edit();  break;
                case 3: governorate::city3::edit();  break;
                case 0: break;
                default: cout << "Invalid Choice" << endl;   break;
            }
            break;
            case 2:
            cout << "Select a city to view" << endl;
            cout << "===============" << endl ;
            cout << "[1] City 1 "     << endl ;
            cout << "[2] City 2 "     << endl ;
            cout << "[3] City 3 "     << endl ;
            cout << "[0] Back   "     << endl ;
            cout << "===============" << endl ;
            cin  >> choice;
            system("cls");
            switch (choice)
            {
            case 1: governorate::city1::print(); break;
            case 2: governorate::city2::print(); break;
            case 3: governorate::city3::print(); break;
            case 0: break;
            default:  cout << "Invalid Choice" << endl; break;
            }
            break;
            case 3:
            cout << "Select a city to delete" << endl;
            cout << "===============" << endl ;
            cout << "[1] City 1 "     << endl ;
            cout << "[2] City 2 "     << endl ;
            cout << "[3] City 3 "     << endl ;
            cout << "[0] Back   "     << endl ;
            cout << "===============" << endl ;
            cin  >> choice;
            system("cls");
            switch (choice)
            {
                case 1: governorate::city1::reset(); break;
                case 2: governorate::city2::reset(); break;
                case 3: governorate::city3::reset(); break;
                case 0: break;
                default:  cout << "Invalid Choice" << endl; break;
            }
            break;
            case 4:
                system("cls");
                governorate::city1::edit();
                governorate::city2::edit();
                governorate::city3::edit();
                break;
            case 5:
                system("cls");
                governorate::city1::print();
                governorate::city2::print();
                governorate::city3::print();
                break;
            case 6:
            system("cls");
            governorate::city1::reset();
            governorate::city2::reset();
            governorate::city3::reset();
            break;
            case 7:
            system("cls");
            CityStats* merged_stats;
                cout << "======================" << endl ;
                cout << "[1] City 1 "            << endl ;
                cout << "[2] City 2 "            << endl ;
                cout << "[3] City 3 "            << endl ;
                cout << "[0] Back "              << endl ;
                cout << "======================" << endl ;
                cout << "Select First City :  " ;
                cin  >> City1_Input ;
                cout << "Select Second City :  " ;
                cin  >> City2_Input ;
            if((City1_Input == 1 && City2_Input == 2 )||(City1_Input == 2 && City2_Input ==1))
                    merged_stats = Merge_TwoCities<CityStats>(&governorate::city1::stats,&governorate::city2::stats);
                else if((City1_Input == 1 && City2_Input == 3) ||(City1_Input == 3 && City2_Input ==1))
                    merged_stats = Merge_TwoCities<CityStats>(&governorate::city1::stats,&governorate::city3::stats);
                else if((City1_Input == 2 && City2_Input == 3) ||(City1_Input == 3 && City2_Input ==2))
                    merged_stats = Merge_TwoCities<CityStats>(&governorate::city2::stats,&governorate::city3::stats);
                else
                    cout<<"Invalid City"<<endl;
            delete merged_stats;
                break;
            case 8:
            system("cls");

            merged_stats = Merge_ThreeCities<CityStats>(&governorate::city1::stats,&governorate::city2::stats,&governorate::city3::stats);
            delete merged_stats;
            break;
        default:
            break;
        }
    }
    return 0;


}
