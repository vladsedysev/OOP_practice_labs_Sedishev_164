#include <iostream>

using namespace std;

class Complex {
public:
    double real;
    double imaginary;

    
    Complex(double r = 0.0, double i = 0.0) : real(r), imaginary(i) {}

    
    Complex const operator+(Complex const&  other) const {
        return Complex(real + other.real, imaginary + other.imaginary);
    }


    
    Complex const operator-(Complex const&  other) const {
        return Complex(real - other.real, imaginary - other.imaginary);
    }

    
    Complex const operator*(Complex const&  other) const {
        return Complex(
            real * other.real - imaginary * other.imaginary,
            real * other.imaginary + imaginary * other.real
            );
    }

    
    Complex operator~() const {
        return Complex(real, -imaginary);
    }

    
    friend ostream& operator<<(ostream& os, const Complex& c) {
        os << c.real;
        if (c.imaginary >= 0)
            os << " + " << c.imaginary << "i";
        else
            os << " - " << -c.imaginary << "i";
        return os;
    }

};

int main() {
    Complex c1(3, 4);   
    Complex c2(1, 2);  

    Complex product = c1 * c2;    
    Complex conjugate = ~c1;      
    Complex s = c1 + c2; 
    Complex c = c1 - c2;      

    cout << "c1 = " << c1 << endl;
    cout << "c2 = " << c2 << endl;
    cout << "c1 * c2 = " << product << endl;
    cout << "~c1 = " << conjugate << endl;
    cout << "s " << s << endl;
    cout << "c = " << c << endl;

    return 0;
}
