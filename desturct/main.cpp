#include <iostream>
#include <vector>
using namespace std;

class Shape {
protected:
    int x;
    int y;
    int r;
public:
    Shape(int x, int y, int r): x(x), y(y), r(r) {
        cout << "Shape Constructor with "<<x<<","<<y<<"" << endl;
    }
    virtual ~Shape() { 
        cout << "Shape Destructor" << endl;
    }
    virtual void draw() = 0;
    void move(int newX, int newY) { x = newX; y = newY; }
};

class Rectangle : public Shape {
public:
    Rectangle(int x, int y, int r): Shape(x, y, r) {
        cout << "Rectangle Constructor" << endl;
    }
    ~Rectangle() {
        cout << "Rectangle Destructor" << endl;
    }
    void draw() override {
        cout << "Drawing Rectangle at " << x << "," << y << endl;
    }
};

int main() {
    Shape* s = new Rectangle(5, 10, 0);
    delete s; // наблюдаем, какие деструкторы вызваны
    return 0;
}
