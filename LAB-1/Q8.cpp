#include <bits/stdc++.h>
using namespace std;

int main()
{
    int m, n;
    cout << "Enter the No. of Rows and Columns of the matrix:";
    cin >> m >> n;
    int arr[m][n];

    cout << "Enter elements for a mxn matrix:\n";
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    int i, j;
    cout << "Enter indices i and j to find the address: ";
    cin >> i >> j;
    cout << (int)(arr + 1) << endl;
    // Row-major order formula
    int row_major_address = (int)(arr + (i * n + j));

    // Column-major order formula
    int col_major_address = (int)(arr + (j * m + i));

    cout << "Row-major address: According to formula:" << row_major_address << "  Actual Address: " << (int)&arr[i][j] << endl;
    cout << "Column-major address: According to formula:" << col_major_address << "  Actual Address: " << (int)&arr[j][i] << endl;

    return 0;
}
