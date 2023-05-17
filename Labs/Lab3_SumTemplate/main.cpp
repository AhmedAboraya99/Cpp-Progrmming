#include <iostream>
#include <string>

using namespace std;

template <typename T1 , typename T2>

    T1 sum(T1 n1, T2 n2)
    {
        return n1 + n2;
    }
int main()
{
    cout << sum(3,4) << endl;
    cout << sum('a',5) << endl;
    cout << sum<string, string>("a","b") << endl;
    cout << sum(6.7,8) << endl;
    return 0;
}
