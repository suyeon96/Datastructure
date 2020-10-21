/*
 * 5.4
 * 배열과 포인터
 */
#include <iostream>
using namespace std;

int main()
{
    int arr[5] = {1, 2, 3, 4, 5};

    cout << "arr : " << arr << ",  ";
    cout << "arr[0] : " << arr[0] << ",  ";
    cout << "*arr : " << *arr << endl;

    cout << "arr+1 : " << arr+1 << ",  ";
    cout << "arr[1] : " << arr[1] << ",  ";
    cout << "*(arr+1) : " << *(arr+1) << endl;

    cout << "arr+2 : " << arr+2 << ",  ";
    cout << "arr[2] : " << arr[2] << ",  ";
    cout << "*(arr+2) : " << *(arr+2) << endl;

    cout << "arr+3 : " << arr+3 << ",  ";
    cout << "arr[3] : " << arr[3] << ",  ";
    cout << "*(arr+3) : " << *(arr+3) << endl;

    cout << "arr+4 : " << arr+4 << ",  ";
    cout << "arr[4] : " << arr[4] << ",  ";
    cout << "*(arr+4) : " << *(arr+4) << endl;

    return 0;
}