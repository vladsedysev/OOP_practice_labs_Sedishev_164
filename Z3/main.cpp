#include <iostream>

using namespace std;

int main()
{
    const int razmer = 11;
    int arr[razmer];
    int sum = 0;
    for(int i = 0; i < razmer; i++) {
        cout << "vvedite element " << i + 1 << ": ";
        cin >> arr[i];
    }


    for(int i = 0; i < razmer; i++) {
        if(arr[i] > 0) {
            sum += arr[i];
        }
    }


    cout << "summa=" << sum << endl;

    return 0;
}
