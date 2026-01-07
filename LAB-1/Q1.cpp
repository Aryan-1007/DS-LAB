#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int m, n;
    cout << "Enter the No. of Rows and Columns of the array:";
    cin >> m >> n;
    int arr[m][n];
    cout << "Enter array elements according to row major order" << endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    cout << "The entered array is:" << endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
