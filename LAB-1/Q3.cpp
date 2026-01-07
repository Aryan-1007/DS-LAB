#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[3][3];

    cout << "Enter 9 elements for the 3x3 matrix:\n";
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> arr[i][j];
        }
    }

    cout << "Matrix elements and their addresses:\n";
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << "Element: " << arr[i][j] << ", Address: " << &arr[i][j] << endl;
        }
    }

    return 0;
}
