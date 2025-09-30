#include <iostream>

using namespace std;

int main()
{
    int a, b;
    cout << "Vvedite 2 4isla: ";
    cin >> a >> b;
    cout << "a=" << a<< " b=" <<b<< endl;
    int *pa=&a;
    int *pb=&b;
    *pa = *pa + *pb;
    *pb = *pa - *pb;
    *pa = *pa - *pb;
    cout << "posle zameni a=" << a<< " b=" <<b<< endl;
    return 0;
}
