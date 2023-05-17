#include <iostream>

using namespace std;

namespace Shape
{
        namespace Circle
        {
            int radius;
            void Area()
            {
                cout << "Circle Area = " << 3.14*radius*radius<< endl;
            }
            void Circum()
            {
                cout << "Circle Circumference = " << 2*3.14*radius<< endl;
            }
        }
        namespace Square
        {
            int length;
            void Area()
            {
                cout << "Square Area = " << length*length<< endl;
            }
            void Circum()
            {
                cout << "Square Circumference = " << 4*length<< endl;
            }
        }
        namespace Rectangle
        {
             int height, width;
            void Area()
            {
                cout << "Rectangle Area = " << height*width<< endl;
            }
            void Circum()
            {
                cout << "Rectangle Circumference = " << 2*(width+height)<< endl;
            }
        }
}
int main()
{
    cout<<"Enter Circle Radius = ";
    cin>>Shape::Circle::radius;

    Shape::Circle::Area();
    Shape::Circle::Circum();

    cout<<"Enter Square length = ";
    cin>>Shape::Square::length;

    Shape::Square::Area();
    Shape::Square::Circum();

    cout<<"Enter Rectangle Height and width :";
    cin>>Shape::Rectangle::height>>Shape::Rectangle::width;
    Shape::Rectangle::Area();
    Shape::Rectangle::Circum();
    return 0;
}
