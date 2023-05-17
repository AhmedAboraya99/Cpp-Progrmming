#include <iostream>


int main()
{
    int n1, n2;
    char Operator;
    char continue_flag = 'n';
    do
    {
        //receive math operation inputs
        std::cout << "Please Enter Two Numbers:" << std::endl;
        std::cin >> n1>>n2;
        std::cout << "Please Enter operator" << std::endl;
        std::cin >>Operator;

        //execute the math operation
        if(Operator == '+')
            std::cout << "Add result = " <<n1+n2 <<std::endl;
        else if(Operator == '-')
            std::cout << "Sub result = " <<n1-n2 <<std::endl;
        else if(Operator == '*')
            std::cout << "Multiply result = " <<n1*n2 <<std::endl;
        else if(Operator == '/')
            std::cout << "Divide result = " <<n1/n2 <<std::endl;
        else
            std::cout << "Unknown Operation " <<std::endl;

        std::cout << "Do you want to continue? y/n " <<std::endl;
        std::cin >> continue_flag;
    }while(continue_flag == 'y');
    return 0;
}
