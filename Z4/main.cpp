#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Vvedite Size of Massive : ";
    cin >> n;

    int *arr = new int[n];

    cout << "Vvedite elements of Massive\n";
    for (int i = 0; i < n; i++) {
        cin >> *(arr + i);
    }

    int *maxPtr = arr;
    for (int i = 1; i < n; i++) {
        if (*(arr + i) > *maxPtr) {
            maxPtr = arr + i;
        }
    }

    cout << "Max of Elements " << *maxPtr << endl;

    delete[] arr;
    return 0;
}
