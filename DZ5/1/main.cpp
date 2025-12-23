#include <iostream>
using namespace std;

class Number
{
public:
    int value;

    Number(int v = 0) : value(v) {}

    
    Number const operator+(Number const& other) const
    {
        return Number(value + other.value);
    }

    Number const operator-(Number const& other) const
    {
        return Number(value - other.value);
    }
    Number const operator*(Number const& other) const
    {
        return Number(value * other.value);
    }


    
    friend ostream& operator<<(ostream& os, const Number& n)
    {
        os << n.value;
        return os;
    }
};
int main() {
    Number a(5), b(3);
    Number c = a + b;
    Number s = a - b;
    Number x = a * b;
    cout << c << endl << s << endl << x;
    return 0;
}
