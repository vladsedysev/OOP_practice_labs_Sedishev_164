#include <iostream>
using namespace std;

class Shape {
protected:
    string name;
    string color;

public:
    Shape(const string& n, const string& c)
        : name(n), color(c) {}

    virtual double area() const = 0;
    virtual void draw() const = 0;

    bool operator==(const Shape& other) const {
        return (name == other.name) && (color == other.color);
    }

    friend ostream& operator<<(ostream& outs, const Shape& sh) {
        outs << "Figure: " << sh.name
             << ", Color: " << sh.color
             << ", Area: " << sh.area();
        return outs;
    }
};

class Circle : public Shape {
protected:
    float radius;

public:
    Circle(float r = 0, const string& col = "white")
        : Shape("Circle", col), radius(r) {}

    void draw() const override {
        cout << "Drawing circle with radius = " << radius << endl;
    }

    double area() const override {
        return 3.14 * radius * radius;
    }


    Circle operator+(const Circle& other) const {
        return Circle(radius + other.radius, color);
    }
};


class Kvadrat : public Shape {
private:
    float width;
    float height;

public:
    Kvadrat(float w = 0, float h = 0, const string& col = "white")
        : Shape("Rectangle", col), width(w), height(h) {}

    void draw() const override {
        cout << "Drawing rectangle: width = " << width
             << ", height = " << height << endl;
    }

    double area() const override {
        return width * height;
    }
};


void printInfo(const Shape& sh) {
    cout << "Basic info: " << sh << endl;
}

void printInfo(const Shape& sh, bool withDraw) {
    cout << "Detailed info: " << sh << endl;
    sh.draw();
}

int main() {
    cout << "Hello World!" << endl;


    Circle c1(5, "Red");
    Circle c2(3, "Red");
    Kvadrat k1(4, 6, "Blue");


    Shape* arr[3];
    arr[0] = &c1;
    arr[1] = &c2;
    arr[2] = &k1;


    for (int i = 0; i < 4; i++) {
        arr[i]->draw();
        cout << "Area = " << arr[i]->area() << endl;
    }


    printInfo(c1);


    printInfo(k1, true);


    Circle sum = c1 + c2;
    printInfo(sum, true);

    return 0;
}
