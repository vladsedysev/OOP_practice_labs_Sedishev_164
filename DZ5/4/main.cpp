#include <iostream>

using namespace std;

class CVector2D
{
public:
    
    CVector2D(double x0 = 0, double y0 = 0)
        : x(x0), y(y0)
    {
    }

   
    CVector2D const operator +(CVector2D const& vector2) const
    {
        return CVector2D(x + vector2.x, y + vector2.y);
    }

    
    CVector2D const operator -(CVector2D const& vector2) const
    {
        return CVector2D(x - vector2.x, y - vector2.y);
    }

    
    double const operator *(CVector2D const& vector2) const
    {
        return x * vector2.x + y * vector2.y;
    }

    
    CVector2D const operator *(double scalar) const
    {
        return CVector2D(x * scalar, y * scalar);
    }

    
    double& operator [](int index)
    {
        if (index == 0) return x;
        return y;
    }

    const double& operator [](int index) const
    {
        if (index == 0) return x;
        return y;
    }

    
    double x, y;
};


CVector2D const operator *(double scalar, CVector2D const& vector)
{
    return CVector2D(scalar * vector.x, scalar * vector.y);
}

int main()
{
    CVector2D v1(3, 4);
    CVector2D v2(1, 2);

    CVector2D sum = v1 + v2;     
    double dot = v1 * v2;       
    CVector2D scaled = v1 * 2.5;  

    cout << sum.x << " " << sum.y << endl;
    cout << dot << endl;
    cout << scaled.x << " " << scaled.y << endl;
    cout << v1[0] << endl;

    return 0;
}
