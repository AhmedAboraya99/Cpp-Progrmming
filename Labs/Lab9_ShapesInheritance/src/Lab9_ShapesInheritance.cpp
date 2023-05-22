#include <iostream>

using namespace std;

class Shape {
public:
    Shape() {}
    virtual ~Shape() {}
    virtual void area() = 0;
    virtual void circumference() = 0;
    virtual void printDimensions() = 0;
};

class Circle : public Shape {
public:
    Circle(int r) : radius(r) {}
    virtual ~Circle() {}
    void area() {
        cout << "Circle Area = " << 3.14*radius*radius << endl;
    }
    void circumference() {
        cout << "Circle Circumference = " << 2*3.14*radius << endl;
    }
    void printDimensions() {
        cout << "Circle Radius = " << radius << endl;
    }
protected:
    int radius;
};

class Square : public Shape {
public:
    Square(int l) : length(l) {}
    virtual ~Square() {}
    void area() {
        cout << "Square Area = " << length*length << endl;
    }
    void circumference() {
        cout << "Square Circumference = " << 4*length << endl;
    }
    void printDimensions() {
        cout << "Square Length = " << length << endl;
    }
protected:
    int length;
};

class Rectangle : public Shape {
public:
    Rectangle(int h,int w) : height(h), width(w) {}
    virtual ~Rectangle() {}
    void area() {
        cout << "Rectangle Area = " << height*width << endl;
    }
    void circumference() {
        cout << "Rectangle Circumference = " << 2*(width+height) << endl;
    }
    void printDimensions() {
        cout << "Rectangle Height = " << height << ", Width = " << width << endl;
    }
protected:
    int height, width;
};

int main() {
    char choice;
    Shape* shape;

    do {
        cout << "Select a shape (C for Circle, S for Square, R for Rectangle, or Q to quit): ";
        cin >> choice;

        switch (toupper(choice)) {
        case 'C':
            int r;
            cout << "Enter Circle Radius: ";
            cin >> r;
            shape = new Circle(r);
            break;
        case 'S':
            int l;
            cout << "Enter Square Length: ";
            cin >> l;
            shape = new Square(l);
            break;
        case 'R':
            int h, w;
            cout << "Enter Rectangle Height: ";
            cin >> h;
            cout << "Enter Rectangle Width: ";
            cin >> w;
            shape = new Rectangle(h, w);
            break;
        case 'Q':
            return 0;
        default:
            cout << "Invalid choice. Please try again." << endl;
            continue;
        }

        shape->area();
        shape->circumference();
        shape->printDimensions();

        delete shape;
    } while (true);

    return 0;
}