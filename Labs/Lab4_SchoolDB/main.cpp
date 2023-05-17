#include <iostream>
#include <string>

using namespace std;

#define MAX_STUDENTS_NUM    100
#define MAX_TEACHERS_NUM    20
class school
{
private:
    int student_num = 0;
    int teacher_num = 0;
    string school_name;
public:
    void set_SchoolName(string Copy_SchoolName)
    {
        school_name = Copy_SchoolName;
    }
    void set_students(int Copy_Students)
    {
        if(0<Copy_Students<=MAX_STUDENTS_NUM)
            student_num = Copy_Students;
    }
    void set_teachers(int Copy_Teachers)
    {
        if(0<Copy_Teachers<= MAX_TEACHERS_NUM)
            teacher_num = Copy_Teachers;
    }

        string get_SchoolName(void)
    {
            return school_name ;
    }
    int get_students(void)
    {
            return student_num ;
    }
    int get_teachers(void)
    {
             return teacher_num ;
    }
    void Print_School(void)
    {
            cout << "==========School Details===========" << endl;
            cout << "School Name = " << get_SchoolName()<< endl;
            cout << "Students Numbers = " << get_students()<< endl;
            cout << "Teachers Numbers = " << get_teachers()<< endl;
            cout << "===================================" << endl;

    }
};
int main()
{
    class school town_school;
    int input_students, input_teachers;
    string input_SchoolName;

    cout << "Enter school name " << endl;
    getline(cin,input_SchoolName);
    town_school.set_SchoolName(input_SchoolName);


    cout << "Enter Students Number " << endl;
    cin>>input_students;
    town_school.set_students(input_students);

    cout << "Enter teachers Number " << endl;
    cin>>input_teachers;
    town_school.set_teachers(input_teachers);

    town_school.Print_School();
    return 0;
}
