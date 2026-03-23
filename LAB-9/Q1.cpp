#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int m, n;
    cout << "Enter value of m and n: ";
    cin >> m >> n;
    int a1[m], a2[n];
    cout << "Enter elements of first array: ";
    for (int i = 0; i < m; i++)
    {
        cin >> a1[i];
    }
    cout << "Enter elements of second array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> a2[i];
    }
    bool found[n] = {};

    for (int j = 0; j < n; j++)
    {
        for (int i = 0; i < m; i++)
        {
            if (a2[j] == a1[i])
            {
                found[j] = true;
                break;
            }
        }
    }

    bool flag = true;
    for (int i = 0; i < n; i++)
    {
        if (!found[i])
        {
            flag = false;
            break;
        }
    }
    if (flag)
    {
        cout << "Second array is subset of first array." << endl;
    }
    else
    {
        cout << "Second array is not subset of first array." << endl;
    }
    return 0;
}
