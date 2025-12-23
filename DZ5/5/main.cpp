#include <iostream>
#include <initializer_list>

struct Vector2D {
    double x, y;

    Vector2D(double x_ = 0, double y_ = 0) : x(x_), y(y_) {}
};

class Matrix2x2 {
private:
    double data[2][2];

public:
 
    Matrix2x2() {
        data[0][0] = data[0][1] = data[1][0] = data[1][1] = 0.0;
    }

    
    Matrix2x2(std::initializer_list<std::initializer_list<double>> init) {
        int i = 0;
        for (auto& row : init) {
            int j = 0;
            for (auto& val : row) {
                data[i][j++] = val;
            }
            i++;
        }
    }

    
    Matrix2x2 operator+(const Matrix2x2& other) const {
        Matrix2x2 result;
        for (int i = 0; i < 2; ++i)
            for (int j = 0; j < 2; ++j)
                result.data[i][j] = data[i][j] + other.data[i][j];
        return result;
    }

    
    Matrix2x2 operator*(const Matrix2x2& other) const {
        Matrix2x2 result;
        for (int i = 0; i < 2; ++i)
            for (int j = 0; j < 2; ++j) {
                result.data[i][j] = 0;
                for (int k = 0; k < 2; ++k)
                    result.data[i][j] += data[i][k] * other.data[k][j];
            }
        return result;
    }

    Vector2D operator*(const Vector2D& v) const {
        return Vector2D(
            data[0][0] * v.x + data[0][1] * v.y,
            data[1][0] * v.x + data[1][1] * v.y
            );
    }

    
    double operator()(int row, int col) const {
        return data[row][col];
    }
};

int main() {
    Matrix2x2 m1({{1, 2}, {3, 4}});
    Matrix2x2 m2({{5, 6}, {7, 8}});

    Matrix2x2 product = m1 * m2;   

    Vector2D v1(1, 2);
    Vector2D result = m1 * v1;    

    double element = m1(0, 1);     

    std::cout << "m1(0,1) = " << element << std::endl;
    std::cout << "m1 * v1 = (" << result.x << ", " << result.y << ")\n";

    return 0;
}
